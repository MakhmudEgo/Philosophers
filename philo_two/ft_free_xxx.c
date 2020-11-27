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

	ft_is_stop_pthreads(arr_data, arr_philos);
	i = -1;
	sem_unlink(SEMEAT);
	sem_unlink(SEMPRINT);
	sem_close(arr_philos->v_mutex);
	sem_close(arr_philos->v_mutex_print);
	if (arr_data)
	{
		free(arr_data[0]->ptr_threads);
		while (++i < arr_philos->v_philos)
			free(arr_data[i]);
	}
	free(arr_philos);
	free(arr_data);
	return (0);
}
