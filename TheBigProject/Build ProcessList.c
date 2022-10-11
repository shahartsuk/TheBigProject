#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <Windows.h>
#include <psapi.h>
#include <time.h>
#include"Structs.h"
#include"LogFile.h"
#include"Build ProcessList.h"
#pragma warning (disable:4996)

t_Process* head = NULL;
t_Process* tail = NULL;

t_DLL* Dhead = NULL;
t_DLL* Dtail = NULL;

int PCounter=0;

void ProcessMemoryInfo(DWORD processID)
{
	int DLLCounter=0;
	int i = 0;
	HANDLE hProcess;
	// pointer to process
	PROCESS_MEMORY_COUNTERS pmc;

	// open the process, get the handle of the process
	hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);
	if (NULL == hProcess)
	{
		///////////////////////////////////////////LogError(strerror(GetLastError()));
		return;
	}
		HMODULE hMods[1024];
		// amount of the processes i need
		DWORD cbNeeded;
		TCHAR Buffer[MAX_PATH];
		TCHAR DLLName[MAX_PATH];
		char DllName[MAX_PATH];
		char ProcessName[MAX_PATH];
		char regularCharArr[MAX_PATH];
		size_t numConverted;
		// get the name of the process
		if (GetModuleFileNameEx(hProcess, 0, Buffer, MAX_PATH))
		{
			// At this point buffer contains the full path of the execut
			wcstombs_s(&numConverted, ProcessName, MAX_PATH, Buffer, MAX_PATH);
			if (strlen(ProcessName) <= 1)
			{
				return;
			}
		}
		else
		{
			// //////////////////LogError(strerror(GetLastError()));
			return;
		}

		// coppy information about the process to pmc like malloc
		if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
		{	

		}
		// have to close every process i opened

		// get DLL list

		if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
		{
			for (i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
			{
				// Get the full path to the module's file.

				if (GetModuleFileNameEx(hProcess, hMods[i], DLLName, MAX_PATH))
				{
					
					// * Get the module name and handle value.
					//printf("%s", DLLName);

					// Convert wChar to regular char array (string)
					size_t numConverted;
					wcstombs_s(&numConverted, DllName, MAX_PATH, DLLName, MAX_PATH);
					if (strlen(DllName ) <= 1)
					{
						break;
					}
					DLLCounter++;
					
				}
				//printf("%s", DllName);
			buildDllList(DllName);
			}
		}

		buildProcessList(processID,ProcessName,DLLCounter,Dhead,pmc);

		CloseHandle(hProcess);
}
int GetProcessInfo()
{
	//Get processes
	//Receive all process ID

	// string of processes
	PCounter = 0;
	DWORD aProcesses[1024], cbNeeded, cProcesses;
	unsigned long i;

	// EnumProcesses function get the processes id
	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
	{
		///////////////////////////////////////LogError(strerror(GetLastError()));
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

void buildDllList(char NDLL[MAX_PATH])
{
	t_DLL* addDLL = (t_DLL*)malloc(sizeof(t_DLL));
	if (!addDLL)
	{
		/////////////////////////////////LogError(strerror(GetLastError()));
		return;
	}
	else
	{
	strcpy(addDLL->DLLName,NDLL);
	addDLL->next = NULL;
	addDLL->prev = NULL;
	if (!Dhead)
	{
		Dhead = addDLL;
		Dtail = addDLL;
	}
	else {
		addDLL->prev = Dtail;
		Dtail->next = addDLL;
		Dtail = addDLL;
	}
	}
}
void buildProcessList(int PID, char PName[MAX_PATH], int DLLNumber, t_DLL* DLLList, PROCESS_MEMORY_COUNTERS ProcessMemory)
{
	t_Process* curr = (t_Process*)malloc(sizeof(t_Process));
	if (!curr)
	{
		///////////////////////////////////LogError(strerror(GetLastError()));
		return;
	}
	else {
	curr->ProcessID = PID;
	strcpy(curr->ProcessName, PName);
	curr->ProcessDLLList = Dhead;
	curr->DLLNumber = DLLNumber;
	curr->pmc.PageFaultCount = ProcessMemory.PageFaultCount;
	curr->pmc.WorkingSetSize = ProcessMemory.WorkingSetSize;
	curr->pmc.QuotaPagedPoolUsage = ProcessMemory.QuotaPagedPoolUsage;
	curr->pmc.QuotaPeakPagedPoolUsage = ProcessMemory.QuotaPeakPagedPoolUsage;
	curr->pmc.PagefileUsage = ProcessMemory.PagefileUsage;
	curr->next = curr->prev = NULL;
	PCounter++;
	if (!head)
	{
		head = curr;
		tail = curr;
	}
	else {
		curr->prev = tail;
		tail->next = curr;
		tail = curr;
	}
	}
	Dhead = Dtail = NULL;
}




   