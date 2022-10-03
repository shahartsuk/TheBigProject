#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <Windows.h>
#include <psapi.h>
#include"BuildSnapshot.h"
#include"LogFile.h"
#pragma warning (disable:4996)

int main()
{
    char strFileName[1000];
    strcpy(strFileName, "TheBigProjectFileLog");
    Log_Init(strFileName);
    LogEvent("System Is Starting");
   /* char userResponses = NULL;
    while (userResponses != 'Q')
    {
        printf("dear user,there is options for you to build your dictionary:\n1. A-Take one snapshot\n2. B-Take 20 snapshots\n3. L-Start long snapshot\n4. E-End long snapshot\n5. G-Generate HTML report\n6. R-Reset collection\n7. S-Save in file\n8. Q-Quit\n");
        scanf(" %c", &userResponses);
        switch (userResponses)
        {
        case 'A':
            break;
        case 'B':
            break;
        case 'L':
            break;
        case 'E':
            break;
        case 'G':
            break;
        case 'R':
            break;
        case 'S':
            break;
        default:
            printf("wrong selection, pls be more sharp");
            break;
        }
    }*/

   GetProcessInfo();
   LogEvent("System Is Ending");
}
