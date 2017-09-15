/* Sample program to handle system signals */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>


void * signalHandle(int sig)
{
    switch(sig){
        case SIGINT:
            printf("\nSignal Handled!! SIGINT\n\n");
            break;
        case SIGTERM:
            printf("\nSignal Handled!! SIGTERM\n\n");
            break;
        case SIGQUIT:
            printf("\nSignal Handled!! SIGQUIT\n\n");
            break;
        case SIGFPE:
            printf("\nSignal Handled!! SIGFPE\n\n");
            printf("\nNow, the program will make the SIGFPE occur programmatically.");
            int a = 10/0;
            break;
        case SIGSEGV:
            printf("\nSignal Handled!! SIGSEGV\n\n");
            printf("\nNow, the program will make the SIGSEGV occur programmatically.");
        
            int arr[5];
            arr[10] = 12;
        case SIGILL:
            printf("\nSignal Handled!! SIGILL\n\n");
            break;
    }
   
   exit(0);
}


int main()
{
   printf("PID: %d",getpid());
   signal( SIGINT, (void (*) (int))  signalHandle );
   signal( SIGQUIT, (void (*) (int))  signalHandle );
   signal( SIGTERM, (void (*) (int))  signalHandle );
   signal( SIGFPE, (void (*) (int))  signalHandle );
   signal( SIGSEGV, (void (*) (int))  signalHandle );
   signal( SIGILL, (void (*) (int))  signalHandle );
   signal( SIGBUS, SIG_IGN);
   //Uncomment to raise SIGILL
   //raise(SIGILL);
   while(1) {
	printf("Doing Nothing...\n");
	sleep(1);
   }
}
