/**
  *
  * WMI
  * @author Thomas Sparber (2016)
  *
 **/

#ifndef WMICLASSES_HPP
#define WMICLASSES_HPP

#include <string>

#include <wmi.hpp>
#include <wmiresult.hpp>

namespace Wmi
{

struct Win32_ComputerSystem
{

	Win32_ComputerSystem() :
		AdminPasswordStatus(), AutomaticManagedPagefile(), AutomaticResetBootOption(), AutomaticResetCapability(),
		BootOptionOnLimit(), BootOptionOnWatchDog(), BootROMSupported(), BootupState(), Caption(), ChassisBootupState(),
		CreationClassName(), CurrentTimeZone(), DaylightInEffect(), Description(), DNSHostName(), Domain(), DomainRole(),
		EnableDaylightSavingsTime(), FrontPanelResetStatus(), InfraredSupported(), InitialLoadInfo(), InstallDate(),
		KeyboardPasswordStatus(), LastLoadInfo(), Manufacturer(), Model(), Name(), NameFormat(), NetworkServerModeEnabled(),
		NumberOfLogicalProcessors(), NumberOfProcessors(), OEMLogoBitmap(), OEMStringArray(), PartOfDomain(),
		PauseAfterReset(), PCSystemType(), PowerManagementCapabilities(), PowerManagementSupported(),
		PowerOnPasswordStatus(), PowerState(), PowerSupplyState(), PrimaryOwnerContact(), PrimaryOwnerName(),
		ResetCapability(), ResetCount(), ResetLimit(), Roles(), Status(), SupportContactDescription(), SystemStartupDelay(),
		SystemStartupOptions(), SystemStartupSetting(), SystemType(), ThermalState(), TotalPhysicalMemory(), UserName(),
		WakeUpType(), Workgroup()
	{}

	void setProperties(const WmiResult &result, std::size_t index)
	{
		SET_VARIABLES(result, index, (*this),
			AdminPasswordStatus, AutomaticManagedPagefile, AutomaticResetBootOption, AutomaticResetCapability,
			BootOptionOnLimit, BootOptionOnWatchDog, BootROMSupported, BootupState, Caption, ChassisBootupState,
			CreationClassName, CurrentTimeZone, DaylightInEffect, Description, DNSHostName, Domain, DomainRole,
			EnableDaylightSavingsTime, FrontPanelResetStatus, InfraredSupported, InitialLoadInfo, InstallDate,
			KeyboardPasswordStatus, LastLoadInfo, Manufacturer, Model, Name, NameFormat, NetworkServerModeEnabled,
			NumberOfLogicalProcessors, NumberOfProcessors, OEMLogoBitmap, OEMStringArray, PartOfDomain,
			PauseAfterReset, PCSystemType, PowerManagementCapabilities, PowerManagementSupported,
			PowerOnPasswordStatus, PowerState, PowerSupplyState, PrimaryOwnerContact, PrimaryOwnerName,
			ResetCapability, ResetCount, ResetLimit, Roles, Status, SupportContactDescription, SystemStartupDelay,
			SystemStartupOptions, SystemStartupSetting, SystemType, ThermalState, TotalPhysicalMemory, UserName,
			WakeUpType, Workgroup
		);
	}

	static std::string getWmiClassName()
	{
		return "Win32_ComputerSystem";
	}

	int AdminPasswordStatus;
	bool AutomaticManagedPagefile;
	bool AutomaticResetBootOption;
	bool AutomaticResetCapability;
	std::string BootOptionOnLimit;
	std::string BootOptionOnWatchDog;
	bool BootROMSupported;
	std::string BootupState;
	std::string Caption;
	int ChassisBootupState;
	std::string CreationClassName;
	int CurrentTimeZone;
	bool DaylightInEffect;
	std::string Description;
	std::string DNSHostName;
	std::string Domain;
	int DomainRole;
	bool EnableDaylightSavingsTime;
	int FrontPanelResetStatus;
	bool InfraredSupported;
	std::string InitialLoadInfo;
	std::string InstallDate;
	int KeyboardPasswordStatus;
	std::string LastLoadInfo;
	std::string Manufacturer;
	std::string Model;
	std::string Name;
	std::string NameFormat;
	bool NetworkServerModeEnabled;
	int NumberOfLogicalProcessors;
	int NumberOfProcessors;
	std::string OEMLogoBitmap;
	std::string OEMStringArray;
	bool PartOfDomain;
	int PauseAfterReset;
	int PCSystemType;
	std::string PowerManagementCapabilities;
	std::string PowerManagementSupported;
	int PowerOnPasswordStatus;
	int PowerState;
	int PowerSupplyState;
	std::string PrimaryOwnerContact;
	std::string PrimaryOwnerName;
	int ResetCapability;
	int ResetCount;
	int ResetLimit;
	std::string Roles;
	std::string Status;
	std::string SupportContactDescription;
	std::string SystemStartupDelay;
	std::string SystemStartupOptions;
	std::string SystemStartupSetting;
	std::string SystemType;
	int ThermalState;
	uint64_t TotalPhysicalMemory;
	std::string UserName;
	int WakeUpType;
	std::string Workgroup;

}; //end struct Win32_ComputerSystem

struct Win32_ParallelPort
{

