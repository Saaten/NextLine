/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayeghia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:25:28 by sayeghia          #+#    #+#             */
/*   Updated: 2026/03/08 19:03:54 by sayeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*read_to_somewhere(int fd, char *place)
{
	char	*buffer;
	int		bytes;

	bytes = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(place, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			free(place);
			place = NULL;
			return (NULL);
		}
		buffer[bytes] = '\0';
		place = ft_join(place, buffer);
	}
	free (buffer);
	return (place);
}

char	*ft_get_line(char *place)
{
	char	*line;
	int		i;

	i = 0;
	while (place[i] && place[i] != '\n')
		i++;
	if (place[i] == '\n')
		i++;
	line = ft_substr(place, 0, i);
	return (line);
}

char	*clean_place(char *place)
{
	char	*cleaned;
	int		i;

	i = 0;
	if (!place)
		return (NULL);
	while (place[i] && place[i] != '\n')
		i++;
	if (!place[i])
	{
		free(place);
		return (NULL);
	}
	cleaned = ft_substr(place, i + 1, ft_strlen(place) - i);
	free (place);
	return (cleaned);
}

char	*get_next_line(int fd)
{
	static char	*place;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	place = read_to_somewhere(fd, place);
	if (!place)
		return (NULL);
	if (place[0] == '\0')
	{
		free(place);
		place = NULL;
		return (NULL);
	}
	line = ft_get_line(place);
	if (!line)
		return (free (place), NULL);
	place = clean_place(place);
	return (line);
}

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = 0;
	if (size == 0)
		return (src_len + dst_len);
	if (dst_len >= size)
		return (src_len + size);
	while (src[i] && i + dst_len < size - 1)
	{
		dst[i + dst_len] = src[i];
		i++;
	}
	dst[i + dst_len] = '\0';
	return (dst_len + src_len);
}
