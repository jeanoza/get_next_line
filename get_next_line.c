/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 09:58:55 by kychoi            #+#    #+#             */
/*   Updated: 2021/12/04 17:51:16 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include<stdio.h>//TO_REMOVE
#include<string.h>//TO_REMOVE

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	static size_t	i;
	char			*new_line;
	char			*tmp;

	if (fd < 0)
		return (NULL);
	i = 0;
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		// new_line = ft_strchr(buffer, '\n');
		// i = 0;
		printf("\n(%zu):%s\n", i, buffer);
		++i;
	}

	return (buffer);
}


int	main(void)
{
	int	fd;


	fd = open("./test.txt", O_RDONLY);
	char *str1 = get_next_line(fd);
	char *str2 = get_next_line(fd);
	char *str3 = get_next_line(fd);
	char *str4 = get_next_line(fd);
	char *str5 = get_next_line(fd);
	//output
	// printf("(1st exec)		:%s\n", str1);
	// printf("(2nd exec)		:%s\n", str2);
	// printf("(3rd exec)		:%s\n", str3);
	// printf("(4th exec)		:%s\n", str4);
	// printf("(5th exec)		:%s\n", str5);
	//compare between output and expected
	// printf("(1st exec)		:%d\n", strcmp(get_next_line(fd), "1st line"));
	// printf("(2nd exec)		:%d\n", strcmp(get_next_line(fd), "2nd line"));
	// printf("(3rd exec)		:%d\n", strcmp(get_next_line(fd), "3rd line"));
	// printf("(4th exec)		:%d\n", strcmp(get_next_line(fd), "4th line"));
	// printf("(5th exec)		:%d\n", strcmp(get_next_line(fd), "5th line"));
	close(fd);
	return (0);
}

//https://github.com/edithturn/42-silicon-valley-gnl/blob/master/get_next_line.c