#include <stdio.h>
#include <process.h>
#include <windows.h>

DWORD WINAPI  thread1()
{
	while(1)
	{
		printf("I'm first\n" );
		sleep(1);
	}
	
	return 0;
}
DWORD WINAPI thread2()
{
	while(1)
	{
	  printf("I'm second\n");
	  sleep(1);
	}
	return 0;
}

int main ()
{
   HANDLE h1 = CreateThread(NULL, 0, thread1, NULL, 0, NULL);  
   HANDLE h2 = CreateThread(NULL, 0, thread2, NULL, 0, NULL);
   WaitForSingleObject(h1, INFINITE);
   WaitForSingleObject(h2, INFINITE);
   CloseHandle(h1);
   CloseHandle(h2);
   return 0;
}
