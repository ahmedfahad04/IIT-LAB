#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

sem_t resource, rmutex, wmutex, readertry, writertry;

int count = 0, readercount = 0, writercount = 0;

void *reader(void * id){

    int rid = *(int*) id;

    sem_wait(&rmutex);
    /* critical section */
    readercount++;
    printf("\nREADER [%d] WAITING\n", rid);
    if (readercount == 1) sem_wait(&resource);
    sem_post(&rmutex);


    /* do the reading */
    printf("Reader [%d] read the value = %d\n", rid+1, count);


    sem_wait(&rmutex);
    /* critical section */
    readercount--;
    if(readercount == 0) sem_post(&resource);
    sem_post(&rmutex);

}

void *writer(void * id){

    int wid = *(int *)id;

    sem_wait(&resource);
    /* critical section */
    count++;
    printf("Writer [%d] updated the value to %d\n", wid+1, count);
    sem_post(&resource);
}

int main(){

    sem_init(&resource, 0, 1);
    sem_init(&rmutex, 0, 1);

    int size = 5;
    pthread_t rd[size+6], wr[size+1];

    int a[10] = {1,2,3,4,5,6,7,8,9,10};

    
    // for(int i=0; i<size; i++){
    //     pthread_create(&rd[i], NULL, reader, (int *)&i);
    // }

    // for(int i=0; i<size; i++){
    //     pthread_create(&wr[i], NULL, writer, (int *)&i);
    // }

    for(int i=0; i<size; i++){
        pthread_create(&rd[i], NULL, reader, (int *)&i);
        pthread_create(&wr[i], NULL, writer, (int *)&i);

    }

    // for(int i=0; i<size; i++){
    //     pthread_join(rd[i], NULL);
    // }

    // for(int i=0; i<size; i++){
    //     pthread_join(wr[i], NULL);
    // }

    
    for(int i=0; i<size; i++){
        pthread_join(rd[i], NULL);
        pthread_join(wr[i], NULL);
    }


    sem_destroy(&resource);
    sem_destroy(&rmutex);
    
}