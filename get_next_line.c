/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 09:58:55 by kychoi            #+#    #+#             */
/*   Updated: 2021/12/11 01:21:35 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include<stdio.h>//TO_REMOVE
#include<string.h>//TO_REMOVE

char	*ft_strjoin(char *s1, char const *s2)
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
		if (ft_strchr(backup, '\n'))
			break ;
		if (ret == 0 && ft_strchr(backup, '\0'))
		{
			backup = NULL;
			return (tmp);
		}
	}
	tmp = backup;
	if (ft_strchr(tmp, '\n'))
	{
		backup = ft_strchr(tmp, '\n');
		backup++[0] = 0;
		free(tmp);
		return (tmp);
	}
	return (NULL);
}
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
//https://github.com/edithturn/42-silicon-valley-gnl/blob/master/get_next_line.c
