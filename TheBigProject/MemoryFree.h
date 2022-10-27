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
#include"Build SnapShot.h"
#include"DLLDictionary.h"

void releaseTheCollection();
void resetSnapShot(t_SnapShot*);
void releaseDLLDictionaryList();
void releaseProcessDictionaryList();