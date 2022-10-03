#include <Windows.h>
#include <psapi.h>
#include <stdio.h>
#pragma once

typedef struct DLLList {
	char DLLName[MAX_PATH];
	struct DLL* next;
	struct DLL* prev;
}td_DLL;

typedef struct Processes {
	PROCESS_MEMORY_COUNTERS pmc;
	int ProcessID;
	char ProcessName[MAX_PATH];
	td_DLL* DLL;
	int numOfDLL;
	struct Process* next;
	struct Process* prev;
}tp_Process;

typedef struct snapShot {
	tp_Process* process;
	int processCounter;
	char timeOfSample[50];
	int sampleNumber;
	struct snapShot* next;
	struct snapShot* prev;
}ts_snapShot;

typedef struct HeaderFile {
	int version;
	int serialNum;
	int ItemsCount;
	char reserve[100];
}th_headerOfFile;