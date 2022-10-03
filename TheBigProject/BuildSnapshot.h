#pragma once
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <Windows.h>
#include <psapi.h>


void ProcessMemoryInfo(DWORD processID);

// GetProcessInfo() this function call ProcessMemoryInfo
void GetProcessInfo();