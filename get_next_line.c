/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 09:58:55 by kychoi            #+#    #+#             */
/*   Updated: 2021/12/09 14:01:42 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include<stdio.h>//TO_REMOVE
#include<string.h>//TO_REMOVE

void	ft_bzero(void *s, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		++i;
	}
}
char	*ft_strncat(char *dest, char *src, size_t nb)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*(dest + i))
		++i;
	j = 0;
	while (j < nb && *(src + j))
	{
		*(dest + i + j) = *(src + j);
		++j;
	}
	*(dest + i + j) = '\0';
	return (dest);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	j = -1;
	while (s2[++j])
		result[i + j] = s2[j];
	result[i + j] = '\0';
	return (result);
}

int	get_new_line_idx(char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (i);
		++i;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*new_line;
	static char	*backup;
	char		*tmp;
	// static int	i = 0; //******TO_REMOVE

	// ++i;
	// printf("\n(**start_point** => %d)\nbackup:%s\n", i, backup);
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	tmp = NULL;
	new_line = NULL;
	if (backup && ft_strlen(backup) > 0)
	{
		tmp = backup;
		new_line = ft_strchr(tmp, '\n');
	}
	// printf("[%d]buffer:%s\n", i, buffer);
	while (new_line || (read(fd, buffer, BUFFER_SIZE) > 0 && !new_line))
	{
		buffer[BUFFER_SIZE] = 0;
		if (!tmp)
			tmp = ft_strndup(buffer, ft_strlen(buffer));
		else if (!new_line)
			tmp = ft_strjoin(tmp, buffer);
		// printf("[while]tmp:%s\n", tmp);
		new_line = ft_strchr(tmp, '\n');
		if (new_line)
		{
			*new_line = 0;
			if (backup)
				free(backup);
			backup = ft_strndup(new_line + 1, ft_strlen(new_line + 1));
			return (tmp);
		}
	}
	// if (backup)
	// 	free(backup);
	return (NULL);
}
/*
int	main(void)
{
	int	fd;
	fd = open("./test.txt", O_RDONLY);
	char *str1 = get_next_line(fd);
	printf("(1st exec)		:%s\n", str1);

	char *str2 = get_next_line(fd);
	printf("(2st exec)		:%s\n", str2);

	char *str3 = get_next_line(fd);
	printf("(3rd exec)		:%s\n", str3);

	char *str4 = get_next_line(fd);
	printf("(4rd exec)		:%s\n", str4);

	char *str5 = get_next_line(fd);
	printf("(5rd exec)		:%s\n", str5);
	close(fd);
	return (0);
}
//https://github.com/edithturn/42-silicon-valley-gnl/blob/master/get_next_line.c
*/