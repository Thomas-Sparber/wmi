/**
  *
  * WMI
  * @author Thomas Sparber (2016)
  *
 **/

#include <iostream>
#include <unistd.h>

#include <wmi.hpp>
#include <wmiclasses.hpp>

using std::cerr;
using std::cout;
using std::endl;
using std::wcout;

using namespace Wmi;

int main(int /*argc*/, char */*args*/[])
{
	try {
		Win32_ComputerSystem computer = retrieveWmi<Win32_ComputerSystem>();
		Win32_ComputerSystemProduct product  = retrieveWmi<Win32_ComputerSystemProduct>();

		cout<<"Computername: "<<computer.Name<<" Domaind:"<<computer.Domain<<endl;
		cout<<"Product: "<<product.Name<<" UUID:"<<product.UUID<<endl;
		cout<<endl;
		cout<<"Installed services:"<<endl;
		for(const Win32_Service &service : retrieveAllWmi<Win32_Service>())
		{
			cout<<service.Caption<<" started:"<<service.Started<<" state:"<<service.State<<  endl;
		}
	} catch (const WmiException &ex) {
		cerr<<"Wmi error: "<<ex.errorMessage<<", Code: "<<ex.hexErrorCode()<<endl;
		return 1;
	}

	return 0;
}