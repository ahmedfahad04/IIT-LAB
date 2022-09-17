#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define Thread_Count 2

int count = 0, buffer[10];

void *producer()
{
    while (1)
    {
        // produce
        int x = rand() % 100;

        // store in buffer
        
        /* this will produce segmentation fault
        as we have only 10 slots and once all are
        occupied, and if we try to access the 11th
        element, it'll throw SEGMENTATION FAULT.*/
        buffer[count] = x;  
        count++;
    }
}

void *consumer()
{

    while (1)
    {

        // retrieve from buffer
        int y = buffer[count - 1];
        count--;

        // consume
        printf("GET %d\n", y);
    }
}

int main()
{

    srand(time(NULL));
    pthread_t t[Thread_Count];

    for (int i = 0; i < Thread_Count; i++)
    {
        if(i%2 == 0) pthread_create(&t[i], NULL, &producer, NULL);
        else pthread_create(&t[i], NULL, &consumer, NULL);
    }

    for (int i = 0; i < Thread_Count; i++)
    {
        pthread_join(t[i], NULL);
    }
}