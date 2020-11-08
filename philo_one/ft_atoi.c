/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizola <mizola@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 15:42:07 by mizola            #+#    #+#             */
/*   Updated: 2020/05/14 20:16:39 by mizola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	get_str_without_signs(const char *str, int *k, unsigned int *index)
{
	while ((str[*index] == ' ' || str[*index] == '\t'
		|| str[*index] == '\v' || str[*index] == '\f'
		|| str[*index] == '\r' || str[*index] == '\n')
		&& str[*index])
	{
		*index += 1;
	}
	if (str[*index] == '-' || str[*index] == '+')
	{
		if (str[*index] == '-')
			*k = -1;
		*index += 1;
	}
	while (str[*index] == '0' && str[*index])
		*index += 1;
}

int			ft_atoi(const char *str)
{
	unsigned int	index;
	long int		number;
	int				k;
	long int		old_number;
	unsigned int	lim;

	index = 0;
	number = 0;
	k = 1;
	lim = 0;
	get_str_without_signs(str, &k, &index);
	while (str[index] <= '9' && str[index] >= '0')
	{
		old_number = k * number;
		number = (number * 10) + (str[index] - '0');
		if ((old_number < 0 && number * k > 0)
			|| (old_number < 0 && lim > 18))
			return (0);
		if ((old_number > 0 && number * k < 0)
			|| (old_number > 0 && lim > 18))
			return (-1);
		index++;
		lim++;
	}
	return (number * k);
}
