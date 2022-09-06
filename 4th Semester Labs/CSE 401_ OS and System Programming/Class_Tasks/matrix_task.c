/**
 * Matrix (N*N) multiplication with multiple threads.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

int size = 3, num_threads = 3;
double matrix1[5][5], matrix2[5][5], matrix3[5][5];

void print_matrix(double matrix[5][5])
{
    int i, j;

    for (i = 0; i < size; ++i)
    {
        for (j = 0; j < size - 1; ++j)
        {
            printf("%lf, ", matrix[i][j]);
        }

        printf("%lf", matrix[i][j]);
        putchar('\n');
    }
}

void initialize(double mat[5][5], int a)
{

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            mat[i][j] = a;
        }
    }
}
/**
 * Thread routine.
 * Each thread works on a portion of the 'matrix1'.
 * The start and end of the portion depend on the 'arg' which
 * is the ID assigned to threads sequentially.
 */
void *worker(void *arg)
{
    int i, j, tid;

    tid = *(int *)(arg); // get the thread ID assigned sequentially.

    for (i = 0; i < size; ++i)
    {
        int t = 0;
        for (j = 0; j < size; ++j)
        {
            t += matrix1[tid][j] * matrix2[j][i];
        }
        matrix3[tid][i] = t;
    }
}

int main()
{
    int i;
    double sum = 0;
    struct timeval tstart, tend;
    double exectime;
    pthread_t threads[num_threads + 1];

    initialize(matrix1, 1);
    initialize(matrix2, 2);
    initialize(matrix3, 0);

    // gettimeofday(&tstart, NULL);
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
    // gettimeofday(&tend, NULL);

    // exectime = (tend.tv_sec - tstart.tv_sec) * 1000.0;    // sec to ms
    // exectime += (tend.tv_usec - tstart.tv_usec) / 1000.0; // us to ms

    // printf("Number of threads: %d\tExecution time:%.3lf sec\n",
    //        num_threads, exectime / 1000.0);

    printf("Matrix 1:\n");
    print_matrix(matrix1);
    printf("Matrix 2:\n");
    print_matrix(matrix2);
    printf("\nMatrix 3:\n");
    print_matrix(matrix3);

    return 0;
}
