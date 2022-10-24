#include"GenerateHTML.h" 

void GenerateHTML()
{
	char homeIconStr[5000];
	char aboutMeIconStr[5000];
	char gitIconStr[5000];
	char html[1000];

	strcpy(html, "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"/><meta http-equiv=\"X-UA-Compatible\"content=\"IE=edge\"/><meta name=\"viewport\"content=\"width=device-width, initial-scale=1.0\"/><link rel=\"stylesheet\"href=\"style/styleHome.css\"/><title>Home page</title></head><body><header>");

	strcpy(homeIconStr, "<div class=\"HomeIcon\"><a href=\"C:\\Users\\shaha\\source\\repos\\TheBigProject\\HTML\\HomePage.html\"><svg xmlns=\"http://www.w3.org/2000/svg\"width=\"9em\"height=\"9em\"preserveAspectRatio=\"xMidYMid meet\"viewBox=\"0 0 24 24\"><path fill=\"currentColor\"fill-opacity=\"0\"d=\"M6 8L12 3L18 8V20H6V8Z\"><animate fill=\"freeze\"attributeName=\"fill-opacity\"begin=\"0.9s\"dur=\"0.5s\"values=\"0;1\"/></path><g fill=\"none\"stroke=\"currentColor\"stroke-linecap=\"round\"stroke-linejoin=\"round\" stroke-width=\"2\"><path stroke-dasharray=\"21\"stroke-dashoffset=\"21\"d=\"M5 21H19\"><animate fill=\"freeze\"attributeName=\"stroke-dashoffset\" dur=\"0.2s\"values=\"21;0\"/></path><path stroke-dasharray=\"15\"stroke-dashoffset=\"15\"d=\"M5 21V8M19 21V8\"><animate fill=\"freeze\"attributeName=\"stroke-dashoffset\"begin=\"0.2s\"dur=\"0.2s\"values=\"15;0\"/></path><path stroke-dasharray=\"26\"stroke-dashoffset=\"26\"d=\"M2 10L12 2L22 10\"><animate fill=\"freeze\"attributeName=\"stroke-dashoffset\"begin=\"0.5s\"dur=\"0.4s\"values=\"26;0\"/></path></g></svg></a></div>");

	strcpy(aboutMeIconStr,"<div class=\"MeIcon\"><a href=\"C:\\Users\\shaha\\source\\repos\\TheBigProject\\HTML\\AboutMe.html\"><svg xmlns=\"http://www.w3.org/2000/svg\"width=\"9em\"height=\"9em\"preserveAspectRatio=\"xMidYMid meet\"viewBox=\"0 0 24 24\"><g fill=\"none\"stroke=\"currentColor\"stroke-dasharray=\"28\"stroke-dashoffset=\"28\"stroke-linecap=\"round\"stroke-width=\"2\"><path d=\"M4 21V20C4 16.6863 6.68629 14 10 14H14C17.3137 14 20 16.6863 20 20V21\"><animate fill=\"freeze\"attributeName=\"stroke-dashoffset\"dur=\"0.4s\"values=\"28;0\"/></path><path d=\"M12 11C9.79086 11 8 9.20914 8 7C8 4.79086 9.79086 3 12 3C14.2091 3 16 4.79086 16 7C16 9.20914 14.2091 11 12 11Z\"><animate fill=\"freeze\"attributeName=\"stroke-dashoffset\"begin=\"0.5s\"dur=\"0.4s\"values=\"28;0\"/></path></g></svg></a></div>");

	strcpy(gitIconStr, "<div class=\"GitIcon\"><a target=\"_blank\"href=\"https://github.com/shahartsuk\"><svg xmlns=\"http://www.w3.org/2000/svg\"width=\"9em\"height=\"9em\"preserveAspectRatio=\"xMidYMid meet\"viewBox=\"0 0 24 24\"><g fill=\"none\"stroke=\"currentColor\"stroke-linecap=\"round\"stroke-linejoin=\"round\"stroke-width=\"2\"><path stroke-dasharray=\"30\"stroke-dashoffset=\"30\"d=\"M12 4C13.6683 4 14.6122 4.39991 15 4.5C15.5255 4.07463 16.9375 3 18.5 3C18.8438 4 18.7863 5.21921 18.5 6C19.25 7 19.5 8 19.5 9.5C19.5 11.6875 19.017 13.0822 18 14C16.983 14.9178 15.8887 15.3749 14.5 15.5C15.1506 16.038 15 17.3743 15 18C15 18.7256 15 21 15 21M12 4C10.3317 4 9.38784 4.39991 9 4.5C8.47455 4.07463 7.0625 3 5.5 3C5.15625 4 5.21371 5.21921 5.5 6C4.75 7 4.5 8 4.5 9.5C4.5 11.6875 4.98301 13.0822 6 14C7.01699 14.9178 8.1113 15.3749 9.5 15.5C8.84944 16.038 9 17.3743 9 18C9 18.7256 9 21 9 21\"><animate fill=\"freeze\"attributeName=\"stroke-dashoffset\"dur=\"0.6s\"values=\"30;0\"/></path><path stroke-dasharray=\"10\"stroke-dashoffset=\"10\"d=\"M9 19C7.59375 19 6.15625 18.4375 5.3125 17.8125C4.46875 17.1875 4.21875 16.1562 3 15.5\"><animate fill=\"freeze\"attributeName=\"stroke-dashoffset\"begin=\"0.7s\"dur=\"0.2s\"values=\"10;0\"/></path></g></svg></a></div></header><div class=\"BlackLine\"></div>");

	HomePageHTML(html,aboutMeIconStr, gitIconStr);
	SamplePageHTML(homeIconStr,aboutMeIconStr, gitIconStr);
	DLLDictionaryPageHTML(homeIconStr, aboutMeIconStr, gitIconStr);
	AboutMePageHTML(homeIconStr, gitIconStr);

	DLLCounter = 0;
	ProcessCounter = 0;
}

