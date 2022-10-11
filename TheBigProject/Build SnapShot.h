#pragma once
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <Windows.h>
#include <psapi.h>
#include"Structs.h"

extern t_SnapShot* Shead;
extern t_SnapShot* Stail;

extern t_SnapShot* firstSnapShot;
extern t_SnapShot* fullSnapShot;

extern int sampleCounter;

t_SnapShot* OneSnapShot();
void TwentySnapShots();

void buildSnapShotList(t_SnapShot*);

void releaseProcessList();
void releaseSnapShotList();
void printTheList();
void releaseDLLList();

