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

unsigned long long averageProcessMemory(t_SnapShot*);
unsigned long long averageSnapShotMemory();