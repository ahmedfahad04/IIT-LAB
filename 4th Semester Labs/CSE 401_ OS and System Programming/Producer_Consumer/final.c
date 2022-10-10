#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define Thread_Count 5
#define BUFFER_SIZE 10

pthread_mutex_t mutex;
sem_t semBufferEmpty;
sem_t semBufferFull;

int count = 0, buffer[BUFFER_SIZE];

void *producer()
{
    while (1)
    {
        // produce
        int x = rand() % 100;
        sleep(1);
        
        /* Here we solved the "MANY CASES ARE IGNORE AS BUFFER IS FULL"
        problem by using SEMAPHORES. When we try to put element of 
        buffer we check through semaphore is actually any empty slots
        avaiable or not by using semaphores.*/

        sem_wait(&semBufferEmpty);  // if there is at least one empty slot then enter
        pthread_mutex_lock(&mutex);

        if(count < 10){
        // store in buffer
            buffer[count] = x;
            count++;
        } else {
            printf("Skipped %d, Count: %d\n", x, count);
        }

        pthread_mutex_unlock(&mutex);   
        sem_post(&semBufferFull);   // it will increment sem_t value and will occupy one slot
    }
}

void *consumer()
{

    while (1)
    {
        int y = -1;

        // retrieve from buffer

        /* We also solved "CPU CYCLE WASTE DUE TO EMPTY BUFFER"
        problem through SEMAPHORES. It will check each cases whether
        we have at least one element to access in buffer otherwise 
        we won't fetch buffer value.
        */
        sem_wait(&semBufferFull);  // means we'll access the buffer if there is at least one element
        pthread_mutex_lock(&mutex);
        
        if (count > 0)
        {
            y = buffer[count - 1];
            count--;
        }

        pthread_mutex_unlock(&mutex);
        sem_post(&semBufferEmpty);   // it will decrement sem_t value and will release one slot

        // consume
        printf("\nGET %d, COUNT: %d", y, count);
    }
}

int main()
{

    srand(time(NULL));
    pthread_t t[Thread_Count];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&semBufferEmpty, 0, BUFFER_SIZE);  // means 10 slots of buffer is initally empty
    sem_init(&semBufferFull, 0, 0);     // means 0 slots are occupied in buffer

    for (int i = 0; i < Thread_Count; i++)
    {
        if (i % 2 == 0)
            pthread_create(&t[i], NULL, &producer, NULL);
        else
            pthread_create(&t[i], NULL, &consumer, NULL);
    }

    for (int i = 0; i < Thread_Count; i++)
    {
        pthread_join(t[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&semBufferEmpty);
    sem_destroy(&semBufferFull);
}