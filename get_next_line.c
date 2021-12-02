/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:21:49 by kyubongchoi       #+#    #+#             */
/*   Updated: 2021/12/02 08:31:53 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include<stdio.h>//TO_REMOVE
#include<string.h>//TO_REMOVE

char	*get_next_line(int fd)
{
	char	*buffer;
	size_t	i;

	if (fd < 0)
		return (NULL);
	i = 0;
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	while (i < BUFFER_SIZE - 1 && read(fd, &buffer[i], 1) == 1 && buffer[i] != '\n')
	{
		// printf("[%zu]\n", i);
		++i;
	}
	//if length == 0, NULL pointer or empty char array?
	if (i == 0)
		return (NULL);
	buffer[i] = 0;
	printf("[%zu]%s(strlen:%lu)\n", i, buffer, strlen(buffer));
	return (buffer);
}

int	main(void)
{
	int	fd;

	fd = open("./test.txt", O_RDONLY);
	/*output*/
	printf("(1st exec)		:%s\n", get_next_line(fd));
	printf("(2st exec)		:%s\n", get_next_line(fd));
	printf("(3st exec)		:%s\n", get_next_line(fd));
	printf("(4st exec)		:%s\n", get_next_line(fd));
	printf("(5st exec)		:%s\n", get_next_line(fd));
	printf("(6st exec)		:%s\n", get_next_line(fd));
	printf("(7st exec)		:%s\n", get_next_line(fd));

	/*compare between output and expected*/
	// printf("(1st exec)		:%d\n", strcmp(get_next_line(fd), "1st line"));
	// printf("(2nd exec)		:%d\n", strcmp(get_next_line(fd), "2nd line"));
	// printf("(3rd exec)		:%d\n", strcmp(get_next_line(fd), "3rd line"));
	// printf("(4th exec)		:%d\n", strcmp(get_next_line(fd), "4th line"));
	// printf("(5th exec)		:%d\n", strcmp(get_next_line(fd), "5th line"));
	close(fd);
	while (1);
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