void HomePageHTML(char html[],char aboutMeIcon[],char gitIcon[])
{
	t_DLLDictionary* dllDictionaryList = DDictionaryHead;
	t_SnapShot* sampleList = Shead;
	t_Process* currProcess=NULL;
	int oneSnapDLLCounter = 0;
	int linkCounter = 1;
	char homeStr[10000];
	FILE* f = fopen("C:\\Users\\shaha\\source\\repos\\TheBigProject\\HTML\\HomePage.html", "w");
	if (!f) {
		LogError(strerror(GetLastError()));
		exit(1);
	}
	sprintf(homeStr, "%s<div class=\"HomeIcon\"><svg xmlns=\"http://www.w3.org/2000/svg\"width=\"9em\"height=\"9em\"preserveAspectRatio=\"xMidYMid meet\"viewBox=\"0 0 24 24\"><path fill=\"currentColor\"fill-opacity=\"0\"d=\"M6 8L12 3L18 8V20H6V8Z\"><animate fill=\"freeze\"attributeName=\"fill-opacity\"begin=\"0.9s\"dur=\"0.5s\"values=\"0;1\"/></path><g fill=\"none\"stroke=\"currentColor\"stroke-linecap=\"round\"stroke-linejoin=\"round\" stroke-width=\"2\"><path stroke-dasharray=\"21\"stroke-dashoffset=\"21\"d=\"M5 21H19\"><animate fill=\"freeze\"attributeName=\"stroke-dashoffset\" dur=\"0.2s\"values=\"21;0\"/></path><path stroke-dasharray=\"15\"stroke-dashoffset=\"15\"d=\"M5 21V8M19 21V8\"><animate fill=\"freeze\"attributeName=\"stroke-dashoffset\"begin=\"0.2s\"dur=\"0.2s\"values=\"15;0\"/></path><path stroke-dasharray=\"26\"stroke-dashoffset=\"26\"d=\"M2 10L12 2L22 10\"><animate fill=\"freeze\"attributeName=\"stroke-dashoffset\"begin=\"0.5s\"dur=\"0.4s\"values=\"26;0\"/></path></g></svg></div><div class=\"Welcome\"><h1>Welcome to the home page</h1></div>%s %s<main><div class=\"LeftInputs\"><input class=\"LeftInput\"placeholder=\"DLL Count:%d\"type=\"text\"/><input class=\"LeftInput\"placeholder=\"Process Count:%d\"type=\"text\"/><input class=\"LeftInput\"placeholder=\"Memory Average:%llu\"type=\"text\"/></div><div class=\"TableContainer\"><div class=\"LeftTable\"><div class=\"Sample\">Samples List</div><table><tr><th>Link</th><th>Process Count</th><th>DLL Count</th><th>Memory Average</th></tr>", html,aboutMeIcon, gitIcon, DLLCounter, ProcessCounter, averageSnapShotMemory());
	fputs(homeStr, f);

	// Builds the table of samples
	while (sampleList)
	{
		// sum all the dll's in the current snapshot
		currProcess = sampleList->process;
		while (currProcess)
		{
			oneSnapDLLCounter += currProcess->DLLNumber;
			currProcess = currProcess->next;
		}
		sprintf(homeStr, "<tr><td><a href=\"C:\\Users\\shaha\\source\\repos\\TheBigProject\\HTML\\SamplePage%d.html\">Sample%d.html</a></td><td>%d</td><td>%d</td><td>%llu</td></tr>", sampleList->sampleNumber,linkCounter,sampleList->processCounter, oneSnapDLLCounter, averageProcessMemory(sampleList));

		oneSnapDLLCounter = 0;
		fputs(homeStr, f);
		linkCounter++;
		sampleList = sampleList->next;
	}
	
	linkCounter = 1;

	strcpy(homeStr, "</table></div><div class=\"RightTable\"><div class=\"DLL\">DLL'S List</div><table><tr><th class=\"DLLName\">DLL Name</th><th>Link</th></tr>");
	fputs(homeStr,f);

	//Constructs the table of a single-valued DLL's
	while (dllDictionaryList)
	{
		sprintf(homeStr, "<tr><td class=\"DLLName\">%s</td><td><a href=\"C:\\Users\\shaha\\source\\repos\\TheBigProject\\HTML\\DLLDictionaryPage%d.html\">DLL%d.html</a></td></tr>", dllDictionaryList->DLLName, linkCounter, linkCounter);

		fputs(homeStr,f);
		dllDictionaryList = dllDictionaryList->next;
		linkCounter++;
	}

	strcpy(homeStr, "</div></table></div></main></body></html>");
	fputs(homeStr, f);

	fclose(f);
}
void SamplePageHTML(char homeIcon[],char aboutMeIcon[], char gitIcon[])
{
	time_t t;
	time(&t);

	struct tm* timeInfo;

	timeInfo = localtime(&t);

	t_SnapShot* sampleList = Shead;
	t_Process* currProcess = NULL;
	t_DLL* currDLL = NULL;
	char sampleStr[5000];
	char fileName[MAX_PATH];
	FILE* f = NULL;

		while (sampleList)
		{
			sprintf(fileName, "C:\\Users\\shaha\\source\\repos\\TheBigProject\\HTML\\SamplePage%d.html", sampleList->sampleNumber);
			f = fopen(fileName, "w");
			if (!f) {
				LogError(strerror(GetLastError()));
				exit(1);
			}
			sprintf(sampleStr, "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"/><meta http-equiv=\"X-UA-Compatible\"content=\"IE=edge\"/><meta name=\"viewport\"content=\"width=device-width,initial-scale=1.0\"/><link rel=\"stylesheet\"href=\"style/stylesample.css\"/><title>Home page/Sample</title></head><body><header>%s<div class=\"Welcome\"><h1>Welcome to the sample page</h1></div>%s %s</header><div class=\"BlackLine\"></div><main><div class=\"SampleDate\"><h1>Sample list number:%dat date%d %d %d-%02d:%02d</h1></div><div class=\"table\"><table class=\"ProcessList\"><tr><th>Process Name</th><th>process ID</th><th>PageFaultCount</th><th>WorkingSetSize</th><th>QuotaPagedPoolUsage</th><th>QuotaPeakPagedPoolUsage</th><th>PageFileUsage</th><th>DLLCount</th><th>Process's DLL List</th></tr>", homeIcon, aboutMeIcon, gitIcon, sampleList->sampleNumber, timeInfo->tm_year + 1900, timeInfo->tm_mon + 1, timeInfo->tm_mday, timeInfo->tm_hour, timeInfo->tm_min);
			fputs(sampleStr, f);

			currProcess = sampleList->process;
			while (currProcess)
			{
				currDLL = currProcess->ProcessDLLList;

				sprintf(sampleStr,"<tr><td class=\"ProcessName\">%s</td><td>%d</td><td>%lu</td><td>%llu</td><td>%llu</td><td>%llu</td><td>%llu</td><td>%d</td><td><select><option value=\"list\">List</option>",currProcess->ProcessName,currProcess->ProcessID, currProcess->pmc.PageFaultCount, currProcess->pmc.WorkingSetSize, currProcess->pmc.QuotaPagedPoolUsage, currProcess->pmc.QuotaPeakPagedPoolUsage, currProcess->pmc.PagefileUsage, currProcess->DLLNumber);
				fputs(sampleStr, f);

				//write the dllList in the table
				while (currDLL)
				{
					sprintf(sampleStr, "<option value=\"list\">%s</option>", currDLL->DLLName);
					fputs(sampleStr,f);
					currDLL = currDLL->next;
				}

				strcpy(sampleStr, "</select></td></tr>");
				fputs(sampleStr, f);

				currProcess = currProcess->next;
			}
			strcpy(sampleStr, "</table></div></main></body></html>");
			fputs(sampleStr, f);


			fclose(f);
			sampleList = sampleList->next;
		}

}
void DLLDictionaryPageHTML(char homeIcon[], char aboutMeIcon[], char gitIcon[])
{
	t_DLLDictionary* dllDictionaryList = DDictionaryHead;
	t_Process* dllProcessList = NULL;
	int processCounter = 0;
	char dllStr[5000];
	char fileName[MAX_PATH];
	FILE* f = NULL;
	int dllNumber = 1;
	
	while (dllDictionaryList)
	{
		dllProcessList = dllDictionaryList->ProcessList;
		while (dllProcessList)
		{
			processCounter++;
			dllProcessList = dllProcessList->next;
		}
		sprintf(fileName, "C:\\Users\\shaha\\source\\repos\\TheBigProject\\HTML\\DLLDictionaryPage%d.html", dllNumber);
		f = fopen(fileName, "w");
		if (!f) {
			LogError(strerror(GetLastError()));
			exit(1);
		}
		sprintf(dllStr, "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"/><meta http-equiv=\"X-UA-Compatible\"content=\"IE=edge\"/><meta name=\"viewport\"content=\"width=device-width,initial-scale=1.0\"/><link rel=\"stylesheet\"href=\"style/DllDictionary.css\"/><title>Home page\DLL process list</title></head><body><header>%s<div class=\"Welcome\"><h1>DLL'S Processes List</h1></div>%s %s</header><div class=\"BlackLine\"></div><main><div class=\"DLLName\"><h1>%d Processes used %s</h1></div><table class=\"ProcessList\"><tr><th class=\"ProcessName\">Process Name</th><th>process ID</ th><th>PageFaultCount</th><th>WorkingSetSize</th><th>QuotaPagedPoolUsage</th><th>QuotaPeakPagedPoolUsage</th><th>PageFileUsage</th></tr>", homeIcon, aboutMeIcon, gitIcon, processCounter,dllDictionaryList->DLLName);
		fputs(dllStr, f);

		dllProcessList = dllDictionaryList->ProcessList;
		while (dllProcessList)
		{
			sprintf(dllStr,"<tr><td class=\"ProcessName\">%s</td><td>%d</td><td>%lu</td><td>%llu</td><td>%llu</td><td>%llu</td><td>%llu</td></tr>", dllProcessList->ProcessName, dllProcessList->ProcessID, dllProcessList->pmc.PageFaultCount, dllProcessList->pmc.WorkingSetSize, dllProcessList->pmc.QuotaPagedPoolUsage, dllProcessList->pmc.QuotaPeakPagedPoolUsage, dllProcessList->pmc.PagefileUsage);
			fputs(dllStr, f);

			dllProcessList = dllProcessList->next;
		}
		dllDictionaryList = dllDictionaryList->next;
		dllNumber++;
		processCounter = 0;

		strcpy(dllStr, "</table></main></body></html>");
		fputs(dllStr, f);

		fclose(f);
	}
}
void AboutMePageHTML(char homeIcon[], char gitIcon[])
{
	FILE* f = fopen("C:\\Users\\shaha\\source\\repos\\TheBigProject\\HTML\\AboutMePage.html", "w");
	if (!f) {
		LogError(strerror(GetLastError()));
		exit(1);
	}
	fclose(f);
}