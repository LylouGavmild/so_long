/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:05:23 by abutet            #+#    #+#             */
/*   Updated: 2023/12/29 14:42:16 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_clean_up(char **_buffer, int len)
{
	char	*rest;
	int		i;

	rest = (char *)malloc(ft_strl(*_buffer) - len + 1);
	if (!rest)
		return (0);
	i = len;
	while ((*_buffer)[i])
	{
		rest[i - len] = (*_buffer)[i];
		i++;
	}
	rest[i - len] = '\0';
	free (*_buffer);
	*_buffer = rest;
	return (1);
}

static char	*ft_create_line(char **_buffer)
{
	char	*line;
	int		len;
	int		i;

	len = 0;
	while ((*_buffer)[len] && (*_buffer)[len] != '\n')
		len++;
	if ((*_buffer)[len] == '\n')
		len++;
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = (*_buffer)[i];
		i++;
	}
	line[i] = '\0';
	if ((ft_clean_up(_buffer, len) == 0 || i == 0) && ft_free_return(line) == 0)
		return (NULL);
	return (line);
}

static int	ft_super_malloc(char **_buffer, int *size, int *len)
{
	char	*new_buffer;
	int		i;

	if (*len + BUFFER_SIZE < *size)
		return (*len);
	while (*size < BUFFER_SIZE)
		*size = *size * 2 + 1;
	new_buffer = (char *)malloc(*size * 2 + 1);
	if (!new_buffer)
		return (-1);
	i = 0;
	while (*_buffer && (*_buffer)[i])
	{
		new_buffer[i] = (*_buffer)[i];
		i++;
	}
	new_buffer[i] = '\0';
	free(*_buffer);
	*_buffer = new_buffer;
	*size = *size * 2;
	return (1);
}

static int	ft_read_line(char **con, int fd)
{
	char	*buffer;
	int		bytes;
	int		ind;
	int		actual_size;

	actual_size = BUFFER_SIZE;
	buffer = *con;
	bytes = 0;
	ind = ft_strl(buffer);
	while (ft_check(buffer + ind) == 0)
	{
		ind += bytes;
		if (ft_super_malloc(&buffer, &actual_size, &ind) == 0)
			return (ft_free_return(buffer));
		bytes = read(fd, buffer + ind, BUFFER_SIZE);
		if (bytes < 0)
			return (ft_free_return(buffer));
		buffer[ind + bytes] = '\0';
		if (bytes < BUFFER_SIZE)
			break ;
	}
	*con = buffer;
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*containers;
	char		*returner;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	if (!ft_check(containers) && !ft_read_line(&containers, fd))
		return (NULL);
	returner = ft_create_line(&containers);
	if (!returner)
	{
		free(returner);
		free(containers);
		containers = NULL;
		return (NULL);
	}
	return (returner);
}
