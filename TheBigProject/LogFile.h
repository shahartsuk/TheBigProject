#pragma once
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#include <Windows.h>
extern char logFileName[1000];
void Log_Init(char[]);
// file name include .log
void LogFile(char[]);
void LogError(char[]);
void LogEvent(char[]);
void LogWarning(char[]);