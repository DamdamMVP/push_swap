/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 08:59:12 by dalebran          #+#    #+#             */
/*   Updated: 2024/10/26 23:05:40 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#ifndef MAX_FD
# define MAX_FD 1024
#endif

char	*read_and_concat(int fd, char *remainder, int *eof)
{
	char	*buffer;
	int		bytes_read;
	char	*tmp;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(buffer);
		free(remainder);
		return (NULL);
	}
	if (bytes_read == 0)
	{
		*eof = 1;
		free(buffer);
		return (remainder);
	}
	buffer[bytes_read] = '\0';
	tmp = ft_strjoin(remainder, buffer);
	free(remainder);
	free(buffer);
	return (tmp);
}

char	*extract_line(char **remainder)
{
	char	*newline_pos;
	char	*line;

	newline_pos = ft_strchr(*remainder, '\n');
	if (newline_pos)
	{
		line = ft_substr(*remainder, 0, newline_pos - *remainder + 1);
		ft_memmove(*remainder, newline_pos + 1, ft_strlen(newline_pos + 1) + 1);
	}
	else
	{
		line = ft_strdup(*remainder);
		free(*remainder);
		*remainder = NULL;
	}
	return (line);
}

char	*get_line_from_remainder(char **remainder, int fd)
{
	char	*newline_pos;
	int		eof;

	newline_pos = ft_strchr(*remainder, '\n');
	eof = 0;
	while (!newline_pos && !eof)
	{
		*remainder = read_and_concat(fd, *remainder, &eof);
		if (!*remainder)
			return (NULL);
		newline_pos = ft_strchr(*remainder, '\n');
	}
	if (!newline_pos && !**remainder)
	{
		free(*remainder);
		*remainder = NULL;
		return (NULL);
	}
	return (extract_line(remainder));
}

char	*ft_get_next_line(int fd)
{
	static char	*remainder[MAX_FD];

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		if (remainder[fd])
		{
			free(remainder[fd]);
			remainder[fd] = NULL;
		}
		return (NULL);
	}
	if (!remainder[fd])
		remainder[fd] = ft_strdup("");
	return (get_line_from_remainder(&remainder[fd], fd));
}
