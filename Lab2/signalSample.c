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


int main()
{
   signal( SIGINT, (void *)  sigintHandle );
   signal( SIGTERM, (void *)  sigtermHandle );
   while(1) {
	printf("Doing Nothing...\n");
	sleep(1);
   }
}
