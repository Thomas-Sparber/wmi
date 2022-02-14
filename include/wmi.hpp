/**
  *
  * WMI
  * @author Thomas Sparber (2016)
  *
 **/

#ifndef WMI_HPP
#define WMI_HPP

#include <string>
#include <type_traits>

#include <wmiexception.hpp>
#include <wmiresult.hpp>

namespace Wmi
{

	//SFINAE test
	template <typename WmiClass>
	class HasGetWmiPath
	{
	private:
		typedef char YesType[1];
		typedef char NoType[2];

		template <typename C> static YesType& test( decltype(&C::getWmiPath) ) ;
		template <typename C> static NoType& test(...);

	public:
		enum { value = sizeof(test<WmiClass>(0)) == sizeof(YesType) };
	};

	template<typename WmiClass>
	typename std::enable_if<HasGetWmiPath<WmiClass>::value, std::string>::type
	CallGetWmiPath(const WmiClass &c) {
	   return WmiClass::getWmiPath();
	}

	//default wmi path if wmi class does not implement getWmiPath
	std::string CallGetWmiPath(...)
	{
		return "cimv2";
	}

	void query(const std::string& q, const std::string& p, WmiResult &out);

	inline WmiResult query(const std::string& q, const std::string& p)
	{
		WmiResult result;
		query(q, p, result);
		return result;
	}

	template <class WmiClass>
	inline void retrieveWmi(WmiClass &out)
	{
		WmiResult result;
		const std::string q = std::string("Select * From ") + WmiClass::getWmiClassName();
		query(q, CallGetWmiPath(out), result);
		out.setProperties(result, 0);
	}

	template <class WmiClass>
	inline void retrieveWmi(WmiClass &out, std::string columns)
	{
		WmiResult result;
		const std::string q = std::string("Select ") + columns + std::string(" From ") + WmiClass::getWmiClassName();
		query(q, CallGetWmiPath(out), result);
		out.setProperties(result, 0);
	}

	template <class WmiClass>
	inline WmiClass retrieveWmi()
	{
		WmiClass temp;
		retrieveWmi(temp);
		return temp;
	}

	template <class WmiClass>
	inline WmiClass retrieveWmi(std::string columns)
	{
		WmiClass temp;
		retrieveWmi(temp, columns);
		return temp;
	}

	template <class WmiClass>
	inline void retrieveAllWmi(std::vector<WmiClass> &out)
	{
		WmiResult result;
		const std::string q = std::string("Select * From ") + WmiClass::getWmiClassName();
		query(q, CallGetWmiPath(out), result);

		out.clear();
		for(std::size_t index = 0; index < result.size(); ++index)
		{
			WmiClass temp;
			temp.setProperties(result, index);
			out.push_back(std::move(temp));
		}
	}

	template <class WmiClass>
	inline void retrieveAllWmi(std::vector<WmiClass> &out, std::string columns)
	{
		WmiResult result;
		const std::string q = std::string("Select ") + columns + std::string(" From ") + WmiClass::getWmiClassName();
		query(q, CallGetWmiPath(out), result);

		out.clear();
		for(std::size_t index = 0; index < result.size(); ++index)
		{
			WmiClass temp;
			temp.setProperties(result, index);
			out.push_back(std::move(temp));
		}
	}

	template <class WmiClass>
	inline std::vector<WmiClass> retrieveAllWmi()
	{
		std::vector<WmiClass> ret;
		retrieveAllWmi(ret);

		return ret;
	}

	template <class WmiClass>
	inline std::vector<WmiClass> retrieveAllWmi(std::string columns)
	{
		std::vector<WmiClass> ret;
		retrieveAllWmi(ret, columns);

		return ret;
	}

}; //end namespace Wmi

#endif //WMI_HPP