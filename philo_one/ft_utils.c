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

	v_message = 0x0;
	if (!(v_time = ft_gettime()))
		return (1);
	v_time -= ar->ptr_philo->v_start;
	if (!(v_time_message = ft_str_for_msg(&v_time, 0x0, 0x0, 0x0))
		|| !(v_message = ft_str_for_msg(&v_id, 0x0, v_str, v_strlen)))
	{
		free(v_time_message);
		free(v_message);
		return (1);
	}
	v_len = v_time + v_id;
	if (!(v_message = ft_join_3_ptr(v_time_message, " ", v_message, v_len)) ||
		(write(1, v_message, v_len) == -1))
		return (1);
	free(v_message);
	return (0);
}

int		ft_eat(t_args *ar)
{
	if (ft_print(ar, ar->v_id, EAT_TXT, EAT_LEN))
		return (1);
	ar->v_last_eat = ft_gettime();
	ar->v_finsh = ar->v_last_eat + ar->ptr_philo->v_die;
	while (ft_gettime() <= ar->v_last_eat + ar->ptr_philo->v_eat)
		usleep(100);
	if (ar->ptr_philo->v_is_eat && ar->v_eaten)
		ar->v_eaten--;
	return (0);
}

void	ft_monitoring_status_philos(t_args **args)
{
	size_t i;

	while (!(0x0))
	{
		i = 0;
		while (i < args[0]->ptr_philo->v_philos)
		{
			if (ft_gettime() >= args[i]->v_finsh)
			{
				args[0]->ptr_philo->v_stop = 1;
				break ;
			}
			i++;
		}
		if (args[0]->ptr_philo->v_stop)
			break ;
	}
}
