#include <stdio.h>
#include <stdio.h> 
#include <stdlib.h>
#include <windows.h>

DWORD WINAPI threadfunc1(void* data);
DWORD WINAPI threadfunc2(void* data);
DWORD WINAPI threadfunc3(void* data);


DWORD WINAPI threadfunc1(void* data)
{
	for (int i = 0; i < 100; i++)
	{
		printf("%s", (char*)data);
		printf("i = %d\n", i);
	}
	return 0;
}

DWORD WINAPI threadfunc2(void* data)
{
	for (int i = 10000; i < 11000; i += 10)
	{
		printf("%s", (char*)data);
		printf("i = %d\n", i);
	}
	return 0;
}

DWORD WINAPI threadfunc3(void*)
{
	printf("µÈ´ý½áÊø");
	return 0;
}

int main()
{
	DWORD threadId[3];
	HANDLE th[2];
	HANDLE th2;
	const char* a = "hello";
	int cnt = 0;

	th[cnt++] = CreateThread(NULL, 0, &threadfunc1, (void *)a, 0, &threadId[0]);

	th[cnt++] = CreateThread(NULL, 0, &threadfunc2, (void*)a, 0, &threadId[1]);

	WaitForMultipleObjects(2,th,true, INFINITE);

	th2 = CreateThread(NULL, 0, &threadfunc3, 0, 0, &threadId[2]);

	WaitForSingleObject(th2, INFINITE);

	for (int i = 0; i < cnt; i++)
		CloseHandle(th[i]);
	CloseHandle(th2);
	return 0;
}

