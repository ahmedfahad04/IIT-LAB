#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define Thread_Count 2
pthread_mutex_t mutex;

int count = 0, buffer[10];

void *producer()
{
    while (1)
    {
        // produce
        int x = rand() % 100;

        // store in buffer

        /* to avoid RACE CONDITION we need to
        add mutex */

        /* "MANY CASES ARE IGNORE AS BUFFER IS FULL": 
        We have a bigger issue to resolve and that is
        A lot of cases are being skippe din this producer
        section. For some x we ignore the case when the 
        buffer is FULL and that's totally unexpected.
        Those x might be important but we can't handle those
        number (x) as our buffer becomes full.*/
       
        pthread_mutex_lock(&mutex);
        if(count < 10){
            buffer[count] = x;
            count++;
        } else {
            printf("Skipped %d, Count %d\n", x, count);
        }
        pthread_mutex_unlock(&mutex);
    }
}

void *consumer()
{

    while (1)
    {
        int y = -1;

        // retrieve from buffer

        /* "CPU CYCLE WASTE DUE TO EMPTY BUFFER": 
        Here raised another problem that we got
        a lot of -1 which means huge cpu wastes as
        they do nothing;
        Here I should avoid such cases i.e I shouldn't 
        check the if condition so often...then when should 
        I check the condition is ANOTHER BIG QUESTION!!!*/
        pthread_mutex_lock(&mutex);
        if (count > 0)
        {
            y = buffer[count - 1];
            count--;
        }
        pthread_mutex_unlock(&mutex);

        // consume
        printf("\nGET %d, COUNT: %d", y, count);
        // sleep(1);
    }
}

int main()
{

    srand(time(NULL));
    pthread_t t[Thread_Count];
    pthread_mutex_init(&mutex, NULL);

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
}