/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayeghia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 14:23:06 by sayeghia          #+#    #+#             */
/*   Updated: 2026/03/08 19:09:50 by sayeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(char	*s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);
	return (NULL);
}

char	*ft_join(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

char	*ft_substr(char *place, size_t start, size_t len)
{
	char	*substr;
	size_t	place_len;
	size_t	i;

	i = 0;
	if (!place)
		return (NULL);
	place_len = ft_strlen(place);
	if (start >= place_len)
		return (malloc(1));
	if (len > place_len - start)
		len = place_len - start;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr[i] = place[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
