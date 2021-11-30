/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:21:49 by kyubongchoi       #+#    #+#             */
/*   Updated: 2021/11/30 23:02:22 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include<stdio.h>//TO_REMOVE

char	*get_next_line(int fd)
{
	char	*buffer;
	char	c;
	size_t	i;

	if (fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	i = 0;
	while (read(fd, &c, 1) == 1)
	{
		if (c == '\n')
		{
			buffer[i] = 0;
			return (buffer);
		}
		buffer[i++] = c;
	}
	return (NULL);
}

int	main(void)
{
	int	fd;

	fd = open("./test.txt", O_RDONLY);
	printf("(1st exec)		%s\n", get_next_line(fd));
	printf("(2st exec)		%s\n", get_next_line(fd));
	printf("(3st exec)		%s\n", get_next_line(fd));
	printf("(4st exec)		%s\n", get_next_line(fd));
	close(fd);
	return (0);
}