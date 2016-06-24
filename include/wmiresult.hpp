/**
  *
  * WMI
  * @author Thomas Sparber (2016)
  *
 **/

#ifndef WMIRESULT_HPP
#define WMIRESULT_HPP

#include <map>
#include <string>
#include <vector>

#define FE_00(WHAT, A, B, C, X) WHAT(A, B, C, X) 
#define FE_01(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_00(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_02(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_01(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_03(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_02(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_04(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_03(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_05(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_04(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_06(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_05(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_07(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_06(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_08(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_07(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_09(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_08(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_10(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_09(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_11(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_10(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_12(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_11(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_13(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_12(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_14(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_13(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_15(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_14(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_16(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_15(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_17(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_16(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_18(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_17(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_19(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_18(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_20(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_19(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_21(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_20(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_22(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_21(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_23(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_22(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_24(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_23(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_25(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_24(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_26(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_25(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_27(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_26(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_28(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_27(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_29(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_28(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_30(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_29(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_31(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_30(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_32(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_31(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_33(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_32(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_34(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_33(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_35(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_34(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_36(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_35(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_37(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_36(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_38(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_37(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_39(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_38(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_40(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_39(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_41(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_40(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_42(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_41(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_43(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_42(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_44(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_43(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_45(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_44(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_46(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_45(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_47(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_46(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_48(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_47(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_49(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_48(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_50(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_49(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_51(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_50(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_52(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_51(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_53(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_52(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_54(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_53(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_55(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_54(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_56(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_55(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_57(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_56(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_58(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_57(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_59(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_58(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_60(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_59(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_61(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_60(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_62(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_61(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_63(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_62(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_64(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_63(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_65(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_64(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_66(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_65(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_67(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_66(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_68(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_67(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_69(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_68(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_70(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_69(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_71(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_70(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_72(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_71(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_73(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_72(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_74(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_73(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_75(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_74(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_76(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_75(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_77(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_76(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_78(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_77(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_79(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_78(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_80(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_79(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_81(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_80(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_82(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_81(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_83(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_82(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_84(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_83(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_85(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_84(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_86(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_85(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_87(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_86(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_88(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_87(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_89(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_88(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_90(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_89(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_91(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_90(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_92(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_91(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_93(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_92(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_94(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_93(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_95(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_94(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_96(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_95(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_97(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_96(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_98(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_97(WHAT, A, B, C, __VA_ARGS__); } while(0)
#define FE_99(WHAT, A, B, C, X, ...) do { WHAT(A, B, C, X); FE_98(WHAT, A, B, C, __VA_ARGS__); } while(0)

#define GET_MACRO( \
	_00,_01,_02,_03,_04,_05,_06,_07,_08,_09, \
	_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
	_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
	_30,_31,_32,_33,_34,_35,_36,_37,_38,_39, \
	_40,_41,_42,_43,_44,_45,_46,_47,_48,_49, \
	_50,_51,_52,_53,_54,_55,_56,_57,_58,_59, \
	_60,_61,_62,_63,_64,_65,_66,_67,_68,_69, \
	_70,_71,_72,_73,_74,_75,_76,_77,_78,_79, \
	_80,_81,_82,_83,_84,_85,_86,_87,_88,_89, \
	_90,_91,_92,_93,_94,_95,_96,_97,_98,_99, \
	NAME,...) NAME

#define FOR_EACH(action, A, B, C, ...) \
	GET_MACRO(__VA_ARGS__, \
		FE_99,FE_98,FE_97,FE_96,FE_95,FE_94,FE_93,FE_92,FE_91,FE_90, \
		FE_89,FE_88,FE_87,FE_86,FE_85,FE_84,FE_83,FE_82,FE_81,FE_80, \
		FE_79,FE_78,FE_77,FE_76,FE_75,FE_74,FE_73,FE_72,FE_71,FE_70, \
		FE_69,FE_68,FE_67,FE_66,FE_65,FE_64,FE_63,FE_62,FE_61,FE_60, \
		FE_59,FE_58,FE_57,FE_56,FE_55,FE_54,FE_53,FE_52,FE_51,FE_50, \
		FE_49,FE_48,FE_47,FE_46,FE_45,FE_44,FE_43,FE_42,FE_41,FE_40, \
		FE_39,FE_38,FE_37,FE_36,FE_35,FE_34,FE_33,FE_32,FE_31,FE_30, \
		FE_29,FE_28,FE_27,FE_26,FE_25,FE_24,FE_23,FE_22,FE_21,FE_20, \
		FE_19,FE_18,FE_17,FE_16,FE_15,FE_14,FE_13,FE_12,FE_11,FE_10, \
		FE_09,FE_08,FE_07,FE_06,FE_05,FE_04,FE_03,FE_02,FE_01,FE_00)(action, A, B, C, __VA_ARGS__)

#define SET_VARIABLE(result, index, object, var) \
	result.extract(index, #var, object.var)

#define SET_VARIABLES(result, index, object, ...) \
	do { \
		FOR_EACH(SET_VARIABLE, result, index, object, __VA_ARGS__); \
	} while(0)

namespace Wmi
{

	class WmiResult
	{
	
	public:
		WmiResult() :
			result()
		{}

		void set(std::size_t index, std::wstring name, const std::wstring &value);

		std::vector<std::map<std::wstring,std::wstring> >::iterator begin()
		{
			return result.begin();
		}

		std::vector<std::map<std::wstring,std::wstring> >::iterator end()
		{
			return result.end();
		}

		std::vector<std::map<std::wstring,std::wstring> >::const_iterator cbegin() const
		{
			return result.cbegin();
		}

		std::vector<std::map<std::wstring,std::wstring> >::const_iterator cend() const
		{
			return result.cend();
		}

		std::size_t size() const
		{
			return result.size();
		}
		
		bool extract(std::size_t index, const std::string &name, std::wstring &out) const;
		bool extract(std::size_t index, const std::string &name, std::string &out) const;
		bool extract(std::size_t index, const std::string &name, int &out) const;
		bool extract(std::size_t index, const std::string &name, bool &out) const;
		bool extract(std::size_t index, const std::string &name, uint64_t &out) const;

	private:
		std::vector<std::map<std::wstring,std::wstring> > result;

	}; //end class WmiResult

}; //end namespace Wmi

#endif //WMIRESULT_HPP