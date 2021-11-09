/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:52:12 by cvixen            #+#    #+#             */
/*   Updated: 2021/11/08 19:57:55 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*trim_linebreak(char *str)
{
	int		i;
	char	*line;
	int		j;

	i = 0;
	line = ft_strdup(str);
	if (line == 0)
		return (NULL);
	while (str[i] != '\n')
		i++;
	i++;
	line[i] = '\0';
	j = 0;
	while (str[i + j])
	{
		str[j] = str[i + j];
		j++;
	}
	str[j] = '\0';
	return (line);
}

char	*read_line(char *remainder, int fd, int read_symbol)
{
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!is_has_linebreak(remainder))
	{
		read_symbol = read(fd, buff, BUFFER_SIZE);
		if (read_symbol < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[read_symbol] = '\0';
		if (read_symbol == 0)
			break ;
		remainder = ft_strjoin(remainder, buff);
		if (remainder == 0)
		{
			free(buff);
			return (NULL);
		}
	}
	free(buff);
	return (remainder);
}

void	free_remainder(char **remainder)
{
	free(*remainder);
	*remainder = 0;
}

char	*get_next_line(int fd)
{
	static char	*remainder[1024];
	char		*line;

	if (fd < 0 || fd > 1024)
		return (NULL);
	remainder[fd] = read_line(remainder[fd], fd, 0);
	if (!remainder[fd])
		return (0);
	if (is_has_linebreak(remainder[fd]))
	{
		line = trim_linebreak(remainder[fd]);
		if (line == 0)
		{
			free_remainder(&remainder[fd]);
			return (NULL);
		}
		if (*remainder[fd] == '\0')
			free_remainder(&remainder[fd]);
	}
	else
	{
		line = remainder[fd];
		remainder[fd] = 0;
	}
	return (line);
}
