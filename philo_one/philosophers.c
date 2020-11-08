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

	l = ar->id;
	r = ar->id + 1 == ar->t_philos ? 0 : ar->id;
	while (21)
	{
		pthread_mutex_lock(&ar->mutex[l]);
		pthread_mutex_lock(&ar->mutex[r]);
		ft_putnbr_fd(ar->id, 1);
		write(1, "\n", 1);
		pthread_mutex_unlock(&ar->mutex[l]);
		pthread_mutex_unlock(&ar->mutex[r]);
	}
}

int				ft_pthreads_create(t_args *args)
{
	int			i;
	pthread_t	pit;

	i = 0;
	while (i < args->t_philos)
		pthread_mutex_init(&args->mutex[i++], NULL);
	i = 0;
	while (i < args->t_philos)
	{
		args->id = i + 1;
		pthread_create(&pit, 0x0, ft_start, (void *) args);
		usleep(43);
		args->thread[i++] = pit;
	}
	i = 0;
	while (i < args->t_philos)
	{
		pthread_join(args->thread[i++], 0x0);
	}
	return (0);
}

int		ft_init_args(t_args *args, char **argv)
{
	args->start = ft_gettime();
	if ((args->t_philos = ft_atoi(argv[1])) <= 0)
		return (1);
	args->t_die = ft_atoi(argv[2]);
	args->t_eat = ft_atoi(argv[3]);
	args->t_sleep = ft_atoi(argv[4]);
	args->t_amount_eat = argv[5] ? ft_atoi(argv[5]) : 0;
	args->thread = malloc(sizeof(pthread_t) * args->t_philos);
	args->mutex = malloc(sizeof(pthread_mutex_t) * args->t_philos);
	ft_pthreads_create(args);
	return 0;
}

int		main(int argc, char **argv)
{
	t_args	args;

	if(argc < 5 || argc > 6 || ft_init_args(&args, argv))
	{
		write(1, "bad args\n", 9);
		return (1);
	}
	return (0);
}