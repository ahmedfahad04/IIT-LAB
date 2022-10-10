#include <stdio.h>
#include <stdlib.h>
#include <string.h>    // memset
#include <pthread.h>   // pthread_t, pthread_create, pthread_join
#include <semaphore.h> // sem_init, sem_wait, sem_post
#include <time.h>

// semaphore
sem_t pizza;
sem_t deliver;

int num_slices = 0;
pthread_mutex_t mutex;

// int students[5] = {1, 2, 3, 4, 5};

void *stu_eat_pizza(void *stu_id);
void *delivery_pizza();

int main()
{

    pthread_t piz;
	pthread_t *students;


    sem_init(&pizza, 0, 0);
    sem_init(&deliver, 0, 1);
    pthread_mutex_init(&mutex, NULL);


    int *student_ids;
    student_ids = (int *)malloc(sizeof(int) * 5);
	students = (pthread_t *)malloc(sizeof(pthread_t) * 5);
    memset(student_ids, 0, 5);


    pthread_create(&piz, NULL, delivery_pizza, (void *)&student_ids);

    for (int i = 0; i < 5; i++)
    {
        student_ids[i] = i + 1;
        pthread_create(&students[i], NULL, stu_eat_pizza, (void *)&student_ids[i]);
    }

    pthread_join(piz, NULL);

    for (int i = 0; i < 5; i++)
    {
        pthread_join(students[i], NULL);
    }
}


void *stu_eat_pizza(void *stu_id)
{
    int id = *(int *)stu_id;

    while (1) // while study
    {
        sem_wait(&pizza);
        pthread_mutex_lock(&mutex);

        printf("STUDENT %d TAKES A PIECE OF PIZZA...\n", id);
        num_slices--;

        if (num_slices == 0){ 
            sem_post(&deliver);
            printf("STUDENT [%d] ORDERED A PIZZA...\n", id);
        }

        pthread_mutex_unlock(&mutex);
        
    }
}

void *delivery_pizza(){

    while(1){

        sem_wait(&deliver);

        printf("MAKING PIZZA...\n");
        sleep(2);
        
		pthread_mutex_lock(&mutex);

        printf("DELEVERING A PIZZA ....\n");
        sleep(2);
        
        num_slices = 8;

        pthread_mutex_unlock(&mutex);

        for(int i=0; i<8; i++) sem_post(&pizza);

    }
}
