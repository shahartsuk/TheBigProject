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
#include"MemoryFree.h"
#include"DLLDictionary.h"
#pragma warning (disable:4996)


void releaseProcessList() {
	t_Process* freeTheList;
	while (head) {
		freeTheList = head;
		head = head->next;
		free(freeTheList);
	}
	head = tail = NULL;
}

void releaseSnapShotList()
{
	t_SnapShot* freeTheList;
	while (Shead) {
		freeTheList = Shead;
		Shead = Shead->next;
		free(freeTheList);
	}
	Shead = Stail = NULL;
	sampleCounter = 0;
	releaseProcessList();
	releaseDLLList();
}
void releaseDLLList()
{
	t_DLL* freeTheList;
	while (Dhead) {
		freeTheList = Dhead;
		Dhead = Dhead->next;
		free(freeTheList);
	}
	Dhead = Dtail = NULL;
}

void releaseDLLDictionaryList()
{
	t_DLLDictionary* freeTheList;
	while (DDictionaryHead) {
		freeTheList = DDictionaryHead;
		DDictionaryHead = DDictionaryHead->next;
		free(freeTheList);
	}
	DDictionaryHead = DDictionaryTail = NULL;
}