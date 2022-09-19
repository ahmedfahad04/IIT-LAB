/**
 * Matrix (N*N) multiplication with multiple threads.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <semaphore.h>

int size = 1000000, num_threads = 3, count = 0.0;
double matrix1[5][1000000];
sem_t s1;

void print_matrix()
{
    int i, j;

    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < size - 1; ++j)
        {
            printf("%lf, ", matrix1[i][j]);
        }

        printf("%lf", matrix1[i][j]);
        putchar('\n');
    }
}

int initialize(int a)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix1[i][j] = a;
        }
    }
}

void *functionC_s()
{
    /*
    Semaphores can be wait(or lock) mulitple 
    times in multiple threads at the same time. 
    It Means multiple threads having same weight 
    executed at the same time. 
    But when we use 1 as the third parameter, 
    it acts similar to a mutex lock
    */
    sem_wait(&s1);
    count++;    // shared variable
    sem_post(&s1);
}

void *worker(void *arg)
{
    int i, j, tid;
    i = *(int *)(arg);

    for (int j = 0; j < size; j++)
    {
        if (matrix1[i][j] == 1)
            functionC_s();
    }
}

int main()
{
    int i;
    double sum = 0;
    struct timeval tstart, tend;
    double exectime;
    pthread_t threads[num_threads + 1];

    // matrix initialization
    initialize(1);

    /* 
    If the 2nd parameter is 0, it means we are using threads
    we would pass non zero value if we used multiple processes
    if the 3rd parameter is:
        1 - it's like mutex lock/ulock
        2 or more - it will then execute [that numbered] threads at the same time
    */

    // semaphore initialization
    sem_init(&s1, 0, 1);

    printf("ROW: %d\n", 3);
    printf("COLUMN: %d\n", size);

    gettimeofday(&tstart, NULL);
    int k = 0;

    for (int i = 0; i < num_threads; ++i)
    {
        int *tid = (int *)malloc(sizeof(int));
        *tid = i;
        pthread_create(&threads[i], NULL, worker, (void *)tid);
    }

    for (int i = 0; i < num_threads; ++i)
    {
        pthread_join(threads[i], NULL);
    }

    gettimeofday(&tend, NULL);

    exectime = (tend.tv_sec - tstart.tv_sec) * 1000.0;    // sec to ms
    exectime += (tend.tv_usec - tstart.tv_usec) / 1000.0; // us to ms

    printf("Number of threads: %d\tExecution time:%.3lf sec\n",
           num_threads, exectime / 1000.0);

    printf("COUNT of 1: %d\n", count);

    sem_destroy(&s1);

    return 0;
}
