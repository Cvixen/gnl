/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:37:49 by cvixen            #+#    #+#             */
/*   Updated: 2021/10/22 22:15:28 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char	*read_stroky(int fd, char *str)
{
	char	*buf;
	int		write_symbol;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == 0)
		return (NULL);
	write_symbol = 1;
	while (!ft_strchr(str, '\n') && write_symbol)
	
	
}

char	*get_next_line(int fd)
{
	char		*len;
	static char	*str;
	if ( fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = read_stroky(fd, str);
	
}

//int	main ()
//{
//	int	fd;

//	fd = open("text.txt",O_RDONLY);
//	printf("%s",get_next_line(fd));
//}
