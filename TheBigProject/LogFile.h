void Log_Init(char fileName[1000]);
// file name include .log
void LogFile(char message[1000]);
void LogError(char message[1000]);
void LogEvent(char message[100]);
void LogWarning(char message[100]);
extern char logFileName[1000];