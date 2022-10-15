#include <Windows.h>
#include <psapi.h>
#include <stdio.h>
#pragma once

typedef struct DLLList {
	char DLLName[MAX_PATH];
	struct DLLList* next;
	struct DLLList* prev;
}t_DLL;

typedef struct Processes {
	PROCESS_MEMORY_COUNTERS pmc;
	int ProcessID;
	char ProcessName[MAX_PATH];
	t_DLL* ProcessDLLList;
	int DLLNumber;
	struct Processes* next;
	struct Processes* prev;
}t_Process;

typedef struct snapShot {
	t_Process* process;
	int processCounter;
	char SampleTime[50];
	int sampleNumber;
	struct snapShot* next;
	struct snapShot* prev;
}t_SnapShot;

typedef struct HeaderFile {
	int version;
	int ItemsCount;
	char reserve[100];
}t_headerOfFile;

typedef struct DLLDictionary {
	char DLLName[MAX_PATH];
	struct Processes* ProcessList;
	struct DLLDictionary* next;
	struct DLLDictionary* prev;
}t_DLLDictionary;