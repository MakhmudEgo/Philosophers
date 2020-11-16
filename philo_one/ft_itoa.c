/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizola <mizola@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 14:44:26 by mizola            #+#    #+#             */
/*   Updated: 2020/05/11 23:13:15 by mizola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static size_t	num_len(size_t n)
{
	size_t i;
	size_t tmp;

	i = 0;
	tmp = n;
	if (n < 0)
	{
		i++;
		tmp *= (-1);
	}
	while (tmp >= 10)
	{
		tmp /= 10;
		i++;
	}
	return (i + 2);
}

static void	push_char(char *s, size_t n, size_t i)
{
	size_t res;

	res = n;
	s[--i] = '\0';
	while (res)
	{
		s[--i] = res % 10 + '0';
		res /= 10;
	}
}

char		*ft_itoa(size_t n, int v_sig, unsigned int *v_strlen)
{
	char	*res;
	size_t	i;

	i = num_len(n);
	res = malloc(sizeof(char) * i);
	if (res == NULL)
		return (NULL);
	if (n == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	push_char(res, n, i);
	if (v_sig)
		*v_strlen = --i;
	return (res);
}
