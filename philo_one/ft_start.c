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

static int	ft_work(t_args *ar, size_t l, size_t r)
{
	size_t time;

	pthread_mutex_lock(ar->ptr_philo->ptr_mutex[l]);
	if (ft_print(ar, ar->v_id, FORK_TXT_L, FORK_LEN))
		return (1);
	pthread_mutex_lock(ar->ptr_philo->ptr_mutex[r]);
	if (ft_print(ar, ar->v_id, FORK_TXT_R, FORK_LEN) || ft_eat(ar))
		return (1);
	if (!ar->ptr_philo->v_dead)
		pthread_mutex_unlock(ar->ptr_philo->ptr_mutex[l]);
	if (!ar->ptr_philo->v_dead)
		pthread_mutex_unlock(ar->ptr_philo->ptr_mutex[r]);
	if (ft_print(ar, ar->v_id, SLEEP_TXT, SLEEP_LEN) || !(time = ft_gettime()))
		return (1);
	while (ft_gettime() <= time + ar->ptr_philo->v_sleep)
		usleep(100);
	if (ft_print(ar, ar->v_id, THINK_TXT, THINK_LEN))
		return (1);
	return (0);
}

void		*ft_start(void *args)
{
	size_t l;
	size_t r;
	t_args *ar;

	ar = (t_args *)args;
	l = ar->v_id - 1;
	r = ar->v_id == ar->ptr_philo->v_philos ? 0 : ar->v_id;
	if (!(ar->v_last_eat = ft_gettime()))
		return ((void *)1);
	ar->v_finsh = ar->v_last_eat + ar->ptr_philo->v_die;
	while (!(ar->ptr_philo->v_dead))
	{
		if ((ar->ptr_philo->v_is_eat && !ar->v_eaten))
			break ;
		if (ar->ptr_philo->v_stop)
		{
			ar->ptr_philo->v_dead = ar->v_id;
			break ;
		}
		if (ft_work(ar, l, r))
			return ((void *)1);
	}
	return (0x0);
}
