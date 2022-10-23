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
#include"MemoryFree.h"
#pragma warning (disable:4996)

void GenerateHTML();

void HomePageHTML(char[], char[], char[]);
void SamplePageHTML(char[], char[], char[]);
void DLLDictionaryPageHTML(char[], char[], char[]);
void AboutMePageHTML(char[], char[]);