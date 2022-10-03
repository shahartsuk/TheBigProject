#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#include"LogFile.h"
#pragma warning (disable:4996)

char logFileName[1000];

void Log_Init(char fileName[1000])
{
    sprintf(logFileName, "%s.log", fileName);
}


void LogFile(char message[1000])
{
    char date[100];

    time_t t;
    time(&t);

    struct tm* timeinfo;

    timeinfo = localtime(&t);

    FILE* f = fopen(logFileName, "a");
    if (!f) {
        printf("error1");
        exit(1);
    }
    sprintf(date, "sec%d.min%d.hour%d.day%d.mounth%d.year%d-%s", timeinfo->tm_sec, timeinfo->tm_min, timeinfo->tm_hour, timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year % 100, message);
    fputs(date, f);
    fputs("\n", f);

    return 0;
}
void LogError(char message[1000])
{
    char error[100];
    strcpy(error, "Error-");
    strcat(error, message);
    LogFile(error);
}
void LogEvent(char message[100])
{
    char event[100];
    strcpy(event, "Event-");
    strcat(event, message);
    LogFile(event);
}
void LogWarning(char message[100])
{
    char event[100];
    strcpy(event, "Warning-");
    strcat(event, message);
    LogFile(event);
}