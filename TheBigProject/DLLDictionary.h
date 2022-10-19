#pragma once
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
#include"averageProcessMemory.h"

extern t_DLLDictionary* DDictionaryHead;
extern t_DLLDictionary* DDictionaryTail;

extern t_PDictionary* PDictionaryHead;
extern t_PDictionary* PDictionaryTail;

extern int DLLCounter;
extern int ProcessCounter;

void searchForAllTheDLLS();
void buildDLLDictionaryList(t_DLL*);
void addNewValue();
void addToDictionary(t_DLLDictionary*, t_Process*);
void buildProcessDictionaryList(t_Process*);