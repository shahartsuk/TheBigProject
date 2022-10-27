
#include"LogFile.h"
#pragma warning (disable:4996)

char logFileName[1000];

void Log_Init(char fileName[])
{
    sprintf(logFileName, "%s.log", fileName);
}


void LogFile(char message[])
{
    char date[600];

    time_t t;
    time(&t);

    struct tm* timeInfo;

    timeInfo = localtime(&t);

    FILE* f = fopen(logFileName, "a");
    if (!f) {
        LogError(strerror(GetLastError()));
        exit(1);
    }
    sprintf(date, "%d %d %d - %02d:%02d-%s", timeInfo->tm_year + 1900, timeInfo->tm_mon + 1, timeInfo->tm_mday, timeInfo->tm_hour, timeInfo->tm_min,message);
    fputs(date, f);
    fputs("\n", f);

    return 0;
}
void LogError(char message[])
{
    char error[100];
    strcpy(error, "Error-");
    strcat(error, message);
    LogFile(error);
}
void LogEvent(char message[])
{
    char event[100];
    strcpy(event, "Event-");
    strcat(event, message);
    LogFile(event);
}
void LogWarning(char message[])
{
    char event[100];
    strcpy(event, "Warning-");
    strcat(event, message);
    LogFile(event);
}