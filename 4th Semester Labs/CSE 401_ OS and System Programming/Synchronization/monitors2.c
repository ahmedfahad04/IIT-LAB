/**
 * Brian Anderson, Spring 2013
 * Com S 352, Assignment 7
 *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * INTRODUCTION & PURPOSE
 * -------------------------------------------------------------------
 * Create a monitor library fashioned after the slides shown in class.
 * It solves the producer/consumer problem by making sure their
 * execution happens in a safe manner, even across multiple threads
 * by using two semaphores to lock and notify reading and
 * writing operations.
 *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * USING THE LIBRARY
 * -------------------------------------------------------------------
 *
 *  if(monitor_Initialized() == 0){
 *    monitor_StartWrite();
 *    + - - - - - - - - - - - +      Your producer/writer code here
 *    |                       |  <<  monitor_StartWrite(); will block
 *    + - - - - - - - - - - - +      until it is safe to write/produce data.
 *    monitor_EndWrite();
 *
 *    monitor_StartRead();
 *    + - - - - - - - - - - - +      Your consumer/reader code here
 *    |                       |  <<  monitor_StartRead(); will block
 *    + - - - - - - - - - - - +      until it is safe to consume data
 *    monitor_EndRead();
 *
 *    monitor_Destroy();
 *  }
 *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * BUILDING
 * -------------------------------------------------------------------
 * Compilation must be linked with pthread library
 * on pyrite the command should look like the following
 *   cc -o monitor monitor.c -lpthread
 *
 * For testing purposes there is main(), with the body commented out.
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>

// Define the data we need to create the monitor
struct monitor_DataType
{
    sem_t OKtoRead;
    sem_t OKtoWrite;
    int readerCount;
    int isBusyWriting;
    // The read-queue
    int readRequested;
};
struct monitor_DataType monitor_data;

// Function that will block until write can start
void monitor_StartWrite()
{
    if (monitor_data.isBusyWriting || monitor_data.readerCount != 0)
    {
        sem_wait(&(monitor_data.OKtoWrite));
    }
    monitor_data.isBusyWriting++; // Using 1 as true
}

// Function to signal reading is complete
void monitor_EndWrite()
{
    monitor_data.isBusyWriting--;
    if (monitor_data.readRequested)
    {
        sem_post(&(monitor_data.OKtoRead));
    }
    else
    {
        sem_post(&(monitor_data.OKtoWrite));
    }
}

// Function that will block until read can start
void monitor_StartRead()
{
    if (monitor_data.isBusyWriting)
    {
        monitor_data.readRequested++;
        sem_wait(&(monitor_data.OKtoRead));
        monitor_data.readRequested--;
    }
    monitor_data.readerCount++;
    sem_post(&(monitor_data.OKtoRead));
}

// Function to signal reading is complete
void monitor_EndRead()
{
    monitor_data.readerCount--;
    if (monitor_data.readerCount == 0)
    {
        sem_post(&(monitor_data.OKtoWrite));
    }
}

// intialize the monitor
// return's 0 on success, just like sem_init()
int monitor_Initialized()
{
    int returnValue = 1;

    // Initialize the structure
    monitor_data.readerCount = 0;
    monitor_data.isBusyWriting = 0;
    monitor_data.readRequested = 0;

    // initialize the semaphores
    if (sem_init(&(monitor_data.OKtoWrite), 0, 1) == 0 &&
        sem_init(&(monitor_data.OKtoRead), 0, 1) == 0)
    {
        returnValue = 0;
    }
    else
    {
        printf("Unable to initialize semaphores\n");
    }
    return returnValue;
}

// Destroys the semphores.
void monitor_Destroy()
{
    sem_destroy(&(monitor_data.OKtoWrite));
    sem_destroy(&(monitor_data.OKtoRead));
}

int main()
{
    /** For testing only
    --------------------------------
     if(monitor_Initialized() == 0){
       printf("Initialized\n");

       monitor_StartWrite();
       printf("Writing stuffs...\n");
       monitor_EndWrite();

       monitor_StartRead();
       printf("Reading stuffs...\n");
       monitor_EndRead();

       monitor_Destroy();
     }
    */
    return 0;
}