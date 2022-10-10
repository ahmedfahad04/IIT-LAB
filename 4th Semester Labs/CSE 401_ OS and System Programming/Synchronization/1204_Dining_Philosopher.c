#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <semaphore.h>

#define NUMBER_OF_PHILOSOPHERS 5

void *philosopher(void *);
void think(int);
void pickUp(int);
void eat(int);
void putDown(int);

sem_t chopsticks[NUMBER_OF_PHILOSOPHERS];
pthread_t thread_id[NUMBER_OF_PHILOSOPHERS];
pthread_attr_t attributes[NUMBER_OF_PHILOSOPHERS];
int philosophers[NUMBER_OF_PHILOSOPHERS] = {0, 1, 2, 3, 4};

int main()
{
	int i;

	for (i = 0; i < NUMBER_OF_PHILOSOPHERS; ++i)
		sem_init(&chopsticks[i], 0, 1);

	for (i = 0; i < NUMBER_OF_PHILOSOPHERS; ++i)
		pthread_create(&thread_id[i], NULL, philosopher, &philosophers[i]);

	for (i = 0; i < NUMBER_OF_PHILOSOPHERS; ++i)
		pthread_join(thread_id[i], NULL);

	return 0;
}

void *philosopher(void *philnumber)
{
	int philosopherNumber = *(int *)philnumber;

	while (1)
	{
		think(philosopherNumber);
		pickUp(philosopherNumber);
		eat(philosopherNumber);
		putDown(philosopherNumber);
	}
}

void think(int philosopherNumber)
{
	printf("Philosopher %d will think for %d seconds\n", philosopherNumber, 2);
	sleep(2);
}

void pickUp(int philosopherNumber)
{
	int right = (philosopherNumber + 1) % NUMBER_OF_PHILOSOPHERS;
	int left = (philosopherNumber + NUMBER_OF_PHILOSOPHERS) % NUMBER_OF_PHILOSOPHERS;

	if (philosopherNumber & 1)	// if the philosopher is odd
	{
		printf("Philosopher %d is waiting to pick up chopstick %d\n", philosopherNumber, right);

		sem_wait(&chopsticks[right]);
		printf("Philosopher %d picked up chopstick %d\n", philosopherNumber, right);
		printf("Philosopher %d is waiting to pick up chopstick %d\n", philosopherNumber, left);
		sem_wait(&chopsticks[left]);

		printf("Philosopher %d picked up chopstick %d\n", philosopherNumber, left);
	}
	else
	{
		printf("Philosopher %d is waiting to pick up chopstick %d\n", philosopherNumber, left);

		sem_wait(&chopsticks[left]);
		printf("Philosopher %d picked up chopstick %d\n", philosopherNumber, left);
		printf("Philosopher %d is waiting to pick up chopstick %d\n", philosopherNumber, right);
		sem_wait(&chopsticks[right]);

		printf("Philosopher %d picked up chopstick %d\n", philosopherNumber, right);
	}
}

void eat(int philosopherNumber)
{
	printf("Philosopher %d will eat for %d seconds\n", philosopherNumber, 2);
	sleep(2);
}

void putDown(int philosopherNumber)
{
	printf("Philosopher %d will will put down her chopsticks\n", philosopherNumber);
	sem_post(&chopsticks[(philosopherNumber + 1) % NUMBER_OF_PHILOSOPHERS]);
	sem_post(&chopsticks[(philosopherNumber + NUMBER_OF_PHILOSOPHERS) % NUMBER_OF_PHILOSOPHERS]);
}
