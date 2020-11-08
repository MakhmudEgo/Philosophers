//
// Created by Mahmud Jego on 11/3/20.
//

#include "philo_one/philosophers.h"


void *hello()
{
	write(1, "say hello\n", 10);
	return 0X0;
}


void* helloWorld(void *args) {
	someArgs_t *arg = (someArgs_t*) args;
	int len;

	if (arg->msg == NULL) {
		return -1;
	}

	len = strlen(arg->msg);
	printf("%s\n", arg->msg);
	arg->out = len;

	return SUCCESS;
}

int main()
{
/*	t_day day;
	t_zone zone;
	int i = 0;
	while (i < 5)
	{
		gettimeofday(&day, 0x0);
		printf("day - %ld; $%d\n", day.tv_sec/86400, i);
		usleep(MILLISECOND * 100);
		i++;
	}
	while (i < 10)
	{
		gettimeofday(&day, 0x0);
		printf("day - %ld; $%d\n", day.tv_sec/2629743/12, i);
		usleep(SECOND);
		i++;
	}*/

	pthread_t thread;
	int status;
	int status_addr;

	status = pthread_create(&thread, 0x0, hello, 0x0);
	if (status)
		return 32;
	status = pthread_join(thread, (void **)&status_addr);
	if (status) {
		return 54;
	}
	write(1, "hello from main\n", 16);
	printf("join - %d\n", status_addr);
	return 0;
}

/*
#define PH 5

void *hello(void *args)
{
	someArgs_t *ars = (someArgs_t *) args;


	pthread_mutex_lock(ars->mutex);
	write(1, ars->msg, 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	usleep(1000000);
	pthread_mutex_unlock(ars->mutex);
//	pthread_mutex_destroy(ars->mutex);
}

int main()
{
	pthread_t thread[PH];
	someArgs_t args[PH];

	int status;
	int status_addr;
	int i = 0;
	pthread_mutex_t mutex;
	pthread_mutex_init(&mutex, NULL);
	const char *messages[] = {
			"1",
			"2",
			"3",
			"4",
			"5"
	};

	while (i < PH)
	{
		args[i].id = i;
		args[i].msg = messages[i];
		args[i].mutex = &mutex;
		i++;
	}
//	while (21)
	{
		i = 0;
		while (i < PH)
		{
			status = pthread_create(&thread[i], 0x0, hello, (void *) &args[i]);
//			usleep(1);
			i++;
		}
		i = 0;
		while (i < PH)
		{
			pthread_join(thread[i], 0x0);
			i++;
		}
	}
	return 0;
}
*/
