#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 20

//int count = 0;
int in = 0;
int out = 0;
int buffer [BUFFER_SIZE];

sem_t clients,barber,chair;
int chairsAvailable;


pthread_t tid;

void * barberThread(void * param){
    int clientCount=1;
    while(1){
      sem_wait(&clients); //Sleep while waiting for clients
      printf("Serving client: %d\n",clientCount++);
      sem_wait(&chair);   //chair semaphore for chairsAvailable critical section
      chairsAvailable++;  //done with the haircut
      sem_post(&barber);  //signal clients barber is ready
      sem_post(&chair);   //Allow clients to sit in chair
   }
}

void * clientThread(void * param){
   	sem_wait(&chair);
	if(chairsAvailable>0)
	{
		chairsAvailable--;
		sem_post(&clients);
		sem_post(&chair);
		sem_wait(&barber);
	}
	else
		sem_post(&chair);
}

int main(int argc, char * argv[])
{
    int numOfclients = atoi(argv[1]);
    chairsAvailable = atoi(argv[2]);

    int i;

    sem_init(&clients, i, 0);
    sem_init(&barber, i , 0);
    sem_init(&chair, i, 1);
    
    printf("Chairs available: %d\n",chairsAvailable);
    printf("Clients:	  %d\n",numOfclients);

    pthread_create(&tid, NULL, barberThread,NULL);

    for (i = 0; i < numOfclients; i++)
       pthread_create(&tid, NULL, clientThread, NULL); 
 
    pthread_join(tid,NULL);
}

