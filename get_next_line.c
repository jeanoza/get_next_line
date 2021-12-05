/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 09:58:55 by kychoi            #+#    #+#             */
/*   Updated: 2021/12/05 17:13:12 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include<stdio.h>//TO_REMOVE
#include<string.h>//TO_REMOVE

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

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*new_line;
	static char	*backup;
	char		*tmp;

	if (fd < 0)
		return (NULL);
	tmp = NULL;
	if (backup)
		tmp = ft_strndup(backup, ft_strlen(backup));
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		buffer[BUFFER_SIZE] = 0;
		new_line = ft_strchr(buffer, '\n');
		if (new_line)
			backup = &new_line[1];
		if (tmp)
			tmp = ft_strjoin(tmp, buffer);
		else
			tmp = ft_strndup(buffer, ft_strlen(buffer));
		if (ft_strchr(tmp, '\n'))
		{
			*(ft_strchr(tmp, '\n')) = 0;
			return (tmp);
		}
	}
	return (NULL);
}
int	main(void)
{
	// char dst[100];
	// printf("result:%s\n", ft_strncat(dst, "hello", 4));
	
	
	int	fd;
	fd = open("./test.txt", O_RDONLY);
	char *str1 = get_next_line(fd);
	char *str2 = get_next_line(fd);
	char *str3 = get_next_line(fd);
	char *str4 = get_next_line(fd);
	char *str5 = get_next_line(fd);
	//output
	printf("(1st exec)		:%s\n", str1);
	printf("(2nd exec)		:%s\n", str2);

	printf("(3rd exec)		:%s\n", str3);
	printf("(4th exec)		:%s\n", str4);
	printf("(5th exec)		:%s\n", str5);
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
