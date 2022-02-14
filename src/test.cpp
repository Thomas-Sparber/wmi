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
using std::string;
using std::wcout;

using namespace Wmi;

int main(int /*argc*/, char */*args*/[])
{
	try {
		Win32_ComputerSystem computer = retrieveWmi<Win32_ComputerSystem>();
		Win32_ComputerSystemProduct product  = retrieveWmi<Win32_ComputerSystemProduct>();
		SoftwareLicensingService liscense  = retrieveWmi<SoftwareLicensingService>();
		Win32_OperatingSystem os_info  = retrieveWmi<Win32_OperatingSystem>();
				
		cout<<"Computername: "<<computer.Name<<" Domain: "<<computer.Domain<<endl;
		cout<<"Product: "<<product.Name<<" UUID:"<<product.UUID<<endl;
		cout<<"Architecture: "<<os_info.OSArchitecture<<std::endl;
		cout<<"Roles: "<<endl;
		for(const string &role : computer.Roles)
		{
			cout<<" - "<<role<<std::endl;
		}
		cout<<endl;
		cout<<"Machine Id:"<<liscense.ClientMachineID<<" Kmsid:"<<liscense.KeyManagementServiceProductKeyID<<std::endl;
		cout<<"Installed services:"<<endl;

		// gets all rows and all columns
		for(const Win32_Service &service : retrieveAllWmi<Win32_Service>())
		{
			cout<<service.Caption<<" started:"<<service.Started<<" state:"<<service.State<<  endl;
		}
		
		// gets all rows and only specified columns(better performance)
		for(const Win32_Service &service : retrieveAllWmi<Win32_Service>("Caption,Started,State"))
		{
			cout<<service.Caption<<" started:"<<service.Started<<" state:"<<service.State<<  endl;
		}

		//Example for using a class that has a non default root (securitycenter2)
		//This can be accombplished by implementing getWmiPath in the wmi class
		cout << "Antivirus installed:" << endl;
		for (const AntiVirusProduct& antivirus : retrieveAllWmi<AntiVirusProduct>())
		{
			cout << antivirus.DisplayName << " | path:" << antivirus.PathToSignedProductExe << " state:" << antivirus.ProductState << " time: " << antivirus.Timestamp << endl;
		}

		// Example for Windows Embedded
		//UWF_Filter filter = retrieveWmi<UWF_Filter>();
		//cout << "UWF Filter enabled:" << filter.CurrentEnabled << std::endl;
	} catch (const WmiException &ex) {
		cerr<<"Wmi error: "<<ex.errorMessage<<", Code: "<<ex.hexErrorCode()<<endl;
		return 1;
	}

	return 0;
}