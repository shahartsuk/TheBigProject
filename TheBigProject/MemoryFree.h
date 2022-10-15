#pragma once
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <Windows.h>
#include <psapi.h>
#include"Structs.h"

void releaseProcessList();
void releaseSnapShotList();
void releaseDLLList();
void releaseDLLDictionaryList();