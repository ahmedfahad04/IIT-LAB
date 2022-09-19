/**
 * Matrix (N*N) multiplication with multiple threads.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

int msize=9, num_threads=9;
double mat1[9][9], mat2[9][9], mat3[9][9];
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void print_matrix( double matrix[9][9], int size )
{
  int i, j;

  for (i = 0; i < size; ++i) {
    for (j = 0; j < size-1; ++j) {
      printf( "%.2lf, ", matrix[ i ][ j ] );
    }
    printf( "%.2lf", matrix[ i ][ j ] );
    putchar( '\n' );
  }
}


void init_matrix( double matrix[9][9], double val )
{
  int i, j;

  for (i = 0; i < msize; ++i) {
    for (j = 0; j < msize; ++j) {
       matrix[ i ][ j ] = val;
    }
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
  int i, j, k,  tid;
  double sum;

  tid = *(int *)(arg); 

  i = tid;
  for (j = 0; j < msize; ++j) {
    sum = 0.0;
    for (k = 0; k < msize; ++k) {
       pthread_mutex_lock( &mutex1 );
       sum += mat1[ i ][ k ] * mat2[ k ][ j ];
       pthread_mutex_unlock( &mutex1 );
    }
    mat3[ i ][ j ] = sum;
  }
}

int main( int argc, char *argv[] )
{
  int i;
  double sum = 0;
  struct timeval tstart, tend;
  double exectime;
  pthread_t  threads[9];


  init_matrix (mat1, 1);
  init_matrix (mat2, 2);


  for ( i = 0; i < num_threads; ++i ) {
    int *tid;
    tid = (int *) malloc( sizeof(int) );
    *tid = i;
    pthread_create( &threads[i], NULL, worker, (void *)tid );
  }

  for ( i = 0; i < num_threads; ++i ) {
    pthread_join( threads[i], NULL );
  }

  if ( msize <= 10 ) {
    printf( "Matrix 1:\n" );
    print_matrix( mat1, msize );
    printf( "Matrix 2:\n" );
    print_matrix( mat2, msize );
    printf( "Matrix 3:\n" );
    print_matrix( mat3, msize );
  }

  return 0;
}
