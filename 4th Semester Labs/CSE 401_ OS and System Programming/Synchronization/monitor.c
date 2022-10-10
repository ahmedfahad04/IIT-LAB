/* ---------------------------------------------------------------- */
/* PROGRAM  count-2.c:                                              */
/*    This program uses a monitor (inc-dec-m.h and inc-dec-m.c) to  */
/* synchronize the increasing, decreasing, reseting and retrieving  */
/* the value of a shared counter.  Note that the counter is within  */
/* the monitor.                                                     */
/* ---------------------------------------------------------------- */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

#include "inc-dec-m.h"

#define MAX_ITEMS 20
#define MAX_INC 5
#define MAX_DEC 4
#define MAX_THREADS 3

pthread_mutex_t Screen;       /* mutex lock for screen    */
pthread_mutex_t RandomNumber; /* lock for random # gen.   */

/* ---------------------------------------------------------------- */
/* FUNCTION  Increase():                                            */
/*    This function will be run as a thread.  It keeps increasing   */
/* the value of the shared counter.                                 */
/* ---------------------------------------------------------------- */

void *Increase(void *voidPTR)
{
    int *intPTR = (int *)voidPTR;
    int ID = *intPTR;
    int value, i;

    for (i = 0; i < MAX_ITEMS; i++)
    {                        /* iterates MAX_ITEMS times */
        thr_yield();         /* take some rest           */
        value = INC();       /* increase the value       */
        mutex_lock(&Screen); /* display the new value    */
        printf("   (%d): Counter has been increased by 1 "
               "(value = %d)\n",
               ID, value);
        mutex_unlock(&Screen);
    }
    thr_exit(0);
}

/* ---------------------------------------------------------------- */
/* FUNCTION  Decrease():                                            */
/*    This function will be run as a thread.  It keeps decreasing   */
/* the value of the shared counter.                                 */
/* ---------------------------------------------------------------- */

void *Decrease(void *voidPTR)
{
    int *intPTR = (int *)voidPTR;
    int ID = *intPTR;
    int value, i;

    for (i = 0; i < MAX_ITEMS; i++)
    {
        thr_yield();
        value = DEC();
        mutex_lock(&Screen);
        printf("   (%d): Counter has been decreased by 1 "
               "(value = %d)\n",
               ID, value);
        mutex_unlock(&Screen);
    }
    thr_exit(0);
}

/* ---------------------------------------------------------------- */
/* FUNCTION  Reset():                                               */
/*    This function will be run as a thread.  It keeps reseting the */
/* value of the shared counter.                                     */
/* ---------------------------------------------------------------- */

void *Reset(void *voidPTR)
{
    int *intPTR = (int *)voidPTR;
    int ID = *intPTR;
    int value, i;

    for (i = 0; i < MAX_ITEMS / 2; i++)
    {
        thr_yield();
        mutex_lock(&RandomNumber);
        value = rand() % MAX_INC;
        mutex_unlock(&RandomNumber);
        SET(value);
        mutex_lock(&Screen);
        printf("*** (%d): The counter has been reset to %d ***\n",
               ID, value);
        mutex_unlock(&Screen);
    }
    thr_exit(0);
}

/* ---------------------------------------------------------------- */
/* FUNCTION  Display():                                             */
/*   This function will be run as a thread.  It keeps displaying    */
/* the value of the shared counter.                                 */
/* ---------------------------------------------------------------- */

void *Display(void *voidPTR)
{
    int *intPTR = (int *)voidPTR;
    int ID = *intPTR;
    int value, i;

    for (i = 0; i < MAX_ITEMS / 2; i++)
    {
        thr_yield();
        value = GET();
        mutex_lock(&Screen);
        printf("### (%d): The current counter value is %d ###\n",
               ID, value);
        mutex_unlock(&Screen);
    }
    thr_exit(0);
}

/* ---------------------------------------------------------------- */
/*                 The Main Program Starts Here                     */
/* ---------------------------------------------------------------- */

void main(void)
{
    pthread_t incID[MAX_THREADS], decID[MAX_THREADS];
    pthread_t ResetID, DisplayID;
    size_t incStatus[MAX_THREADS], decStatus[MAX_THREADS];
    size_t ResetStatus, DisplayStatus;
    int incArg[MAX_THREADS], decArg[MAX_THREADS];
    int ResetArg, DisplayArg;
    int i;

    srand((unsigned)time(NULL));

    // mutex_init(&Screen, USYNC_THREAD, (void *)NULL);
    // mutex_init(&RandomNumber, USYNC_THREAD, (void *)NULL);
    pthread_mutex_t Screen = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_t RandomNumber = PTHREAD_MUTEX_INITIALIZER;

    CounterInit(0);

    ResetArg = 0;
    thr_create(NULL, 0, Reset, (void *)&ResetArg,
               0, (void *)&ResetID);
    DisplayArg = 1;
    thr_create(NULL, 0, Display, (void *)&DisplayArg,
               0, (void *)&DisplayID);

    for (i = 0; i < MAX_THREADS; i++)
    {
        incArg[i] = i + 2;
        decArg[i] = incArg[i] + MAX_THREADS;
        thr_create(NULL, 0, Increase, (void *)&(incArg[i]),
                   0, (void *)&(incID[i]));
        thr_create(NULL, 0, Decrease, (void *)&(decArg[i]),
                   0, (void *)&(decID[i]));
    }

    for (i = 0; i < MAX_THREADS; i++)
    {
        thr_join(incID[i], 0, (void *)&(incStatus[i]));
        thr_join(decID[i], 0, (void *)&(decStatus[i]));
    }
    thr_join(ResetID, 0, (void *)&ResetStatus);
    thr_join(DisplayID, 0, (void *)&DisplayStatus);

    printf("Parent exits ...\n");
}
