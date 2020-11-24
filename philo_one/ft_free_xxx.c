/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_xxx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizola <mizola@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 20:17:54 by mizola            #+#    #+#             */
/*   Updated: 2020/11/24 20:17:55 by mizola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_is_stop_pthreads(t_args **arr_data, t_philo *arr_philos)
{
	size_t i;

	while (1)
	{
		i = 0;
		while (i < arr_philos->v_philos)
		{
			if (!arr_data[i]->v_finish)
				break ;
			i++;
		}
		if (i == arr_philos->v_philos)
			break ;
	}
}

int			ft_free_xxx(t_args **arr_data, t_philo *arr_philos)
{
	size_t i;

	i = 0;
	ft_is_stop_pthreads(arr_data, arr_philos);
	while (i < arr_philos->v_philos)
	{
		pthread_mutex_destroy(arr_philos->ptr_mutex[i]);
		free(arr_philos->ptr_mutex[i++]);
	}
	free(arr_philos->ptr_mutex);
	i = 0;
	pthread_mutex_destroy(arr_philos->ptr_mutex_write);
	free(arr_philos->ptr_mutex_write);
	if (arr_data)
	{
		free(arr_data[0]->ptr_threads);
		while (i < arr_philos->v_philos)
			free(arr_data[i++]);
	}
	free(arr_philos);
	free(arr_data);
	return (0);
}
