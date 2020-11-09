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

unsigned int	ft_gettime()
{
	t_day time;

	gettimeofday(&time, 0x0);
	return (time.tv_sec);
}

void			*ft_start(void *args)
{
	unsigned int l;
	unsigned int r;
	t_args *ar = (t_args *) args;

	l = ar->v_id - 1;
	r = ar->v_id == ar->ptr_philo->v_philos ? 0 : ar->v_id;
	while (21)
	{
		pthread_mutex_lock(ar->ptr_philo->ptr_mutex[l]);
		write(1, "left\n", 5);
		pthread_mutex_lock(ar->ptr_philo->ptr_mutex[r]);
		write(1, "right\n", 6);
		ft_putnbr_fd((int)ar->v_id, 1);
		write(1, "\n", 2);
		usleep(42);
		pthread_mutex_unlock(ar->ptr_philo->ptr_mutex[l]);
		pthread_mutex_unlock(ar->ptr_philo->ptr_mutex[r]);
	}
	return (0x0);
}

int				ft_pthreads_create(t_args **args, t_philo *arr_philos)
{
	int				i;
	pthread_t		pit;
	pthread_t		**pits;

	i = 0;
	pits = malloc(sizeof(pthread_t*) *arr_philos->v_philos);
	while (i < arr_philos->v_philos)
	{
		arr_philos->ptr_mutex[i] = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(arr_philos->ptr_mutex[i++], NULL);
	}
	i = 0;
	while (i < arr_philos->v_philos)
	{
		args[i] = malloc(sizeof(t_args) * arr_philos->v_philos);
		args[i]->ptr_philo = arr_philos;
		args[i]->v_id = i + 1;
		i++;
	}
	i = 0;
	while (i < arr_philos->v_philos)
	{
		pthread_create(&pit, 0x0, ft_start, (void *) args[i]);
		pits[i] = &pit;
		args[i]->ptr_threads = pits;
		usleep(2);
		i++;
	}
	i = 0;
	while (i < arr_philos->v_philos)
	{
		pthread_join(*args[i]->ptr_threads[i], 0x0);
		i++;
	}
	return (0);
}

int		ft_init_args(char **argv)
{
	t_args **arr_data;
	t_philo *arr_philos;

	arr_philos = malloc(sizeof(t_philo));
	arr_philos->v_philos = PHS; //ft_atoi(argv[1]);
	arr_philos->v_die = ft_atoi(argv[2]);
	arr_philos->v_eat = ft_atoi(argv[3]);
	arr_philos->v_sleep = ft_atoi(argv[4]);
	arr_philos->v_amount_eat = argv[5] ? ft_atoi(argv[5]) : 0;
	if (arr_philos->v_philos <= 0)
		return (1);
	arr_data = malloc(sizeof(t_args *) * arr_philos->v_philos);
	arr_philos->ptr_mutex = malloc(sizeof(pthread_mutex_t *) * arr_philos->v_philos);
	ft_pthreads_create(arr_data, arr_philos);
	return 0;
}

int		main(int argc, char **argv)
{
	t_args	*args;

	if(argc < 5 || argc > 6 || ft_init_args(argv))
	{
		write(1, "bad args\n", 9);
		return (1);
	}
	return (0);
}