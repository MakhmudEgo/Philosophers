/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizola <mizola@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 17:28:02 by mizola            #+#    #+#             */
/*   Updated: 2020/05/14 20:16:52 by mizola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

char	*ft_str_for_msg(size_t *v_id, char *s1, const char *s2, size_t v_s2_len)
{
	char			*str;
	unsigned int	i;
	unsigned int	n;

	i = 0;
	s1 = ft_itoa(*v_id, 1, &i);
	if (!s1)
		return (NULL);
	*v_id = i + v_s2_len + 1;
	i = 0;
	n = 0;
	str = (char*)malloc(*v_id);
	if (!str)
		return (NULL);
	while (s1[n] != '\0')
		str[i++] = s1[n++];
	n = 0;
	while (s2 && s2[n] != '\0')
		str[i++] = s2[n++];
	str[i] = '\0';
	free(s1);
	return (str);
}
