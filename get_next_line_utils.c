/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:27:48 by kyubongchoi       #+#    #+#             */
/*   Updated: 2021/12/10 21:12:41 by kyubongchoi      ###   ########.fr       */
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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		++i;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (*(s + i) != (char) c)
	{
		if (i == (int) ft_strlen((char *) s))
			return (0);
		++i;
	}
	return ((char *)(s + i));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s)
	{
		if (start >= ft_strlen(s))
			len = 0;
		if (len > ft_strlen(s))
			len = ft_strlen(s);
		str = malloc(sizeof(char) * (len + 1));
		if (str)
		{
			i = 0;
			while (i < len && s[i])
			{
				str[i] = s[start + i];
				++i;
			}
			str[i] = 0;
			return (str);
		}
	}
	return (NULL);
}