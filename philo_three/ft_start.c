/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizola <mizola@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 05:13:10 by mizola            #+#    #+#             */
/*   Updated: 2020/11/19 05:13:11 by mizola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_work(t_args *ar)
{
	size_t time;

	sem_wait(ar->v_mutex);
	if (!ar->v_dead && ft_print(ar, ar->v_id, FORK_TXT_L, FORK_LEN))
		return (1);
	sem_wait(ar->v_mutex);
	if (!ar->v_dead && (ft_print(ar, ar->v_id, FORK_TXT_R, FORK_LEN) || ft_eat(ar)))
		return (1);
	if (!(time = ft_gettime()))
		return (1);
	while (ft_gettime() <= time + ar->v_sleep)
		usleep(100);
	sem_post(ar->v_mutex);
	sem_post(ar->v_mutex);
	if (!ar->v_dead && ft_print(ar, ar->v_id, SLEEP_TXT, SLEEP_LEN))
		return (1);
	if (!(time = ft_gettime()))
		return (1);
	while (ft_gettime() <= time + ar->v_sleep)
		usleep(100);
	if (!ar->v_dead && ft_print(ar, ar->v_id, THINK_TXT, THINK_LEN))
		return (1);
	return (0);
}

void ft_start(t_args *ar)
{
	pthread_t			v_pit;

	if (pthread_create(&v_pit, 0x0, ft_monitoring_status_philos, (void  *)ar))
		exit(13);
	if (ar->v_id % 2 == 0)
		usleep(100);
	while (!(0x0))
	{
/*		if (g_test)
			exit(13);*/
		if (ar->v_is_eat && !ar->v_eaten)
		{
			exit(12);
		}
		if (!ar->v_dead &&ft_work(ar))
			exit(13);
	}
	exit(0);
}
