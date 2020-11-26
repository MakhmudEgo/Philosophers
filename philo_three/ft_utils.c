/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizola <mizola@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 05:16:21 by mizola            #+#    #+#             */
/*   Updated: 2020/11/19 05:16:22 by mizola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	ft_gettime(void)
{
	t_day	time;
	size_t	res;

	if (gettimeofday(&time, 0x0) == -1)
		return (0);
	res = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (res);
}

int		ft_print(t_args *ar, size_t v_id, char *v_str, size_t v_strlen)
{
	char	*v_time_message;
	char	*v_message;
	size_t	v_time;
	size_t	v_len;

	sem_wait(g_dead);
	v_message = 0x0;
	if (!(v_time = ft_gettime()))
		return (1);
	v_time -= ar->v_start;
	if (!(v_time_message = ft_str_for_msg(&v_time, 0x0, 0x0, 0x0))
		|| !(v_message = ft_str_for_msg(&v_id, 0x0, v_str, v_strlen)))
	{
		free(v_time_message);
		free(v_message);
		return (1);
	}
	v_len = v_time + v_id;
	if (!(v_message = ft_join_3_ptr(v_time_message, " ", v_message, v_len)))
		return (1);
	write(1, v_message, v_len);
	free(v_message);
	if (v_strlen != DEAD_LEN)
		sem_post(g_dead);
	return (0);
}

int		ft_eat(t_args *ar)
{
	ar->v_last_eat = ft_gettime();
	if (!ar->v_stop && ft_print(ar, ar->v_id, EAT_TXT, EAT_LEN))
		return (1);
/*	while (ft_gettime() <= ar->v_last_eat + ar->v_eat)
		usleep(100);*/
	if (ar->v_is_eat && ar->v_eaten)
		ar->v_eaten--;
	return (0);
}

void		*ft_monitoring_status_philos(void *args)
{
	long long	v_time_now;

	t_args *ar = (t_args *)args;
	while (!(0x0))
	{
		usleep(21);
		v_time_now = (long long)ft_gettime();
		if (((v_time_now - ar->v_last_eat)
			 > ar->v_die))
		{
			if (!(ar->v_is_eat && !ar->v_eaten))
			{
//				g_test = 13;
				ft_print(ar, ar->v_id, DEAD_TXT, DEAD_LEN);
				exit(13);
			}
		}
		if (ar->v_is_eat && !ar->v_eaten)
		{
			ar->v_stop = 12;
			break ;
		}
	}
	return (0x0);
}
