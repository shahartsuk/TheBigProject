#include"Sorting.h"
#pragma warning (disable:4996)

//buble sort
void sortingProcessList()
{
    t_Process* currProcess = head;

    int change = 1;
    if (!currProcess) {
        return 0;
    }
    while (change != 0)
    {
        change = 0;
            while (currProcess)
            {
                 if (currProcess->next != NULL && currProcess->DLLNumber > currProcess->next->DLLNumber)
                 {
                     ReplaceItem(currProcess);
                     change++;
                 }
                 currProcess = currProcess->next;
            }
         currProcess = head;
    }
}

void ReplaceItem(t_Process* item) 
{

    if (item == NULL)
    {
        return;
    }
    else if (!item->next)
    {
        return;
    }
    else if (item == head && item->next == tail)
    {
        item->next = NULL;
        item->prev = tail;
        tail->prev = NULL;
        tail->next = item;
        tail = item;
        head = item->prev;
    }
    else if (item == head)
    {
        item->next = item->next->next;
        item->next->prev->next = item;
        item->next->prev->prev = NULL;
        item->prev = item->next->prev;
        item->next->prev = item;
        head = item->prev;
    }
    else if (item->next == tail)
    {
        item->prev->next = item->next;
        item->next->prev = item->prev;
        item->next->next = item;
        item->prev = item->next;
        item->next = NULL;
        tail = item;
    }
    else
    {
        item->prev->next = item->next;
        item->next->prev = item->prev;
        item->next->next->prev = item;
        item->prev = item->next;
        item->next = item->next->next;
        item->prev->next = item;
    }
    return;
}
