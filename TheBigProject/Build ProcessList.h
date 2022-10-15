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
void ProcessMemoryInfo(DWORD);

// GetProcessInfo() this function call ProcessMemoryInfo
int GetProcessInfo();
void buildDllList(char[MAX_PATH]);
void buildProcessData(int, char[MAX_PATH], int, PROCESS_MEMORY_COUNTERS);
void buildProcessList(t_Process*);

