/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:53:54 by abutet            #+#    #+#             */
/*   Updated: 2024/01/11 11:30:44 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	check_ber(t_mlx *game, char *path)
{
	int	i;

	i = ft_strl(path);
	if (ft_strncmp(&path[i - 4], ".ber", 4))
		ft_error(game, "invald path\n");
}

void	check_path(t_mlx *game, char *path)
{
	int	fd;

	check_ber(game, path);
	fd = open(path, O_RDONLY);
	if (fd < 1)
	{
		close(fd);
		ft_error(game, "invald path\n");
	}
	close(fd);
	(*game).path = path;
}