	Win32_ParallelPort() :
		Availability(), Capabilities(), CapabilityDescriptions(), Caption(), ConfigManagerErrorCode(),
		ConfigManagerUserConfig(), CreationClassName(), Description(), DeviceID(), DMASupport(), ErrorCleared(),
		ErrorDescription(), InstallDate(), LastErrorCode(), MaxNumberControlled(), Name(), OSAutoDiscovered(),
		PNPDeviceID(), PowerManagementCapabilities(), PowerManagementSupported(), ProtocolSupported(), Status(),
		StatusInfo(), SystemCreationClassName(), SystemName(), TimeOfLastReset()
	{}

	void setProperties(const WmiResult &result, std::size_t index)
	{
		SET_VARIABLES(result, index, (*this),
			Availability, Capabilities, CapabilityDescriptions, Caption, ConfigManagerErrorCode,
			ConfigManagerUserConfig, CreationClassName, Description, DeviceID, DMASupport, ErrorCleared,
			ErrorDescription, InstallDate, LastErrorCode, MaxNumberControlled, Name, OSAutoDiscovered,
			PNPDeviceID, PowerManagementCapabilities, PowerManagementSupported, ProtocolSupported, Status,
			StatusInfo, SystemCreationClassName, SystemName, TimeOfLastReset
		);
	}

	static std::string getWmiClassName()
	{
		return "Win32_ParallelPort";
	}
	
	int Availability;
	std::string Capabilities;
	std::string CapabilityDescriptions;
	std::string Caption;
	int ConfigManagerErrorCode;
	bool ConfigManagerUserConfig;
	std::string CreationClassName;
	std::string Description;
	std::string DeviceID;
	bool DMASupport;
	std::string ErrorCleared;
	std::string ErrorDescription;
	std::string InstallDate;
	int LastErrorCode;
	int MaxNumberControlled;
	std::string Name;
	bool OSAutoDiscovered;
	std::string PNPDeviceID;
	std::string PowerManagementCapabilities;
	bool PowerManagementSupported;
	int ProtocolSupported;
	std::string Status;
	std::string StatusInfo;
	std::string SystemCreationClassName;
	std::string SystemName;
	std::string TimeOfLastReset;

}; //end class Win32_ParallelPort

struct Win32_Service
{

	Win32_Service() :
		AcceptPause(), AcceptStop(), Caption(), CheckPoint(), CreationClassName(), Description(),
		DesktopInteract(), DisplayName(), ErrorControl(), ExitCode(), InstallDate(), Name(), PathName(),
		ProcessId(), ServiceSpecificExitCode(), ServiceType(), Started(), StartMode(), StartName(), State(),
		Status(), SystemCreationClassName(), SystemName(), TagId(), WaitHint()
	{}

	void setProperties(const WmiResult &result, std::size_t index)
	{
		SET_VARIABLES(result, index, (*this),
			AcceptPause, AcceptStop, Caption, CheckPoint, CreationClassName, Description,
			DesktopInteract, DisplayName, ErrorControl, ExitCode, InstallDate, Name, PathName,
			ProcessId, ServiceSpecificExitCode, ServiceType, Started, StartMode, StartName, State,
			Status, SystemCreationClassName, SystemName, TagId, WaitHint
		);
	}

	static std::string getWmiClassName()
	{
		return "Win32_Service";
	}
	
	bool AcceptPause;
	bool AcceptStop;
	std::string Caption;
	int CheckPoint;
	std::string CreationClassName;
	std::string Description;
	bool DesktopInteract;
	std::string DisplayName;
	std::string ErrorControl;
	int ExitCode;
	std::string InstallDate;
	std::string Name;
	std::string PathName;
	int ProcessId;
	int ServiceSpecificExitCode;
	std::string ServiceType;
	bool Started;
	std::string StartMode;
	std::string StartName;
	std::string State;
	std::string Status;
	std::string SystemCreationClassName;
	std::string SystemName;
	int TagId;
	int WaitHint;

}; //end Win32_Service

struct Win32_SerialPort
{

