/*
 * Semaphore: Use a semaphore when you (thread) want to sleep till some other 
 * thread tells you to wake up. Semaphore 'down' happens in one thread (producer) 
 * and semaphore 'up' (for same semaphore) happens in another thread (consumer) 
 * e.g.: In producer-consumer problem, producer wants to sleep till at least one 
 * buffer slot is empty - only the consumer thread can tell when a buffer slot is empty.

 * Mutex: Use a mutex when you (thread) want to execute code that should not be executed 
 by any other thread at the same time. Mutex 'down' happens in one thread and mutex 'up' 
 must happen in the same thread later on. e.g.: If you are deleting a node from a global 
 linked list, you do not want another thread to muck around with pointers while you are 
 deleting the node. When you acquire a mutex and are busy deleting a node, if another 
 thread tries to acquire the same mutex, it will be put to sleep till you release the mutex.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <semaphore.h>

int size = 10000000, num_threads = 3, count = 0.0;
double matrix1[5][10000000];
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
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
    Means multiple threads having same weight is
    called at the same time.
    But when we use 1 as the third parameter,
    it acts similar to a mutex lock
    */
    sem_wait(&s1);
    count++;
    sem_post(&s1);
}

void *functionC_m()
{

    /*
    In mutex we can lock into one thread
    We may lock it several times but it's
    bound is within only ONE thread. It can't be
    locked in multiple threads at the same time.
    */
    pthread_mutex_lock(&mutex1);
    count++;
    pthread_mutex_unlock(&mutex1);
}

void *worker(void *arg)
{
    int i, j, tid;
    i = *(int *)(arg);

    for (int j = 0; j < size; j++)
    {
        if (matrix1[i][j] = 1)
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
    int sem_init_return_value = 1;
    // pthread_t threads;

    initialize(1);

    /* If the 2nd parameter is 0, it means we are using threads
     we would pass non zero value if we used multiple processes
     if the 3rd parameter is:
        1 - it's like mutex lock/ulock
        >2 - it will then execute that numbered threads at the same time
    */
    sem_init_return_value = sem_init(&s1, 0, 2);
    printf("%d\n", sem_init_return_value);

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

    printf("COUNT: %d\n", count);

    return 0;
}
