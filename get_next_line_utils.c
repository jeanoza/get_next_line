/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:27:48 by kyubongchoi       #+#    #+#             */
/*   Updated: 2021/12/03 00:57:19 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(const char *src, size_t len)
{
	char	*dst;
	size_t	i;

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
		if (i == (int) ft_strlen((char*) s))
			return (0);
		++i;
	}
	return ((char *)(s + i));
}

void	*ft_memset(void *b, int c, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		((char *) b)[i] = c;
		++i;
	}
	return (b);
}
