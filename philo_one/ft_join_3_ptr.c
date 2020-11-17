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

char	*ft_join_3_ptr(char *s1, const char *s2, char *s3, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = 0;
	str = (char*)malloc(len);
	if (str == NULL)
		return (NULL);
	while (s1 && s1[n] != '\0')
		str[i++] = s1[n++];
	n = 0;
	while (s2 && s2[n] != '\0')
		str[i++] = s2[n++];
	n = 0;
	while (s3 && s3[n] != '\0')
		str[i++] = s3[n++];
	str[i] = '\0';
	free(s1);
	free(s3);
	return (str);
}
