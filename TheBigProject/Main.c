#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#include <Windows.h>
#include <psapi.h>
#include"Build SnapShot.h"
#include"Build ProcessList.h"
#include"LogFile.h"
#include"LongSnapShot.h"
#include"DLLDictionary.h"
#include"SnapShotFile.h"
#include"MemoryFree.h"
#pragma warning (disable:4996)

int main()
{
    char strFileName[1000];
    char strEvents[1000];
    time_t t;
    time(&t);

    struct tm* timeInfo;

    timeInfo = localtime(&t);
    sprintf(strFileName, "C:\\Users\\shaha\\source\\repos\\TheBigProject\\LogFiles\\FileLog %d %d %d - %02d:%02d-%s", timeInfo->tm_year + 1900, timeInfo->tm_mon + 1, timeInfo->tm_mday, timeInfo->tm_hour, timeInfo->tm_min);
    Log_Init(strFileName);
    strcpy(strEvents, "System Is Starting");
    LogEvent(strEvents);

    char userResponses = NULL;
    while (userResponses != 'Q')
    {
        printf("Dear user,there is options for you to build your dictionary:\n1. A-Take one snapshot\n2. B-Take 20 snapshots\n3. L-Start long snapshot\n4. G-Generate HTML report\n5. R-Reset collection\n6. S-Save in file\n7. C-Upload from File\n8. Q-Quit\n");
        scanf(" %c", &userResponses);
        switch (userResponses)
        {
        case 'A':
            sprintf(strFileName, "C:\\Users\\shaha\\source\\repos\\TheBigProject\\LogFiles\\FileLog %d %d %d - %02d:%02d-%s", timeInfo->tm_year + 1900, timeInfo->tm_mon + 1, timeInfo->tm_mday, timeInfo->tm_hour, timeInfo->tm_min);
           strcpy(strEvents, "Taking one snapshot");
           LogEvent(strEvents);
            OneSnapShot();
            buildSnapShotList(OneSnapShot());
            head = tail = NULL;
            Dhead = Dtail = NULL;
            strcpy(strEvents, "One snapshot had finished");
            break;
             case 'B':
                 sprintf(strFileName, "C:\\Users\\shaha\\source\\repos\\TheBigProject\\LogFiles\\FileLog %d %d %d - %02d:%02d-%s", timeInfo->tm_year + 1900, timeInfo->tm_mon + 1, timeInfo->tm_mday, timeInfo->tm_hour, timeInfo->tm_min);
                 printf("Please wait for twenty seconds");
                 strcpy(strEvents, "Taking twenty snapshots");
                 LogEvent(strEvents);
                 TwentySnapShots();
                 head = tail = NULL;
                 Dhead = Dtail = NULL;
                 strcpy(strEvents, "Twenty snapshots had finished");
            break;
            case 'L':
                sprintf(strFileName, "C:\\Users\\shaha\\source\\repos\\TheBigProject\\LogFiles\\FileLog %d %d %d - %02d:%02d-%s", timeInfo->tm_year + 1900, timeInfo->tm_mon + 1, timeInfo->tm_mday, timeInfo->tm_hour, timeInfo->tm_min);
                strcpy(strEvents, "Taking long snapshot");
                LogEvent(strEvents);
                LongSnapShot();
                strcpy(strEvents, "Long snapshot had finished");
            break;
        case 'G':       
            if (!Shead)
            {
                printf("There is no SnapShots in the list pleas try other options");
            }
            else
            {
                sprintf(strFileName, "C:\\Users\\shaha\\source\\repos\\TheBigProject\\LogFiles\\FileLog %d %d %d - %02d:%02d-%s", timeInfo->tm_year + 1900, timeInfo->tm_mon + 1, timeInfo->tm_mday, timeInfo->tm_hour, timeInfo->tm_min);
                strcpy(strEvents, "Starting to build DLL Dictionary");
                LogEvent(strEvents);
                searchForAllTheDLLS();
                strcpy(strEvents, "Done building DLL Dictionary");
            }
            break;
         case 'R':
         releaseSnapShotList();
             break;
         case 'S':
            if (!Shead)
            {
                printf("There is no SnapShots in the list pleas try other options");
            }
            else
            {
                sprintf(strFileName, "C:\\Users\\shaha\\source\\repos\\TheBigProject\\LogFiles\\FileLog %d %d %d - %02d:%02d-%s", timeInfo->tm_year + 1900, timeInfo->tm_mon + 1, timeInfo->tm_mday, timeInfo->tm_hour, timeInfo->tm_min);
                strcpy(strEvents, "Starting to enter snapshot list to file");
                LogEvent(strEvents);
                EnterSnapShotListToFile();
                strcpy(strEvents, "Done entering snapshot list to file");
            }
            break;
         case 'U':
             if (!Shead)
             {
                 printf("There is no SnapShots in the list pleas try other options");
             }
             else
             {
                 sprintf(strFileName, "C:\\Users\\shaha\\source\\repos\\TheBigProject\\LogFiles\\FileLog %d %d %d - %02d:%02d-%s", timeInfo->tm_year + 1900, timeInfo->tm_mon + 1, timeInfo->tm_mday, timeInfo->tm_hour, timeInfo->tm_min);
                 strcpy(strEvents, "Starting to upload snapshot list from file");
                 LogEvent(strEvents);
                 UploadSnapShotListFromFile();
                 strcpy(strEvents, "Done uploading snapshot list from file");
             }
             break;
            case 'Q':
                sprintf(strFileName, "C:\\Users\\shaha\\source\\repos\\TheBigProject\\LogFiles\\FileLog %d %d %d - %02d:%02d-%s", timeInfo->tm_year + 1900, timeInfo->tm_mon + 1, timeInfo->tm_mday, timeInfo->tm_hour, timeInfo->tm_min);
                strcpy(strEvents, "Starting to delet snapshot list");
                LogEvent(strEvents);
                releaseSnapShotList();
                strcpy(strEvents, "Done deleting snapshot list");
                break; 
        default:
            printf("wrong selection, pls be more sharp");
            break;
        }
    }

   GetProcessInfo();
   LogEvent("System Is Ending");
}
