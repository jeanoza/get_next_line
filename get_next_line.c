/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 09:58:55 by kychoi            #+#    #+#             */
/*   Updated: 2021/12/10 13:55:21 by kychoi           ###   ########.fr       */
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
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len;
	size_t	i;

	if (s1)
		len = ft_strlen(s1);
	if (s2)
		len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	len = 0;
	while (s1 && s1[len])
	{
		result[len] = s1[len];
		++len;
	}
	i = -1;
	while (s2 && s2[++i])
		result[len++] = s2[i];
	result[len] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	int			ret;
	static char	*backup;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	ret = BUFFER_SIZE;
	while (ret > 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		buffer[ret] = 0;
		tmp = backup;
		backup = ft_strjoin(tmp, buffer);
		// free(tmp);
		if (ft_strchr(backup, '\n'))
			break ;
	}
	tmp = backup;
	if (ft_strchr(tmp, '\n'))
	{
		backup = ft_strchr(tmp, '\n');
		backup++[0] = 0;
	}
	else
		backup = NULL;
	if (tmp)
		return (tmp);
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
	printf("(4th exec)		:%s\n", str4);

	char *str5 = get_next_line(fd);
	printf("(5th exec)		:%s\n", str5);

	char *str6 = get_next_line(fd);
	printf("(6th exec)		:%s\n", str6);

	char *str7 = get_next_line(fd);
	printf("(7th exec)		:%s\n", str7);
	close(fd);
	return (0);
}
*/
//https://github.com/edithturn/42-silicon-valley-gnl/blob/master/get_next_line.c


/*
char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*new_line;
	static char *backup;
	char		*tmp; 
	static int	i = 0; // ******TO_REMOVE

	++i;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	tmp = NULL;
	if (backup)
		tmp = backup;
	new_line = ft_strchr(tmp, '\n');
	while (new_line || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		buffer[BUFFER_SIZE] = 0;
		if (!tmp)
			tmp = ft_strndup(buffer, ft_strlen(buffer));
		else if (!new_line)
			tmp = ft_strjoin(tmp, buffer);
		new_line = ft_strchr(tmp, '\n');
		// printf("[while]tmp:%s	buffer:%s\n", tmp, buffer);
		if (new_line)
		{
			*new_line = 0;
			if (backup)
				free(backup);
			backup = ft_strndup(new_line + 1, ft_strlen(new_line + 1));
			// printf("	[if]tmp:%s	backup:%s	buffer:%s\n", tmp, backup, buffer);
			return (tmp);
		}
	}
	*ft_strchr(tmp, '\0') = 0;
	return (NULL);
}
*/