#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <semaphore.h>

sem_t s;

void *routine(void *x){

    sem_wait(&s);
    sleep(1);
    printf("HELLO WORLD --- %d\n", *(int*)x);
    sem_post(&s);
}

int main(){

    pthread_t t;
    int num = 10;
    pthread_t threads[num + 1];

    sem_init(&s, 0, 2);


    for(int i=0; i<num; i++){
        int *t = malloc(sizeof(int));
        *t = i;
        pthread_create(&threads[i], NULL, routine, (int*)t);
    }

    for(int i=0; i<num; i++){
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&s);

}