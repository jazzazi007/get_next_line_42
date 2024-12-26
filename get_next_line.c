/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaljazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:49:24 by moaljazz          #+#    #+#             */
/*   Updated: 2024/10/27 23:49:27 by moaljazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*allocate_buffer(void)
{
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	return (buffer);
}

char	*save_data(char *saved_data, char *buffer)
{
	char	*dup;

	if (saved_data)
	{
		dup = ft_strjoin(saved_data, buffer);
		free(saved_data);
		saved_data = dup;
	}
	else
		saved_data = ft_strdup(buffer);
	return (saved_data);
}

char	*extract_line(char **saved_data)
{
	char	*newline_ptr;
	int		len_to_newline;
	char	*line;
	char	*temp;

	newline_ptr = ft_strchr(*saved_data, '\n');
	if (newline_ptr)
	{
		len_to_newline = newline_ptr - *saved_data + 1;
		line = ft_strndup(*saved_data, len_to_newline);
		temp = ft_strdup(newline_ptr + 1);
		free(*saved_data);
		*saved_data = temp;
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*saved_data;
	char		*buffer;
	char		*line;
	int			bytes_read;

	buffer = allocate_buffer();
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while ((bytes_read) > 0)
	{
		buffer[bytes_read] = '\0';
		saved_data = save_data(saved_data, buffer);
		line = extract_line(&saved_data);
		if (line)
			return (free(buffer), line);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (fd < 0 || bytes_read < 0 || (!saved_data || !*saved_data))
		return (free(buffer), free(saved_data), saved_data = NULL, NULL);
	line = extract_line(&saved_data);
	if (line)
		return (free(buffer), line);
	line = ft_strdup(saved_data);
	return (free(buffer), free(saved_data), saved_data = NULL, line);
}
