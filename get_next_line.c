/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:21:49 by kyubongchoi       #+#    #+#             */
/*   Updated: 2021/12/02 08:12:46 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include<stdio.h>//TO_REMOVE
#include<string.h>//TO_REMOVE

char	*get_next_line(int fd)
{
	char	*buffer;
	char	tmp;
	size_t	i;

	if (fd < 0)
		return (NULL);
	i = 0;
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	while (read(fd, &tmp, 1) == 1)
	{
		if (tmp == '\n')
		{
			buffer[i] = 0;
			// printf("[%zu]%d(strlen:%lu)\n", i, buffer[i], strlen(buffer));
			return (buffer);
		}
		buffer[i] = tmp;
		// printf("[%zu]%c\n", i, buffer[i]);
		++i;
	}
	return (NULL);
}

int	main(void)
{
	int	fd;

	fd = open("./test.txt", O_RDONLY);
	printf("(1st exec)		:%d\n", strcmp(get_next_line(fd), "1st line"));
	printf("(2nd exec)		:%d\n", strcmp(get_next_line(fd), "2nd line"));
	printf("(3rd exec)		:%d\n", strcmp(get_next_line(fd), "3rd line"));
	printf("(4th exec)		:%d\n", strcmp(get_next_line(fd), "4th line"));
	printf("(5th exec)		:%d\n", strcmp(get_next_line(fd), "5th line"));
	printf("(6st exec)		:%s\n", get_next_line(fd));
	close(fd);
	return (0);
}

//bonus??
/*
void	*ft_realloc(void *ptr, size_t size)
{
	free(ptr);
	return (malloc(size));
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	tmp;
	size_t	i;

	if (fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char));
	i = 0;
	while (read(fd, &tmp, 1) == 1)
	{
		buffer = ft_realloc(buffer, i + 1);
		if (!buffer)
			return (NULL);
		if (tmp == '\n')
		{
			buffer[i] = '\0';
			printf("[%zu]%d(strlen:%lu)\n", i, buffer[i], strlen(buffer));
			return (buffer);
		}
		buffer[i++] = tmp;
		printf("[%zu]%c\n", i - 1, buffer[i - 1]);
	}
	return (NULL);
}
*/