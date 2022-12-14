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
#include"SnapShotFile.h"
#pragma warning (disable:4996)

void EnterSnapShotListToFile()
{
	int write = 0;
	t_headerOfFile headerFile;

	t_SnapShot* snapShotList = Shead;

	t_Process* processList = NULL;

	t_DLL* dllList =NULL;

	FILE* f = fopen("C:\\Users\\97254\\source\\repos\\TheBigProject\\SnapShotFolder\\SnapShotFile.bin", "wb");
	if (!f)
	{
		LogError(strerror(GetLastError()));
		exit(1);
	}

	headerFile.ItemsCount = 0;
	headerFile.version = 1;


	while (snapShotList)
	{
		headerFile.ItemsCount++;
		snapShotList = snapShotList->next;
	}
	snapShotList = Shead;

	write = fwrite(&headerFile, sizeof(t_headerOfFile), 1, f);

	while (snapShotList)
	{
		write = fwrite(snapShotList, sizeof(t_SnapShot), 1, f);
		processList = snapShotList->process;
		while (processList)
		{
			write = fwrite(processList, sizeof(t_Process), 1, f);
			dllList = processList->ProcessDLLList;
			while (dllList)
			{
				write = fwrite(dllList, sizeof(t_DLL), 1, f);
				dllList = dllList->next;
			}
			processList = processList->next;
		}
		snapShotList = snapShotList->next;
	}

	fclose(f);
	return;
}

void UploadSnapShotListFromFile()
{
	int read = 0;
	t_headerOfFile headerFile;

	t_SnapShot* currSnapShot = NULL;

	t_Process* currProcess = NULL;

	t_DLL* currDLL = NULL;


	FILE* f = fopen("C:\\Users\\97254\\source\\repos\\TheBigProject\\SnapShotFolder\\SnapShotFile.bin", "rb");
	if (!f)
	{
		LogError(strerror(GetLastError()));
		// If the file is accidentally deleted
		printf("No file found");
		return;
	}

	read = fread(&headerFile, sizeof(t_headerOfFile), 1, f);

	// ItemsCount is the number of the snapshots
	for (int i = 0; i < headerFile.ItemsCount; i++)
	{
		currSnapShot = (t_SnapShot*)malloc(sizeof(t_SnapShot));
		if (!currSnapShot)
		{
			LogError(strerror(GetLastError()));
			exit(1);
		}
			read = fread(currSnapShot, sizeof(t_SnapShot), 1, f);
			for (int p = 0; p < currSnapShot->processCounter; p++)
			{
				currProcess = (t_Process*)malloc(sizeof(t_Process));
				if (!currProcess)
				{
					LogError(strerror(GetLastError()));
					exit(1);
				}
				read = fread(currProcess, sizeof(t_Process), 1, f);

				for (int d = 0; d < currProcess->DLLNumber; d++)
				{
					currDLL = (t_DLL*)malloc(sizeof(t_DLL));
					if (!currDLL)
					{
						LogError(strerror(GetLastError()));
						exit(1);
					}
					read = fread(currDLL, sizeof(t_DLL), 1, f);
					buildDllList(currDLL->DLLName);
				}
				currProcess->ProcessDLLList = Dhead;
				buildProcessList(currProcess);
			}
			currSnapShot->process = head;
			buildSnapShotList(currSnapShot);
	}
	fclose(f);
}
