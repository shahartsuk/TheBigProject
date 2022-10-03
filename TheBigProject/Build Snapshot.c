#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <Windows.h>
#include <psapi.h>
#include"Structs.h"
#include"LogFile.h"
#include"BuildSnapshot.h"
#pragma warning (disable:4996)

char strError[1000];

void ProcessMemoryInfo(DWORD processID)
{
	HANDLE hProcess;
	// pointer to process
	PROCESS_MEMORY_COUNTERS pmc;

	// open the process, get the handle of the process
	hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);
	if (NULL == hProcess)
	{
		strcpy(strError, "Process is not opened");
		LogError(strError);
		return;
	}
		HMODULE hMods[1024];
		// amount of the processes i need
		DWORD cbNeeded;
		TCHAR Buffer[MAX_PATH];
		TCHAR Buffer2[MAX_PATH];
		TCHAR DLLName[MAX_PATH];
		char regularCharArr[MAX_PATH];
		// get the name of the process
		if (GetModuleFileNameEx(hProcess, 0, Buffer, MAX_PATH))
		{
			// At this point buffer contains the full path of the execut
		}
		else
		{
			//printf("Error2");
			// GetLastError()
		}

		// coppy information about the process to pmc like malloc
		if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
		{
			
		}
		// have to close every process i opened

		// get DLL list

		if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
		{
			for (int i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
			{
				// Get the full path to the module's file.

				if (GetModuleFileNameEx(hProcess, hMods[i], DLLName, MAX_PATH))
				{
					// * Get the module name and handle value.
					printf("%s", DLLName);

					// Convert wChar to regular char array (string)
					char dllName[MAX_PATH];
					size_t numConverted;
					wcstombs_s(&numConverted, dllName, MAX_PATH, DLLName, MAX_PATH);

					int tmp = 0;
					tmp++;
				}
			}
		}
		CloseHandle(hProcess);
}
void GetProcessInfo()
{
	//Get processes
	//Receive all process ID

	// string of processes
	DWORD aProcesses[1024], cbNeeded, cProcesses;
	unsigned int i;

	// EnumProcesses function get the processes id
	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
	{
		strcpy(strError, "Enum Function cant get the processes ID");
		logError(strError);
		return 1;
	}

	// Calculate how many process identifiers were returned

	cProcesses = cbNeeded / sizeof(DWORD);

	//print the memory usage for each process

		for (i = 0; i < cProcesses; i++)
		{
			ProcessMemoryInfo(aProcesses[i]);
		}
	
	// for each process to get its memory information
}