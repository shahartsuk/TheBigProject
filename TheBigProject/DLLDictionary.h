#pragma once
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <Windows.h>
#include <psapi.h>
#include"Structs.h"
#include"Build SnapShot.h"
#include"LogFile.h"

void searchForAllTheDLLS();
void buildDLLDictionaryList(t_DLL*);
void addNewValue();
void addToDictionary(t_DLLDictionary*, t_Process*);