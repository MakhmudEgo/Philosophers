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
	res = time.tv_sec * 1000;
	return (res);
}

int		ft_print(size_t v_id, char *v_str, size_t v_strlen)
{
	char *v_message;

	if (!(v_message = ft_str_for_msg(&v_id, 0x0, v_str, v_strlen))
	|| write(1, v_message, v_id) == -1)
		return (-1);
	return (1);
}

void		ft_eat(t_args *ar)
{
	ar->v_last_eat = ft_gettime();
	ft_print(ar->v_id, EAT_TXT, EAT_LEN);
	sleep(ar->ptr_philo->v_eat * 1000);
//	return (1);
}

void	*ft_start(void *args)
{
	size_t l;
	size_t r;
	t_args *ar = (t_args *) args;

	l = ar->v_id - 1;
	r = ar->v_id == ar->ptr_philo->v_philos ? 0 : ar->v_id;
	while (!(0x0))
	{
		if (ar->ptr_philo->v_stop)
		{
			write(1, "dead\n", 5);
			break ;
		}
		pthread_mutex_lock(ar->ptr_philo->ptr_mutex[l]);
		ft_print(ar->v_id, FORK_TXT_L, FORK_LEN);
		pthread_mutex_lock(ar->ptr_philo->ptr_mutex[r]);
		ft_print(ar->v_id, FORK_TXT_R, FORK_LEN);
		ft_eat(ar);

		//eat
		//slepp
		//thinking
/*		char *ss = ft_itoa(ft_gettime() - ar->ptr_philo->v_start, 0, 0);
		write(1, ss, strlen(ss));
		write(1, "\n", 1);*/
		pthread_mutex_unlock(ar->ptr_philo->ptr_mutex[l]);
		ft_print(ar->v_id, "v_l\n", 4);
		pthread_mutex_unlock(ar->ptr_philo->ptr_mutex[r]);
		ft_print(ar->v_id, "v_r\n", 4);
		usleep(10);
	}
	return (0x0);
}

void	*ft_monitoring_status_philos(void *args)
{
	t_philo *ar;

	ar = (t_philo *) args;
	while (!(0x0))
	{
		if (ar->v_amount_eat == 2)
			ar->v_stop = 1;
	}
}

int		ft_pthreads_create(t_args **args, t_philo *arr_philos)
{
	unsigned int	i;
	pthread_t		pit;
//	pthread_t		pit_monitoring;
	pthread_t		**pits;

	i = 0;

//	pthread_create(&pit_monitoring, 0x0, ft_monitoring_status_philos, (void *) arr_philos);
	pits = malloc(sizeof(pthread_t*) *arr_philos->v_philos);
	while (i < arr_philos->v_philos)
	{
		arr_philos->ptr_mutex[i] = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(arr_philos->ptr_mutex[i], NULL);
		args[i] = malloc(sizeof(t_args) * arr_philos->v_philos);
		args[i]->ptr_philo = arr_philos;
		args[i]->v_id = i + 1;
		args[i]->v_philo_start = 0;
		i++;
	}
	i = 0;
/*	while (i < arr_philos->v_philos)
	{

		i++;
	}
	i = 0;*/
	while (i < arr_philos->v_philos)
	{
		pthread_create(&pit, 0x0, ft_start, (void *) args[i]);
		pits[i] = &pit;
		args[i]->ptr_threads = pits;
//		usleep(100);
		i++;
	}
	ft_monitoring_status_philos((void *) arr_philos);
	i = 0;
	while (i < arr_philos->v_philos)
	{
		pthread_join(*args[i]->ptr_threads[i], 0x0);
		i++;
	}
//	pthread_join(pit_monitoring, 0x0);
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
	arr_philos->v_stop = 0x0;
	arr_philos->v_start = ft_gettime();
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
