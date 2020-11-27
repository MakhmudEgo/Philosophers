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

int			ft_free_xxx(t_main *v_main, t_args *v_data)
{
	sem_unlink(SEMEAT);
	sem_unlink(SEMPRINT);
	sem_close(v_data->v_mutex);
	sem_close(v_data->v_mutex_print);
	free(v_main->v_pids);
	free(v_data);
	exit(0);
	return (0);
}
