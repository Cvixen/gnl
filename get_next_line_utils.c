/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:54:44 by cvixen            #+#    #+#             */
/*   Updated: 2021/10/22 21:11:56 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	char	*str;

	str = (char *)s;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (c == '\0')
		return (str);
	else
		return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*strjoin;
	size_t		strjoinlen;
	size_t		i;
	size_t		j;

	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	strjoinlen = ft_strlen(s1) + ft_strlen(s2) + 1;
	strjoin = (char *)malloc(strjoinlen);
	if (!strjoin)
		return (0);
	i = -1;
	while (s1[++i])
		strjoin[i] = s1[i];
	while (s2[j])
		strjoin[i++] = s2[j++];
	strjoin[i] = 0;
	free(s1);
	return (strjoin);
}
