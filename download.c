#include "stdafx.h"
#include <Windows.h>

int main(int argc, char * argv[])
{
	int i;
	for (i = 1; i < argc; i++) {}
	if (i!=3) {
		printf("Usage: download.exe https://www.microsoft.com/favicon.ico c:\\1.txt");

	}
	else
	{
		typedef UINT(CALLBACK *t_DownloadFile)(LPCSTR, LPCSTR, int);
		CHAR *dllpath = "C:\\Windows\\System32\\inseng.dll";
		HMODULE dll = LoadLibraryA(dllpath);
		t_DownloadFile DownloadFile = (t_DownloadFile)GetProcAddress(dll, "DownloadFile");
		DownloadFile(argv[1], argv[2], 1);
		printf("%s\r\n",argv[1]);
		printf("%s\r\n",argv[2]);
		printf("ok!\r\n");
	}
	return 0;
}
