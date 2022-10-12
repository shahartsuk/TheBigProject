#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <Windows.h>
#include <psapi.h>
#include"Build SnapShot.h"
#include"Build ProcessList.h"
#include"LogFile.h"
#include"LongSnapShot.h"
#include"DLLDictionary.h"
#pragma warning (disable:4996)

int main()
{
    char strFileName[1000];
    char strEvents[1000];
    strcpy(strFileName, "TheBigProjectFileLog");
   // Log_Init(strFileName);
    //strcpy(strEvents, "System Is Starting");
    //LogEvent(strEvents);

    char userResponses = NULL;
    while (userResponses != 'Q')
    {
        printf("Dear user,there is options for you to build your dictionary:\n1. A-Take one snapshot\n2. B-Take 20 snapshots\n3. L-Start long snapshot\n4. G-Generate HTML report\n5. R-Reset collection\n6. S-Save in file\n7. Q-Quit\n");
        scanf(" %c", &userResponses);
        switch (userResponses)
        {
        case 'A':
           // strcpy(strEvents, "Taking one snapshot");
           // LogEvent(strEvents);
            OneSnapShot();
            buildSnapShotList(OneSnapShot());
            head = tail = NULL;
            Dhead = Dtail = NULL;
            break;
             case 'B':
                 strcpy(strEvents, "Taking twenty snapshots");
                 //LogEvent(strEvents);
                 TwentySnapShots();
            break;
            case 'L':
                LongSnapShot();
            break;
        case 'G':       
            if (!Shead)
            {
                printf("There no SnapShots in the list plas try other options");
            }
            else
            {
                searchForAllTheDLLS();
            }
            break;
            /* 
        case 'R':
        releaseSnapShotList();
            break;
        case 'S':
            break;*/
            case 'Q':
                releaseSnapShotList();
                break; 
        default:
            printf("wrong selection, pls be more sharp");
            break;
        }
    }

   GetProcessInfo();
   LogEvent("System Is Ending");
}
