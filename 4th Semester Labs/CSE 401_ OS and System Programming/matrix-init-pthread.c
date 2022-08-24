/**
 * Matrix (N*N) multiplication with multiple threads.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

int size, num_threads=3;
double **matrix1, **matrix2, **matrix3;

double ** allocate_matrix( int size )
{
  /* Allocate 'size' * 'size' doubles contiguously. */
  double * vals = (double *) malloc( size * size * sizeof(double) );

  /* Allocate array of double* with size 'size' */
  double ** ptrs = (double **) malloc( size * sizeof(double*) );

  int i;
  for (i = 0; i < size; ++i) {
    ptrs[ i ] = &vals[ i * size ];
  }

  return ptrs;
}


void print_matrix( double **matrix, int size )
{
  int i, j;

  for (i = 0; i < size; ++i) {
    for (j = 0; j < size-1; ++j) {
      printf( "%lf, ", matrix[ i ][ j ] );
    }
    printf( "%lf", matrix[ i ][ j ] );
    putchar( '\n' );
  }
}

/**
 * Thread routine.
 * Each thread works on a portion of the 'matrix1'.
 * The start and end of the portion depend on the 'arg' which
 * is the ID assigned to threads sequentially. 
 */
void * worker( void *arg )
{
  int i, j, tid;
  double **mat;

  tid = *(int *)(arg); // get the thread ID assigned sequentially.

  if (tid == 0 ) mat = matrix1;
  else if (tid == 1 ) mat = matrix2;
  else  mat = matrix3;

  for (i = 0; i < size; ++i) {
    for (j = 0; j < size; ++j) {
       mat[ i ][ j ] = 1.0;
    }
  }
}

int main( int argc, char *argv[] )
{
  int i;
  double sum = 0;
  struct timeval tstart, tend;
  double exectime;
  pthread_t  threads[3];
  int *tid;

  if (argc != 2) {
    fprintf( stderr, "%s <matrix size>\n", argv[0] );
    return -1;
  }

  size = atoi( argv[1] );

  matrix1 = allocate_matrix( size );
  matrix2 = allocate_matrix( size );
  matrix3 = allocate_matrix( size );

  tid = (int *) malloc( sizeof(int) );
  gettimeofday( &tstart, NULL );
  *tid = 0;
  worker(&tid);
  *tid = 1;
  worker(&tid);
  *tid = 2;
  worker(&tid);
  gettimeofday( &tend, NULL );

  exectime = (tend.tv_sec - tstart.tv_sec) * 1000.0; // sec to ms
  exectime += (tend.tv_usec - tstart.tv_usec) / 1000.0; // us to ms   

  printf( "Number of threads: %d\tExecution time:%.3lf sec\n",
          1, exectime/1000.0);


  gettimeofday( &tstart, NULL );
  for ( i = 0; i < num_threads; ++i ) {
    *tid = i;
    pthread_create( &threads[i], NULL, worker, (void *)tid );
  }

  for ( i = 0; i < num_threads; ++i ) {
    pthread_join( threads[i], NULL );
  }
  gettimeofday( &tend, NULL );

/*
  if ( size <= 10 ) {
    printf( "Matrix 1:\n" );
    print_matrix( matrix1, size );
    printf( "Matrix 2:\n" );
    print_matrix( matrix2, size );
    printf( "Matrix 3:\n" );
    print_matrix( matrix3, size );
  }
*/

  exectime = (tend.tv_sec - tstart.tv_sec) * 1000.0; // sec to ms
  exectime += (tend.tv_usec - tstart.tv_usec) / 1000.0; // us to ms   

  printf( "Number of threads: %d\tExecution time:%.3lf sec\n",
          num_threads, exectime/1000.0);

  return 0;
}
