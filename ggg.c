/*
//
// Created by Mahmud Jego on 11/5/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define ERROR_CREATE_THREAD -11
#define ERROR_JOIN_THREAD   -12
#define BAD_MESSAGE         -13
#define SUCCESS               0

typedef struct someArgs_tag {
	int id;
	const char *msg;
	int out;
} someArgs_t;

void* helloWorld(void *args) {
	someArgs_t *arg = (someArgs_t*) args;
	int len;

	if (arg->msg == NULL) {
		return BAD_MESSAGE;
	}

	len = (int)strlen(arg->msg);
	printf("%s\n", arg->msg);
	arg->out = len;

	return SUCCESS;
}

#define NUM_THREADS 4

int main() {
	pthread_t threads[NUM_THREADS];
	int status;
	int i;
	int status_addr;
	someArgs_t args[NUM_THREADS];
	const char *messages[] = {
			"First",
			"NULL",
			"Third Message",
			"Fourth Message"
	};

	for (i = 0; i < NUM_THREADS; i++) {
		args[i].id = i;
		args[i].msg = messages[i];
	}

	for (i = 0; i < NUM_THREADS; i++)
	{
		status = pthread_create(&threads[i], NULL, helloWorld, (void*) &args[i]);
		if (status != 0) {
			printf("main error: can't create thread, status = %d\n", status);
			exit(ERROR_CREATE_THREAD);
		}
	}
	pthread_detach(threads[0]);
	printf("Main Message\n");
	for (i = 1; i < NUM_THREADS; i++) {
		status = pthread_join(threads[i], (void**)&status_addr);
		if (status != SUCCESS) {
//			printf("main error: can't join thread, status = %d\n", status);
//			exit(ERROR_JOIN_THREAD);
			continue ;
		}
		printf("joined with address %d - %d\n", status_addr, i);
	}
	for (i = 1; i < NUM_THREADS; i++) {
		status = pthread_join(threads[i], (void**)&status_addr);
		if (status != SUCCESS) {
//			printf("main error: can't join thread, status = %d\n", status);
//			exit(ERROR_JOIN_THREAD);
			continue ;
		}
		printf("joined with address %d - %d\n", status_addr, i);
	}

	for (i = 0; i < NUM_THREADS; i++) {
		printf("thread %d arg.out = %d\n", i, args[i].out);
	}

//	_getch();
	return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <pthread.h>

static int counter = 0;

void* minus(void *args) {
	int local;
	pthread_mutex_t mutex;
	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_lock(&mutex);
	local = counter;
	printf("min %d\n", counter);
	local = local - 1;
	counter = local;
	pthread_mutex_unlock(&mutex);
	pthread_mutex_destroy(&mutex);
	return NULL;
}

void* plus(void *args) {
	int local;
	pthread_mutex_t mutex;
	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_lock(&mutex);
	local = counter;
	printf("pls %d\n", counter);
	local = local + 1;
	counter = local;
	pthread_mutex_unlock(&mutex);
	pthread_mutex_destroy(&mutex);
	return NULL;
}

#define NUM_OF_THREADS 5

int main()
{
	pthread_t threads[NUM_OF_THREADS];
	size_t i;

//	while (21)
	{
		printf("counter = %d\n", counter);
		for (i = 0; i < NUM_OF_THREADS / 2; i++) {
			pthread_create(&threads[i], NULL, minus, NULL);
		}
		for (; i < NUM_OF_THREADS; i++) {
			pthread_create(&threads[i], NULL, plus, NULL);
		}
		for (i = 0; i < NUM_OF_THREADS; i++) {
			pthread_join(threads[i], NULL);
		}
		printf("counter = %d", counter);
	}
//	_getch();
	return 0;
}
