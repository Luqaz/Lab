#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <conio.h>


int main()
{
	FILE *f;
	f = fopen("in.txt", "rt");
	int n=0, count=0;
	while (!feof(f))
	{
		fscanf(f, "%d", n);
		count++;
	}
	int* arr = (int*)calloc(count, sizeof(int));
	printf("Input number of processes: ");
	scanf("%d", n);
	STARTUPINFO* si = (STARTUPINFO*)calloc(n, sizeof(STARTUPINFO));
	PROCESS_INFORMATION* piApp = (PROCESS_INFORMATION*)calloc(n, sizeof(PROCESS_INFORMATION));
	char string[128];
	for (int i = 0; i < count; i++)
	{
		sprintf(string, "%d", arr[i]);
	}
	char* path = "\"E:\\4 сем\\ConsoleApplication1\\Child\\Debug\\Child.exe\" ";
	strcat(path, string);
	wchar_t *wpath;
	mbstowcs(wpath, path, strlen(path)+1);
	for (int i = 0; i < n; i++)
	{
		ZeroMemory(&si[i], sizeof(STARTUPINFO));
		si[i].cb = sizeof(STARTUPINFO);
		if (!CreateProcess(NULL, wpath, NULL, NULL, FALSE, 0, NULL, NULL, &si[i], &piApp[i]))
		{
			printf("Error");
		}
	}	
	HANDLE *hProcess = (HANDLE*)calloc(n, sizeof(HANDLE));
	for (int i = 0; i < n; i++)
	{
		hProcess[i] = piApp[i].hProcess;
	}
	WaitForMultipleObjects(count, hProcess, TRUE, INFINITE);
	for (int i = 0; i < n; i++)
	{
		CloseHandle(piApp[i].hThread);
		CloseHandle(piApp[i].hProcess);
	}
	return 0;
}