	Win32_SerialPort() :
		Availability(), Binary(), Capabilities(), CapabilityDescriptions(), Caption(),
		ConfigManagerErrorCode(), ConfigManagerUserConfig(), CreationClassName(), Description(),
		DeviceID(), ErrorCleared(), ErrorDescription(), InstallDate(), LastErrorCode(), MaxBaudRate(),
		MaximumInputBufferSize(), MaximumOutputBufferSize(), MaxNumberControlled(), Name(),
		OSAutoDiscovered(), PNPDeviceID(), PowerManagementCapabilities(), PowerManagementSupported(),
		ProtocolSupported(), ProviderType(), SettableBaudRate(), SettableDataBits(),
		SettableFlowControl(), SettableParity(), SettableParityCheck(), SettableRLSD(),
		SettableStopBits(), Status(), StatusInfo(), Supports16BitMode(), SupportsDTRDSR(),
		SupportsElapsedTimeouts(), SupportsIntTimeouts(), SupportsParityCheck(), SupportsRLSD(),
		SupportsRTSCTS(), SupportsSpecialCharacters(), SupportsXOnXOff(), SupportsXOnXOffSet(),
		SystemCreationClassName(), SystemName(), TimeOfLastReset()
	{}

	void setProperties(const WmiResult &result, std::size_t index)
	{
		SET_VARIABLES(result, index, (*this),
			Availability, Binary, Capabilities, CapabilityDescriptions, Caption,
			ConfigManagerErrorCode, ConfigManagerUserConfig, CreationClassName, Description,
			DeviceID, ErrorCleared, ErrorDescription, InstallDate, LastErrorCode, MaxBaudRate,
			MaximumInputBufferSize, MaximumOutputBufferSize, MaxNumberControlled, Name,
			OSAutoDiscovered, PNPDeviceID, PowerManagementCapabilities, PowerManagementSupported,
			ProtocolSupported, ProviderType, SettableBaudRate, SettableDataBits,
			SettableFlowControl, SettableParity, SettableParityCheck, SettableRLSD,
			SettableStopBits, Status, StatusInfo, Supports16BitMode, SupportsDTRDSR,
			SupportsElapsedTimeouts, SupportsIntTimeouts, SupportsParityCheck, SupportsRLSD,
			SupportsRTSCTS, SupportsSpecialCharacters, SupportsXOnXOff, SupportsXOnXOffSet,
			SystemCreationClassName, SystemName, TimeOfLastReset
		);
	}

	static std::string getWmiClassName()
	{
		return "Win32_SerialPort";
	}
	
	int Availability;
	bool Binary;
	std::string Capabilities;
	std::string CapabilityDescriptions;
	std::string Caption;
	int ConfigManagerErrorCode;
	bool ConfigManagerUserConfig;
	std::string CreationClassName;
	std::string Description;
	std::string DeviceID;
	std::string ErrorCleared;
	std::string ErrorDescription;
	std::string InstallDate;
	int LastErrorCode;
	uint64_t MaxBaudRate;
	uint64_t MaximumInputBufferSize;
	uint64_t MaximumOutputBufferSize;
	int MaxNumberControlled;
	std::string Name;
	bool OSAutoDiscovered;
	std::string PNPDeviceID;
	std::string PowerManagementCapabilities;
	bool PowerManagementSupported;
	int ProtocolSupported;
	std::string ProviderType;
	std::string SettableBaudRate;
	std::string SettableDataBits;
	std::string SettableFlowControl;
	std::string SettableParity;
	std::string SettableParityCheck;
	std::string SettableRLSD;
	std::string SettableStopBits;
	std::string Status;
	std::string StatusInfo;
	bool Supports16BitMode;
	bool SupportsDTRDSR;
	bool SupportsElapsedTimeouts;
	bool SupportsIntTimeouts;
	bool SupportsParityCheck;
	bool SupportsRLSD;
	bool SupportsRTSCTS;
	bool SupportsSpecialCharacters;
	bool SupportsXOnXOff;
	bool SupportsXOnXOffSet;
	std::string SystemCreationClassName;
	std::string SystemName;
	std::string TimeOfLastReset;

}; //end Win32_SerialPort

} //end namespace wmi

#endif //WMICLASSES_HPP