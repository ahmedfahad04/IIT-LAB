/**
 * Matrix (N*N) multiplication with multiple threads.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

int size = 1000000, num_threads = 3, count = 0.0;
double matrix1[5][1000000];
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

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

void initialize(int a)
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix1[i][j] = a;
        }
    }
}

void *functionC()
{
   pthread_mutex_lock( &mutex1 );
   count++;
//    printf("Counter value: %d\n",count);
   pthread_mutex_unlock( &mutex1 );
}

void *worker(void *arg)
{
    int i, j, tid;
    i = *(int *) (arg);

    for(int j=0; j<size; j++){
        if(matrix1[i][j] = 1) functionC();
        // if(matrix1[i][j] = 1) count++;;
    }

    // pthread_mutex_lock(&mutex1);
    // for(int j=0; j<size; j++){
    //     // if(matrix1[i][j] = 1) functionC();
    //     if(matrix1[i][j] = 1) count++;;
    // }
    // pthread_mutex_unlock(&mutex1);
}

int main()
{
    int i;
    double sum = 0;
    struct timeval tstart, tend;
    double exectime;
    pthread_t threads[num_threads + 1];
    // pthread_t threads;

    initialize(1);

    gettimeofday(&tstart, NULL);
    int k = 0;

    for (int i = 0; i < num_threads; ++i)
    {
        int *tid;
        tid = (int *)malloc(sizeof(int));
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
