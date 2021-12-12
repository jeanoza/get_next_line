/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 09:58:55 by kychoi            #+#    #+#             */
/*   Updated: 2021/12/12 17:26:14 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include<stdio.h>//TO_REMOVE
#include<string.h>//TO_REMOVE

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
	{
		free((char *)s1);
		return (NULL);
	}
	len = 0;
	while (s1 && s1[len])
	{
		result[len] = s1[len];
		++len;
	}
	free((char *)s1);
	i = 0;
	while (s2 && s2[i])
		result[len++] = s2[i++];
	result[len] = '\0';
	return (result);
}

char	*ft_select_nl(char *buffer, char *new_line)
{
	int		i;
	int		len;
	char	*dst;

	if (buffer[0] == '\0')
		return (NULL);
	if (buffer[0] == '\n')
		return (ft_strndup("\n", 1));
	if (new_line)
		len = new_line - buffer + 1;
	else
		len = ft_strlen(buffer);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len && buffer[i])
	{
		dst[i] = buffer[i];
		++i;
	}
	dst[i] = 0;
	return (dst);
}

char	*ft_move_cursor(char *buffer)
{
	int		i;
	int		j;
	char	*dst;

	if (buffer && (buffer[0] == 0 || ft_strlen(buffer) == 1))
	{
		free(buffer);
		return (NULL);
	}
	j = 0;
	while (buffer && (buffer)[j] && (buffer)[j] != '\n')
		++j;
	dst = malloc(sizeof(char) * (ft_strlen(buffer) - j + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (buffer && (buffer)[j + i])
	{
		dst[i] = (buffer)[j + i + 1];
		++i;
	}
	dst[i] = 0;
	free(buffer);
	return (dst);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	int			cursor;
	static char	*backup;
	char		*current;
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	cursor = BUFFER_SIZE;
	while (cursor > 0)
	{
		cursor = read(fd, buffer, BUFFER_SIZE);
		if (cursor == -1)
			return (NULL);
		buffer[cursor] = 0;
		backup = ft_strjoin(backup, buffer);
		if (cursor == 0 && ft_strchr(backup, '\n'))
			break ;
	}
	new_line = ft_strchr(backup, '\n');
	current = ft_select_nl(backup, new_line);
	backup = ft_move_cursor(backup);
	return (current);
}
/*
int	main(void)
{
	int	fd;
	fd = open("./test.txt", O_RDONLY);
	char *str1 = get_next_line(fd);
	printf("(1st exec)		:%s\n\n", str1);

	char *str2 = get_next_line(fd);
	printf("(2st exec)		:%s\n\n", str2);

	char *str3 = get_next_line(fd);
	printf("(3rd exec)		:%s\n\n", str3);

	char *str4 = get_next_line(fd);
	printf("(4th exec)		:%s\n\n", str4);

	char *str5 = get_next_line(fd);
	printf("(5th exec)		:%s\n\n", str5);

	char *str6 = get_next_line(fd);
	printf("(6th exec)		:%s\n\n", str6);

	char *str7 = get_next_line(fd);
	printf("(7th exec)		:%s\n\n", str7);
	// while (1)
	// 	;
	close(fd);
	return (0);
}
*/