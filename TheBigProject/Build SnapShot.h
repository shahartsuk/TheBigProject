#pragma once
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <Windows.h>
#include <psapi.h>
#include <time.h>
#include"Structs.h"
#include"LogFile.h"
#include"Build ProcessList.h"
#include"Sorting.h"

extern t_SnapShot* Shead;
extern t_SnapShot* Stail;

extern int sampleCounter;

t_SnapShot* OneSnapShot();
void TwentySnapShots();

void buildSnapShotList(t_SnapShot*);

void printTheList();

void printDllList(t_DLL*);
void printProcessList(t_Process*);
