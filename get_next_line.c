/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 09:58:55 by kychoi            #+#    #+#             */
/*   Updated: 2021/12/11 15:06:27 by kyubongchoi      ###   ########.fr       */
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

char	*ft_select_nl(char *buffer, int *cursor)
{
	int		i;
	char	*dst;

	i = 0;
	while (buffer && buffer[i] && buffer[i] != '\n')
		++i;
	*cursor = i;
	dst = malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (buffer && buffer[i] && buffer[i] != '\n')
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

	i = 0;
	while (buffer && buffer[i] && buffer[i] != '\n')
		++i;
	dst = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!dst)
		return (NULL);
	j = 0;
	while (buffer && buffer[i])
		dst[j++] = buffer[++i];
	dst[j] = 0;
	return (dst);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	int			cursor;
	static char	*backup;
	char		*tmp;
	char		*line;


	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	cursor = BUFFER_SIZE;
	while (cursor > 0)
	{
		cursor = read(fd, buffer, BUFFER_SIZE);
		if (cursor == -1)
			return (NULL);
		buffer[cursor] = 0;
		tmp = backup;
		backup = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_strchr(backup, '\n'))
			break ;
	}
	line = ft_select_nl(backup, &cursor);
	tmp = backup;
	backup = ft_move_cursor(tmp);
	printf("backup[%p] tmp[%p] chr_n[%p] chr_0[%p] line[%p]%d cursor:%d\n", backup, tmp, ft_strchr(backup, '\n'), ft_strchr(backup, '\0'), line, *line, cursor);
	free(tmp);
	// printf("backup[%p]:%s(%d)\n", backup,backup,*backup);
	if (cursor == 0 && backup[0] == 0)
	{
		printf("here\n");
		free(backup);
		backup = NULL;
	}
	return (line);
}
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
	close(fd);
	return (0);
}
//https://github.com/edithturn/42-silicon-valley-gnl/blob/master/get_next_line.c