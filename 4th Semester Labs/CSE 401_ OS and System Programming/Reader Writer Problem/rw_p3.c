#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

// all semaphores initialised to 1
sem_t resource;           // controls access (read/write) to the resource. Binary semaphore.
sem_t rmutex;             // for syncing changes to shared variable readcount
sem_t serviceQueue;       // FAIRNESS: preserves ordering of requests (signaling must be FIFO)

int count = 0, readercount = 0, writercount = 0;

void *reader(void *id)
{

    int rid = *(int *)id;

    sem_wait(&serviceQueue); /* try to enter the entry section */
    sem_wait(&rmutex);
    readercount++;
    // printf("\nREADER [%d] TRYING\n", rid);
    if (readercount == 1)
        sem_wait(&resource);
    sem_post(&serviceQueue);
    sem_post(&rmutex); /* done with trying to enter the entry section */

    /* do the reading, critical section*/
    printf("Reader [%d] read the value = %d\n", rid + 1, count);

    sem_wait(&rmutex);
    readercount--;
    if (readercount == 0)
        sem_post(&resource);
    sem_post(&rmutex);
}

void *writer(void *id)
{

    int wid = *(int *)id;

    sem_wait(&serviceQueue); /* wait in line to be serviced */
    sem_wait(&resource);
    sem_post(&serviceQueue);

    /* do the writing, critical section */
    count++;
    printf("Writer [%d] updated the value to %d\n", wid, count);
    
    sem_post(&resource);
}

int main()
{

    sem_init(&resource, 0, 1);
    sem_init(&rmutex, 0, 1);
    sem_init(&serviceQueue, 0, 1);

    int size = 10;
    pthread_t rd[size + 6], wr[size + 1];

    for (int i = 0; i < size; i++)
    {
        pthread_create(&rd[i], NULL, reader, (int *)&i);
        pthread_create(&wr[i], NULL, writer, (int *)&i);
    }

    for (int i = 0; i < size; i++)
    {
        pthread_join(rd[i], NULL);
        pthread_join(wr[i], NULL);
    }

    sem_destroy(&resource);
    sem_destroy(&rmutex);
    sem_destroy(&serviceQueue);
}