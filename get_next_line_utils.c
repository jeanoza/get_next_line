/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:27:48 by kyubongchoi       #+#    #+#             */
/*   Updated: 2021/12/03 19:48:07 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(const char *src, size_t len)
{
	char	*dst;
	size_t	i;

	if (len == 0)
		return ((void *) 0);
	dst = malloc(sizeof(char) * (len + 1));
	if (dst)
	{
		i = 0;
		while (i < len && src[i])
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
		return (dst);
	}
	return ((void *) 0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*(s + i) != (char) c)
	{
		if (i == (int) ft_strlen((char *) s))
			return (0);
		++i;
	}
	return ((char *)(s + i));
}