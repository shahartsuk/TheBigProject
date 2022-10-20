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
	sortingProcessList();
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

		head = tail = NULL;
		Dhead = Dtail = NULL;

	// in order not to enter new snapshot to the list every time i use TwentySnapShots function
	return SnapShot;
	
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
							if (strcmp(currentOrigProcessDll->DLLName, newProcessDll->DLLName) == 0)
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
					origSnapShot->processCounter++;
					break;
				}
				currentOrigProcess = currentOrigProcess->next;
			}

			newProcess = newProcess->next;
		}
		resetSnapShot(newTempSnapshot);
		Sleep(1000);
		printf("%d\n",i);
	}
	buildSnapShotList(origSnapShot);
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
void printDllList(t_DLL* dll) // a function that i was checking if dll has been added
{
	t_DLL* temp = dll;
	int i = 1;
	printf("Dll list:\n");
	while (temp)
	{
		printf("%d. %s\n", i, temp->DLLName);
		i++;
		temp = temp->next;
	}
}


void printProcessList(t_Process* proc) // a function that i was checking if process has been added
{
	t_Process* temp = proc;
	int i = 0;
	while (temp)
	{
		i++;

		printf("%d Process Id: %d Process: ", i, temp->ProcessID);
		printf("%s\n\n", temp->ProcessName);
		if (temp->ProcessDLLList)
		{
			printDllList(temp->ProcessDLLList);
		}

		temp = temp->next;
	}

}

