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

# include "defines.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>

typedef struct			s_philo
{
	size_t				v_philos;
	size_t				v_die;
	size_t				v_eat;
	size_t				v_sleep;
	size_t				v_stop;
	size_t				v_start;
	size_t				v_dead;
	size_t				v_is_eat;
	size_t				v_amount_eat;
	pthread_mutex_t		**ptr_mutex;
}						t_philo;

typedef struct			s_args
{
	size_t				v_id;
	size_t				v_last_eat;
	size_t				v_finsh;
	size_t				v_eaten;
	t_philo				*ptr_philo;
	pthread_t			**ptr_threads;
}						t_args;
typedef struct timeval	t_day;
int						ft_atoi(const char *str);
char					*ft_itoa(size_t n, int v_sig, unsigned int *v_strlen);
char					*ft_str_for_msg(size_t *v_id, char *s1,
						const char *s2, size_t v_s2_len);
char					*ft_join_3_ptr(char *s1, const char *s2,
						char *s3, size_t len);
void					*ft_start(void *args);
int						ft_print(t_args *ar, size_t v_id,
						char *v_str, size_t v_strlen);
size_t					ft_gettime(void);
int						ft_eat(t_args *ar);
void					ft_monitoring_status_philos(t_args **args);
#endif
