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

void	ft_wait(t_main *v_main)
{
	int		v_return_value;
	size_t	v_amount_eat;

	v_amount_eat = 0;
	while (!(0x0))
	{
		waitpid(-1, &v_return_value, 0);
		v_return_value = WEXITSTATUS(v_return_value);
		if (v_return_value == 12)
			v_amount_eat++;
		else
		{
			v_amount_eat &= (size_t)0;
			while (v_main->v_pids[v_amount_eat])
				kill(v_main->v_pids[v_amount_eat++], SIGKILL);
			exit(13);
		}
		if (v_amount_eat == v_main->v_philos)
		{
			v_amount_eat &= (size_t)0;
			while (v_main->v_pids[v_amount_eat])
				kill(v_main->v_pids[v_amount_eat++], SIGKILL);
			exit(0);
		}
	}
}

int		ft_pids_create(t_main *v_main, t_args *v_data)
{
	int i;

	if (!(v_data->v_start = ft_gettime()))
		return (1);
	v_data->v_last_eat = v_data->v_start;
	i = -1;
	while (++i < (int)v_data->v_philos)
	{
		v_main->v_pids[i] = fork();
		if (v_main->v_pids[i] == 0)
		{
			v_data->v_id = i + 1;
			ft_start(v_data);
			exit(0);
		}
		else if (v_main->v_pids[i] < 0)
		{
			while (i != -1 && v_main->v_pids[i])
				kill(v_main->v_pids[i--], SIGKILL);
			exit(13);
		}
	}
	ft_wait(v_main);
	return (0);
}

int		ft_init_args(char **argv, t_main *v_main, t_args *v_data)
{
	v_data->v_philos = ft_atoi(argv[1]);
	v_data->v_die = ft_atoi(argv[2]);
	v_data->v_eat = ft_atoi(argv[3]);
	v_data->v_sleep = ft_atoi(argv[4]);
	v_data->v_amount_eat = argv[5] ? ft_atoi(argv[5]) : 0;
	v_data->v_is_eat = argv[5] ? 1 : 0;
	v_data->v_stop = 0x0;
	v_data->v_start = 0x0;
	v_data->v_dead = 0x0;
	v_data->v_last_eat = 0x0;
	v_data->v_eaten = v_data->v_amount_eat;
	v_main->v_philos = v_data->v_philos;
	if ((v_data->v_philos <= 0) ||
	!(v_main->v_pids = malloc(sizeof(pid_t) * (v_data->v_philos + 1))))
		return (1);
	v_main->v_pids[v_data->v_philos] = 0x0;
	sem_unlink(SEMEAT);
	sem_unlink(SEMPRINT);
	v_data->v_mutex =
			sem_open(SEMEAT, O_CREAT, S_IWUSR, v_data->v_philos);
	v_data->v_mutex_print =
			sem_open(SEMPRINT, O_CREAT, S_IWUSR, 1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_main	v_main;
	t_args	*v_data;

	if (argc < 5 || argc > 6)
	{
		write(1, "bad args\n", 9);
		return (1);
	}
	if (!(v_data = malloc(sizeof(t_args)))
	|| ft_init_args(argv, &v_main, v_data))
		exit(1);
	ft_pids_create(&v_main, v_data);
	return (ft_free_xxx(&v_main, v_data));
}
