/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizola <mizola@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 03:25:14 by mizola            #+#    #+#             */
/*   Updated: 2020/05/02 05:24:27 by mizola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t		ft_strlen(const char *str)
{
	size_t index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

size_t		ft_strlen_null(const char *str)
{
	size_t index;

	index = 0;
	while (str && str[index] != '\0')
		index++;
	return (index);
}
