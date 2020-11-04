//
// Created by Mahmud Jego on 11/3/20.
//




#include "philosophers.h"

int main()
{
	t_day day;
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
	}
	return 0;
}