#include <stdio.h>
#include <Windows.h>

#define HECTONANO_TO_MILI 10000

void printDiff(SYSTEMTIME start, SYSTEMTIME stop){
	FILETIME fstart, fstop;
	SystemTimeToFileTime(&start, &fstart);
	SystemTimeToFileTime(&stop, &fstop);

	ULARGE_INTEGER ulstart, ulstop;
	ulstart.LowPart = fstart.dwLowDateTime;
	ulstart.HighPart = fstart.dwHighDateTime;
	ulstop.LowPart = fstop.dwLowDateTime;
	ulstop.HighPart = fstop.dwHighDateTime;
	printf("ms: %d\n", (ulstop.QuadPart - ulstart.QuadPart) / HECTONANO_TO_MILI);
}

int main(void) {
	printf("Aufgabe 04:\n");
	printf("===========\n");
	SetLastError(ERROR_FILE_NOT_FOUND);
	char * message;
	FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER, 0, GetLastError(), 0, &message, 0, 0);
	printf("Error: %s", message);
	getchar();

	printf("Aufgabe 05:\n");
	printf("===========\n");
	SYSTEMTIME start, stop;
	//1.
	GetSystemTime(&start);
	Sleep(30);
	GetSystemTime(&stop);
	printDiff(start, stop);
	//2.
	GetSystemTime(&start);
	for (int i = 0; i < 100; ++i){
		Sleep(10);
	}
	GetSystemTime(&stop);
	printDiff(start, stop);
	getchar();
}