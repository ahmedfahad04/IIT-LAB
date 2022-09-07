#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t s;

int count = 0;

void * routine(void * tid) {

    while(1){

        // pthread_mutex_lock(&mutex);
        sem_wait(&s);
        sleep(1);
        count += 10;
        printf("CURRENT COUNT IS: %d\n", count);
        // pthread_mutex_unlock(&mutex);
        sem_post(&s);
    }
}

void * routine2(void *tid) {

    while(1) {
        sem_post(&s);
        // pthread_mutex_unlock(&mutex);
    }
}

int main(){
    
    pthread_t t;
    int thread_size = 5;
    sem_init(&s, 0, 5);


    for(int i=0; i<thread_size; i++){
        int *id = (int*) malloc(sizeof(int));
        *id = i;

        if(i % 2 == 0) pthread_create(&t, NULL, routine, (int *)i);
        else pthread_create(&t, NULL, routine2, (int *)i);

        // pthread_create(&t, NULL, routine, (int *)i);
    }

    for(int i=0; i<thread_size; i++){
        pthread_join(t, NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&s);

}