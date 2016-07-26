#include <stdio.h>
#include <process.h>
#include <windows.h>

int mutex = 0;
HANDLE   hMutex;

DWORD WINAPI  thread1()
{
	
	while(1)
	{
		WaitForSingleObject(hMutex, INFINITE);
        mutex += 1;
		printf("%d\n",mutex );
		sleep(1);
   	    ReleaseMutex(hMutex);
	}
	return 0;
}
DWORD WINAPI thread2()
{  
	while(1)
	{
	      WaitForSingleObject(hMutex, INFINITE);
		  mutex += 2;
		  printf("%d\n",mutex );
		  sleep(1);
		  ReleaseMutex(hMutex);
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	 hMutex = CreateMutex(NULL, FALSE, NULL);
	 HANDLE h1 = CreateThread(NULL, 0, thread1, NULL, 0, NULL);  
     HANDLE h2 = CreateThread(NULL, 0, thread2, NULL, 0, NULL);
     WaitForSingleObject(h1, INFINITE);
     WaitForSingleObject(h2, INFINITE);
     CloseHandle(h1);
     CloseHandle(h2);
	/* code */
	return 0;
}