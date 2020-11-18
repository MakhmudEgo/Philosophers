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

size_t	ft_gettime()
{
	t_day time;
	size_t res;

	gettimeofday(&time, 0x0);
	res = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (res);
}

int		ft_print(t_args *ar, size_t v_id, char *v_str, size_t v_strlen)
{
	char *v_time_message;
	char *v_message;
	size_t v_time;
	size_t v_len;

	if (!ar->ptr_philo->v_dead)
	{
		v_time = ft_gettime() - ar->ptr_philo->v_start;
		if (!(v_time_message = ft_str_for_msg(&v_time, 0x0, 0x0, 0x0))
			|| !(v_message = ft_str_for_msg(&v_id, 0x0, v_str, v_strlen)))
			return (-1);
		v_len = v_time + v_id;
		if (!(v_message = ft_join_3_ptr(v_time_message, " ", v_message, v_len)) ||
			(!ar->ptr_philo->v_dead && write(1, v_message, v_len) == -1))
			return (-1);
		free(v_message);
	}
	return (1);
}

int		ft_eat(t_args *ar)
{
	ft_print(ar, ar->v_id, EAT_TXT, EAT_LEN);
	ar->v_last_eat = ft_gettime();
	ar->v_finsh = ar->v_last_eat + ar->ptr_philo->v_die;
	while (ft_gettime() <= ar->v_last_eat + ar->ptr_philo->v_eat)
		usleep(100);
	if (ar->ptr_philo->v_is_eat && ar->v_eaten)
		ar->v_eaten--;
	return (1);
}

void	*ft_start(void *args)
{
	size_t l;
	size_t r;
	t_args *ar = (t_args *) args;

	l = ar->v_id - 1;
	r = ar->v_id == ar->ptr_philo->v_philos ? 0 : ar->v_id;
	ar->v_last_eat = ft_gettime();
	ar->v_finsh = ar->v_last_eat + ar->ptr_philo->v_die;
	while (!(0x0))
	{
		if (ar->ptr_philo->v_stop || (ar->ptr_philo->v_is_eat && !ar->v_eaten))
		{
			if (!ar->ptr_philo->v_dead && !(ar->ptr_philo->v_is_eat && !ar->v_eaten))
				ft_print(ar, ar->v_id, DEAD_TXT, DEAD_LEN);
			ar->ptr_philo->v_dead = 1;
			break ;
		}
		pthread_mutex_lock(ar->ptr_philo->ptr_mutex[l]);
		ft_print(ar, ar->v_id, FORK_TXT_L, FORK_LEN);
		pthread_mutex_lock(ar->ptr_philo->ptr_mutex[r]);
		ft_print(ar, ar->v_id, FORK_TXT_R, FORK_LEN);
		ft_eat(ar);
		if (!ar->ptr_philo->v_dead)
			usleep(2000);
		pthread_mutex_unlock(ar->ptr_philo->ptr_mutex[l]);
		pthread_mutex_unlock(ar->ptr_philo->ptr_mutex[r]);
		ft_print(ar, ar->v_id, SLEEP_TXT, SLEEP_LEN);
		size_t timi = ft_gettime();
		while (ft_gettime() <= timi + ar->ptr_philo->v_sleep)
			usleep(100);
		ft_print(ar, ar->v_id, THINK_TXT, THINK_LEN);
	}
	return (0x0);
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

int		ft_pthreads_create(t_args **args, t_philo *arr_philos)
{
	size_t	i;
	pthread_t		pit;
	pthread_t		**pits;

	i = 0;
	pits = malloc(sizeof(pthread_t*) *arr_philos->v_philos);
	while (i < arr_philos->v_philos)
	{
		arr_philos->ptr_mutex[i] = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(arr_philos->ptr_mutex[i], NULL);
		args[i] = malloc(sizeof(t_args) * arr_philos->v_philos);
		args[i]->ptr_philo = arr_philos;
		args[i]->v_id = i + 1;
		args[i]->v_last_eat = 0;
		args[i]->v_finsh = 0;
		args[i]->v_eaten = arr_philos->v_amount_eat;
		i++;
	}
	i = -1;
	arr_philos->v_start = ft_gettime();
	while (++i < arr_philos->v_philos)
	{
		pthread_create(&pit, 0x0, ft_start, (void *) args[i]);
		pits[i] = &pit;
		args[i]->ptr_threads = pits;
		usleep(200);
	}
	ft_monitoring_status_philos(args);
	i = -1;
	while (++i < arr_philos->v_philos)
		pthread_join(*args[i]->ptr_threads[i], 0x0);
	return (0);
}

int		ft_init_args(char **argv)
{
	t_args **arr_data;
	t_philo *arr_philos;

	arr_philos = malloc(sizeof(t_philo));
	arr_philos->v_philos = ft_atoi(argv[1]); //PHS;
	arr_philos->v_die = ft_atoi(argv[2]);
	arr_philos->v_eat = ft_atoi(argv[3]);
	arr_philos->v_sleep = ft_atoi(argv[4]);
	arr_philos->v_amount_eat = argv[5] ? ft_atoi(argv[5]) : 0;
	arr_philos->v_is_eat = argv[5] ? 1 : 0;
	arr_philos->v_stop = 0x0;
	arr_philos->v_start = 0x0;
	arr_philos->v_dead = 0x0;
	if (arr_philos->v_philos <= 0)
		return (1);
	arr_data = malloc(sizeof(t_args *) * arr_philos->v_philos);
	arr_philos->ptr_mutex = malloc(sizeof(pthread_mutex_t *) * arr_philos->v_philos);
	ft_pthreads_create(arr_data, arr_philos);
	return 0;
}

int		main(int argc, char **argv)
{

	if(argc < 5 || argc > 6 || ft_init_args(argv))
	{
		write(1, "bad args\n", 9);
		return (1);
	}

	return (0);
}
