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

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>


typedef struct			s_args
{
	unsigned int		start;
	unsigned int		id;
	unsigned int		t_philos;
	unsigned int		t_die;
	unsigned int		t_eat;
	unsigned int		t_sleep;
	unsigned int		t_amount_eat;
	pthread_t			*thread;
	pthread_mutex_t		*mutex;
}						t_args;

typedef struct timeval	t_day;
typedef struct timezone	t_zone;
int						ft_atoi(const char *str);
void					ft_putnbr_fd(int n, int fd);

#endif
