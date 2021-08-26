/**
  *
  * WMI
  * @author Thomas Sparber (2016)
  *
 **/

#include <algorithm>
#include <codecvt>
#include <locale>

#include <wmiresult.hpp>

using std::codecvt_utf8;
using std::string;
using std::transform;
using std::wstring;
using std::wstring_convert;

using namespace Wmi;

void WmiResult::set(std::size_t index, wstring name, const wstring &value)
{
	while(index >= result.size())result.emplace_back();

	transform(name.begin(), name.end(), name.begin(), ::tolower);
	result[index][name] = value;
}

bool WmiResult::extract(std::size_t index, const string &name, wstring &out) const
{
	if(index >= result.size())return false;

	wstring key(name.cbegin(), name.cend());
	transform(key.begin(), key.end(), key.begin(), ::tolower);

	auto found = result[index].find(key);
	if(found == result[index].cend())return false;
	
	out = found->second;
	return true;
}

bool WmiResult::extract(std::size_t index, const string &name, string &out) const
{
	wstring temp;
	if(!extract(index, name, temp))return false;

	wstring_convert<codecvt_utf8<wchar_t>> myconv;
	out = myconv.to_bytes(temp);
	return true;
}

bool WmiResult::extract(std::size_t index, const string &name, int &out) const
{
	string temp;
	if(!extract(index, name, temp))return false;
	
	char *test;
	out = strtol(temp.c_str(), &test, 0);
	return (test == temp.c_str() + temp.length());
}

bool WmiResult::extract(std::size_t index, const string &name, bool &out) const
{
	string temp;
	if(!extract(index, name, temp))return false;

	transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
	if(temp == "true" || temp == "1")out = true;
	else if(temp == "false" || temp == "0")out = false;
	else return false;
	
	return true;
}

bool WmiResult::extract(std::size_t index, const string &name, uint64_t &out) const
{
	string temp;
	if(!extract(index, name, temp))return false;
	
	char *test;
	out = strtoull(temp.c_str(), &test, 0);
	return (test == temp.c_str() + temp.length());
}

bool WmiResult::extract(std::size_t index, const string &name, uint32_t &out) const
{
	string temp;
	if(!extract(index, name, temp))return false;
	
	char *test;
	out = (uint32_t)std::strtoul(temp.c_str(), &test, 0);
	return (test == temp.c_str() + temp.length());
}

bool WmiResult::extract(std::size_t index, const string &name, uint16_t &out) const
{
	string temp;
	if(!extract(index, name, temp))return false;
	
	char *test;
	out = (uint16_t)std::strtoul(temp.c_str(), &test, 0);
	return (test == temp.c_str() + temp.length());
}