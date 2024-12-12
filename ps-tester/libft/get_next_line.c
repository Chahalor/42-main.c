/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:39:16 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/20 12:35:50 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*line_getter(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*update_remainder(char *str)
{
	int		i;
	int		j;
	char	*remainder;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || !str[i + 1])
	{
		free(str);
		return (NULL);
	}
	remainder = (char *)malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!remainder)
		return (NULL);
	i++;
	while (str[i])
		remainder[j++] = str[i++];
	remainder[j] = '\0';
	free(str);
	return (remainder);
}

static char	*read_and_store(int fd, char *remainder)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0 && remainder)
			return (free(buffer), free(remainder), NULL);
		else if (bytes_read < 0)
			return (free(buffer), NULL);
		buffer[bytes_read] = '\0';
		remainder = str_join(remainder, buffer);
		if (!remainder)
			return (free(buffer), free(remainder), NULL);
		if (bytes_read == 0 || (bytes_read > 0 && remainder
				&& (ft_strchr(remainder, '\n'))))
			break ;
	}
	free(buffer);
	return (remainder);
}

/**
 * @file get_next_line.c
 * @brief Read a line from a file descriptor
 * @author nduvoid
 * 
 * @param fd File descriptor
 * @return The line read from the file descriptor, NULL if an error occurs
 * or the end of the file is reached
 */
char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = read_and_store(fd, remainder);
	if (!remainder || remainder[0] == '\0')
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	line = line_getter(remainder);
	remainder = update_remainder(remainder);
	return (line);
}
