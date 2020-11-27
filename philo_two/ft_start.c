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

	sem_wait(ar->ptr_philo->v_mutex);
	if (ft_print(ar, ar->v_id, FORK_TXT_L, FORK_LEN))
		return (1);
	sem_wait(ar->ptr_philo->v_mutex);
	if (ft_print(ar, ar->v_id, FORK_TXT_R, FORK_LEN) || ft_eat(ar))
		return (1);
	sem_post(ar->ptr_philo->v_mutex);
	sem_post(ar->ptr_philo->v_mutex);
	if (ft_print(ar, ar->v_id, SLEEP_TXT, SLEEP_LEN))
		return (1);
	if (!(time = ft_gettime()))
		return (1);
	while (ft_gettime() <= time + ar->ptr_philo->v_sleep)
		usleep(100);
	if (!ar->ptr_philo->v_stop && ft_print(ar, ar->v_id, THINK_TXT, THINK_LEN))
		return (1);
	return (0);
}

void		*ft_start(void *args)
{
	t_args *ar;

	ar = (t_args *)args;
	if (ar->v_id % 2 == 0)
		usleep(100);
	while (!(ar->ptr_philo->v_stop))
	{
		if ((ar->ptr_philo->v_is_eat && !ar->v_eaten) || ar->ptr_philo->v_stop)
			break ;
		if (!ar->ptr_philo->v_stop && ft_work(ar))
			return ((void *)1);
	}
	ar->v_finish = 13;
	return ((void *)0);
}
