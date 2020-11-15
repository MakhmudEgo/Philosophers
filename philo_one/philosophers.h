/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizola <mizola@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:01:04 by mizola            #+#    #+#             */
/*   Updated: 2020/11/03 21:01:13 by mizola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILOSOPHERS_PHILOSOPHERS_H
# define PHILOSOPHERS_PHILOSOPHERS_H
# define SECOND 1000000
# define MILLISECOND 1000
# define PHS 4

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>

typedef struct			s_philo
{
	unsigned int		v_philos;
	unsigned int		v_die;
	unsigned int		v_eat;
	unsigned int		v_sleep;
	unsigned int		v_stop;
	unsigned long long	v_start;
	unsigned int		v_amount_eat;
	pthread_mutex_t		**ptr_mutex;
}						t_philo;

typedef struct			s_args
{
	unsigned int		v_philo_start;
	unsigned int		v_id;
	t_philo				*ptr_philo;
	pthread_t			**ptr_threads;
}						t_args;

typedef struct timeval	t_day;
typedef struct timezone	t_zone;
int						ft_atoi(const char *str);
void					ft_putnbr_fd(int n, int fd);
char					*ft_itoa(int n);

#endif