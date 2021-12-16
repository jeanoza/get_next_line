/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:27:48 by kyubongchoi       #+#    #+#             */
/*   Updated: 2021/12/16 22:19:19 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strjoin(const char *s1, const char *s2)
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
