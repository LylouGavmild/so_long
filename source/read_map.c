/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:01:22 by abutet            #+#    #+#             */
/*   Updated: 2024/01/23 11:14:47 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static int	file_linecount(char *file)
{
	int		linecount;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	linecount = 0;
	line = get_next_line(fd);
	while (line)
	{
		linecount++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (linecount);
}

static char	**alloc_columns(char *file)
{
	char	**map;
	int		line_count;

	line_count = file_linecount(file);
	if (line_count <= 0)
		return (NULL);
	map = malloc(sizeof(char *) * (line_count + 1));
	if (map == NULL)
		return (NULL);
	return (map);
}

char	**read_map(char *file)
{
	char	**map;
	int		fd;
	int		i;

	map = alloc_columns(file);
	if (map == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	i = 0;
	map[i] = get_next_line(fd);
	while (map[i])
	{
		i++;
		map[i] = get_next_line(fd);
	}
	close(fd);
	return (map);
}
