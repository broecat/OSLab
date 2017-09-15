/* Sample program to handle system signals */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>


void * sigintHandle(int myint)
{
   printf("\nSignal Handled!! SIGINT\n\n");
   exit(0);
}

void * sigtermHandle(int myint)
{
   printf("\nSignal Handled!! SIGTERM\n\n");
   exit(0);
}
void * sigquitHandle(int myint)
{
   printf("\nSignal Handled!! SIGQUIT\n\n");
   exit(0);
}
void * sigfpeHandle(int myint)
{
   printf("\nSignal Handled!! SIGFPE\n\n");
   printf("\nNow, the program will make the SIGFPE occur programmatically.");
   
   int a = 10/0;
   
   exit(0);
}
void * sigsegvHandle(int myint)
{
   printf("\nSignal Handled!! SIGSEGV\n\n");
   printf("\nNow, the program will make the SIGSEGV occur programmatically.");
   
   int arr[5];
   arr[10] = 12;

   exit(0);
}
void * sigillHandle(int myint)
{
   printf("\nSignal Handled!! SIGILL\n\n");

   exit(0);
}


int main()
{
   signal( SIGINT, (void *)  sigintHandle );
   signal( SIGQUIT, (void *)  sigquitHandle );
   signal( SIGTERM, (void *)  sigtermHandle );
   signal( SIGFPE, (void *)  sigfpeHandle );
   signal( SIGSEGV, (void *)  sigsegvHandle );
   signal( SIGILL, (void *)  sigillHandle );
   signal( SIGBUS, SIG_IGN);
   raise(SIGILL);
   while(1) {
	printf("Doing Nothing...\n");
	sleep(1);
   }
}
