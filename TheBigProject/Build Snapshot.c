#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <Windows.h>
#include <psapi.h>
#include <time.h>
#include"Structs.h"
#include"LogFile.h"
#include"Build ProcessList.h"
#include"Build SnapShot.h"
#pragma warning (disable:4996)

char strError[1000];

t_SnapShot* Shead = NULL;
t_SnapShot* Stail = NULL;

int sampleCounter = 1;

t_SnapShot* OneSnapShot()
{
	char date[100];
	time_t t;
	time(&t);

	struct tm* timeInfo;

	timeInfo = localtime(&t);
	GetProcessInfo();
	t_SnapShot* SnapShot = (t_SnapShot*)malloc(sizeof(t_SnapShot));
	if (!SnapShot)
	{
		LogError(strerror(GetLastError()));
		exit(1);
	}
	
		SnapShot->next = SnapShot->prev = NULL;
		SnapShot->process = head;
		SnapShot->processCounter = PCounter;
		sprintf(date, "Date and time of sample: %d %d %d - %02d:%02d", timeInfo->tm_year + 1900, timeInfo->tm_mon + 1, timeInfo->tm_mday, timeInfo->tm_hour, timeInfo->tm_min);
		strcpy(SnapShot->SampleTime, date);
		SnapShot->sampleNumber = sampleCounter;
		sampleCounter++;

	//printTheList();
	

	// in order not to enter new snapshot to the list every time i use TwentySnapShots function
	return SnapShot;
	//releaseProcessList();
	//releaseDLLList();
	//releaseSnapShotList();
}
void TwentySnapShots() {
	t_SnapShot* origSnapShot = OneSnapShot();

	//in order not to run over the original list i use another pointers
	t_SnapShot* newTempSnapshot = NULL;

	t_Process* currentOrigProcess = NULL;
	t_Process* newProcess = NULL;
	t_Process* newProcessP = NULL;

	t_DLL* newDLLP = NULL;
	t_DLL* newProcessDll = NULL;
	t_DLL* currentOrigProcessDll = NULL;

	for (int i = 1; i < 21; i++)
	{
		newTempSnapshot = OneSnapShot();
		// check if there is the same process, if so I summarize their memory
		newProcess = newTempSnapshot->process;
		while (newProcess)
		{
			currentOrigProcess = origSnapShot->process;
			while (currentOrigProcess)
			{
				// Iterate over processes that are in main snapshot
				if (newProcess->ProcessID == currentOrigProcess->ProcessID)
				{
					// Sum current process's stuff
					currentOrigProcess->pmc.PageFaultCount += newProcess->pmc.PageFaultCount;
					currentOrigProcess->pmc.WorkingSetSize += newProcess->pmc.WorkingSetSize;
					currentOrigProcess->pmc.QuotaPagedPoolUsage += newProcess->pmc.QuotaPagedPoolUsage;
					currentOrigProcess->pmc.QuotaPeakPagedPoolUsage += newProcess->pmc.QuotaPeakPagedPoolUsage;
					currentOrigProcess->pmc.PagefileUsage += newProcess->pmc.PagefileUsage;

					// Iterate new dll list
					newProcessDll = newProcess->ProcessDLLList;
					while (newProcessDll)
					{
						currentOrigProcessDll = currentOrigProcess->ProcessDLLList;
						while (currentOrigProcessDll)
						{
							if (strncmp(currentOrigProcessDll->DLLName, newProcessDll->DLLName, MAX_PATH) == 0)
							{
								break;
							}
							else if (!currentOrigProcessDll->next)
							{

								newDLLP = (t_DLL*)malloc(sizeof(t_DLL));
								if (!newDLLP)
								{
									LogError(strerror(GetLastError()));
									exit(1);
								}
								*newDLLP = *newProcessDll;

								currentOrigProcessDll->next = newDLLP;
								newDLLP->prev = currentOrigProcessDll;
								newDLLP->next = NULL;
								currentOrigProcess->DLLNumber++;
							}

							currentOrigProcessDll = currentOrigProcessDll->next;
						}

						newProcessDll = newProcessDll->next;
					}
				// found the process, stop and go to the next one
				break;
				}
				else if (!currentOrigProcess->next) 
				{
					newProcessP = (t_Process*)malloc(sizeof(t_Process));
					if (!newProcessP)
					{
						LogError(strerror(GetLastError()));
						exit(1);
					}
					*newProcessP = *newProcess;

					currentOrigProcess->next = newProcessP;
					newProcessP->prev = currentOrigProcess;
					newProcessP->next = NULL;
				}
				currentOrigProcess = currentOrigProcess->next;
			}

			newProcess = newProcess->next;
		}

		Sleep(1000);
		printf("%d\n",i);
	}
	buildSnapShotList(origSnapShot);
}

void printTheList() {
	int d = 1;
	t_Process* curr = head;
	t_DLL* temp = Dhead;
	while (curr) {
		printf("Process ID-%d\nProcess Name-%s\nProcess Memory-%zu\n%zu\n%zu\n%zu\n%zu\nProcess DLL List-", curr->ProcessID, curr->ProcessName, curr->pmc.PageFaultCount, curr->pmc.WorkingSetSize, curr->pmc.QuotaPagedPoolUsage, curr->pmc.QuotaPeakPagedPoolUsage, curr->pmc.PagefileUsage);
		while (curr->ProcessDLLList)
		{
			printf("%d:%s\n",d, curr->ProcessDLLList->DLLName);
			curr->ProcessDLLList = curr->ProcessDLLList->next;
			d++;
		}
		curr = curr->next;
	}
}

void buildSnapShotList(t_SnapShot* snapShot)
{
	t_SnapShot* addSnapShot = snapShot;
	if (!Shead)
	{
		Shead = addSnapShot;
		Stail = addSnapShot;
	}
	else
	{
		addSnapShot->prev = Stail;
		Stail->next = addSnapShot;
		Stail = addSnapShot;
	}
	sampleCounter++;

}

