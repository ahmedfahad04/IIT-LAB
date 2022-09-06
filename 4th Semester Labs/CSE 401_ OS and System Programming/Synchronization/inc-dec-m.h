/* ---------------------------------------------------------------- */
/* MONITOR  inc-dec-m.h:                                            */
/*    This monitor provides the following procedures for a counter: */
/*    (1)  CounterInit()        - initialize the counter            */
/*    (2)  INC()         - increase the counter value by one        */
/*    (3)  DEC()         - decrease the counter value by one        */
/*    (4)  SET()         - reset the counter value with a new value */
/*    (5)  GET()         - retrieve the counter value               */
/* To establish mutual exclusion, a mutex lock is used.             */
/* The counter and the lock are static in this file so that they    */
/* cannot be accessed from outside of this function.                */
/*                                                                  */
/* Although several functions return the value of the counter, this */
/* returned value may not be accurate since before the retrieved    */
/* value can be returned to a thread, the counter may have already  */
/* been reset, increased or decreased.                              */
/* ---------------------------------------------------------------- */

void  CounterInit(int  n);              /* initialize monitor       */
int   INC(void);                        /* increase the counter     */
int   DEC(void);                        /* decrease the counter     */
void  SET(int  n);                      /* reset the counter        */
int   GET(void);                        /* retrieve counter's value */

