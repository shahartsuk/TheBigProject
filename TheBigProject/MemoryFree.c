
#include"MemoryFree.h"
#pragma warning (disable:4996)

// deletes one snapshot
void resetSnapShot(t_SnapShot* snapShotList) { 
	t_SnapShot* currentSnapShot;
	t_Process* currentPorcess;
	t_DLL* currentDLL;

	currentSnapShot = snapShotList;
	while (snapShotList->process)
	{
		currentPorcess = snapShotList->process;
		while (snapShotList->process->ProcessDLLList)
		{
			currentDLL = snapShotList->process->ProcessDLLList;
			snapShotList->process->ProcessDLLList = snapShotList->process->ProcessDLLList->next;
			free(currentDLL);
		}
		snapShotList->process->ProcessDLLList = NULL;
		snapShotList->process = snapShotList->process->next;
		free(currentPorcess);
	}
	snapShotList->process = NULL;
	free(currentSnapShot);
	snapShotList = NULL;
}

void releaseTheCollection() { // deletes all list
	t_SnapShot* currentSnapShot;
	t_Process* currentPorcess;
	t_DLL* currentDLL;
	currentSnapShot = Shead;
	while (Shead)
	{
		currentSnapShot = Shead;
		while (Shead->process)
		{
			currentPorcess = Shead->process;
			while (Shead->process->ProcessDLLList)
			{
				currentDLL = Shead->process->ProcessDLLList;
				Shead->process->ProcessDLLList = Shead->process->ProcessDLLList->next;
				free(currentDLL);
			}
			Shead->process->ProcessDLLList = NULL;
			Shead->process = Shead->process->next;
			free(currentPorcess);
		}
		Shead->process = NULL;
		Shead = Shead->next;
		free(currentSnapShot);
	}
	releaseDLLDictionaryList();
	releaseProcessDictionaryList();
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

void releaseProcessDictionaryList()
{
	t_PDictionary* freeTheList;
	while (DDictionaryHead) {
		freeTheList = PDictionaryHead;
		PDictionaryHead = PDictionaryHead->next;
		free(freeTheList);
	}
	PDictionaryHead = PDictionaryTail = NULL;
}