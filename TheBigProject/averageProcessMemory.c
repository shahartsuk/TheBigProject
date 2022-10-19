#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <Windows.h>
#include <psapi.h>
#include <conio.h>
#include <time.h>
#include"Structs.h"
#include"LogFile.h"
#include"Build ProcessList.h"
#include"Build SnapShot.h"
#include"DLLDictionary.h"
#include"averageProcessMemory.h"
#pragma warning (disable:4996)

	unsigned long long sumAllSnapShots = 0;

 long averageProcessMemory(t_SnapShot* currSnapShot)
{
	t_SnapShot* snapShot=currSnapShot;
	t_Process* currProcess = snapShot->process;
	unsigned long long sum1SnapShot=0;
	long avg = 0;

	while(snapShot)
	{
		while (currProcess)
		{
		sum1SnapShot += currProcess->pmc.WorkingSetSize;

		currProcess = currProcess->next;
		}
		snapShot = snapShot->next;
	}
	avg = (long)(sum1SnapShot / snapShot->processCounter);
	sumAllSnapShots += sum1SnapShot;
	if (snapShot->next == NULL)
	{
		sumAllSnapShots / ProcessCounter/ snapShot->processCounter;
	}
	return avg;
}
 void buildProcessDictionaryList(t_Process* newProcess)
 {
	 ProcessCounter++;
	 t_PDictionary* addProcessID = (t_PDictionary*)malloc(sizeof(t_PDictionary));
	 if (!addProcessID)
	 {
		 LogError(strerror(GetLastError()));
		 exit(1);
	 }
	 t_Process* newItem = newProcess;
	 addProcessID->ProcessID = newItem->ProcessID;
	 addProcessID->next = addProcessID->prev = NULL;

	 if (!PDictionaryHead)
	 {
		 PDictionaryHead = addProcessID;
		 PDictionaryTail = addProcessID;
		 return;
	 }
	 else
	 {
		 addProcessID->prev = PDictionaryTail;
		 PDictionaryTail->next = addProcessID;
		 PDictionaryTail = addProcessID;
		 return;
	 }

 }
