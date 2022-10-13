#pragma once
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <Windows.h>
#include <psapi.h>
#include"Structs.h"
#include"Build SnapShot.h"
#include"LogFile.h"
#include"DLLDictionary.h"

extern unsigned long long avarage1SnapShot;
extern unsigned long long avarageAllSnapShots;

long averageProcessMemory( t_SnapShot*);