#pragma once
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <Windows.h>
#include <psapi.h>
#include"Structs.h"

extern t_Process* head ;
extern t_Process* tail;

extern t_DLL* Dhead;
extern t_DLL* Dtail;

extern int PCounter;
void ProcessMemoryInfo(DWORD processID);

// GetProcessInfo() this function call ProcessMemoryInfo
int GetProcessInfo();
void buildDllList(char NDLL[MAX_PATH]);
void buildProcessList(int PID, char PName[MAX_PATH], int DLLNumber, t_DLL* DLLList, PROCESS_MEMORY_COUNTERS ProcessMemory);

