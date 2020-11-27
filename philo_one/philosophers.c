/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizola <mizola@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:00:58 by mizola            #+#    #+#             */
/*   Updated: 2020/11/03 21:01:02 by mizola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		ft_create_mutex(t_args **args, t_philo *arr_philos, size_t i)
{
	arr_philos->ptr_mutex_write = malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(arr_philos->ptr_mutex_write, NULL))
		return (1);
	while (i < arr_philos->v_philos)
	{
		arr_philos->ptr_mutex[i] = malloc(sizeof(pthread_mutex_t));
		if (pthread_mutex_init(arr_philos->ptr_mutex[i], NULL))
		{
			arr_philos->ptr_mutex[i] = 0x0;
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < arr_philos->v_philos)
	{
		if (!(args[i] = malloc(sizeof(t_args) * arr_philos->v_philos)))
			return (1);
		args[i]->ptr_philo = arr_philos;
		args[i]->v_id = i + 1;
		args[i]->v_last_eat = 0;
		args[i]->v_finish = 0;
		args[i++]->v_eaten = arr_philos->v_amount_eat;
	}
	return (0);
}

int		ft_pthreads_create(t_args **args, t_philo *arr_philos, size_t i)
{
	pthread_t pit;
	pthread_t **pits;

	args[arr_philos->v_philos] = 0x0;
	if (ft_create_mutex(args, arr_philos, 0)
	|| !(arr_philos->v_start = ft_gettime())
	|| !(pits = malloc(sizeof(pthread_t *) * (arr_philos->v_philos + 1))))
		return (1);
	i = -1;
	while (++i < arr_philos->v_philos)
	{
		args[i]->v_last_eat = arr_philos->v_start;
		if (pthread_create(&pit, 0x0, ft_start, (void *)args[i]))
		{
			args[i]->ptr_threads = 0x0;
			return (1);
		}
		pits[i] = &pit;
		args[i]->ptr_threads = pits;
	}
	ft_monitoring_status_philos(args);
	if (arr_philos->v_dead)
		ft_print(args[0], args[0]->ptr_philo->v_dead, DEAD_TXT, DEAD_LEN);
	return (0);
}

int		ft_init_args(char **argv, t_philo *arr_philos)
{
	arr_philos->v_philos = ft_atoi(argv[1]);
	arr_philos->v_die = ft_atoi(argv[2]);
	arr_philos->v_eat = ft_atoi(argv[3]);
	arr_philos->v_sleep = ft_atoi(argv[4]);
	arr_philos->v_amount_eat = argv[5] ? ft_atoi(argv[5]) : 0;
	arr_philos->v_is_eat = argv[5] ? 1 : 0;
	arr_philos->v_stop = 0x0;
	arr_philos->v_start = 0x0;
	arr_philos->v_dead = 0x0;
	if ((arr_philos->v_philos < 2) || !(arr_philos->ptr_mutex =
			malloc(sizeof(pthread_mutex_t *) * (arr_philos->v_philos + 1))))
		return (1);
	arr_philos->ptr_mutex[arr_philos->v_philos] = 0x0;
	return (0);
}

int		main(int argc, char **argv)
{
	t_args	**arr_data;
	t_philo	*arr_philos;

	if (argc < 5 || argc > 6)
	{
		write(1, "bad args\n", 9);
		return (1);
	}
	if (!(arr_philos = malloc(sizeof(t_philo)))
	|| ft_init_args(argv, arr_philos))
		return (1);
	if ((arr_data = malloc(sizeof(t_args *) * (arr_philos->v_philos + 1))))
		ft_pthreads_create(arr_data, arr_philos, -1);
	return (ft_free_xxx(arr_data, arr_philos));
}
