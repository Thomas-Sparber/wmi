// Written by: Diaa Sami

#include <windows.h>
#include <stdlib.h>
#include <strsafe.h>

void __stdcall _com_issue_error(HRESULT hr)
{
	#define MESSAGE_LENGTH_MAX 128
	char message[MESSAGE_LENGTH_MAX];
	StringCbPrintfA(message, MESSAGE_LENGTH_MAX, "_com_issue_error() called with parameter HRESULT = %lu", hr);
	MessageBox(NULL, message, "Error", MB_OK | MB_ICONERROR);
}

namespace _com_util
{
	char * __stdcall ConvertBSTRToString(BSTR bstr)
	{
		const unsigned int stringLength = lstrlenW(bstr);
		char *const ascii = new char [stringLength + 1];

		wcstombs(ascii, bstr, stringLength + 1);

		return ascii;
	}

	BSTR __stdcall ConvertStringToBSTR(const char *const ascii)
	{
		const unsigned int stringLength = lstrlenA(ascii);
		BSTR bstr = SysAllocStringLen(NULL, stringLength);

		mbstowcs(bstr, ascii, stringLength + 1);

		return bstr;
	}
}
