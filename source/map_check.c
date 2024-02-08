/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:00:06 by abutet            #+#    #+#             */
/*   Updated: 2024/02/05 12:24:36 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	flood_fill(t_map *map, int x, int y)
{
	if ((*map).map[y][x] == 'C')
			(*map).c++;
	if ((*map).map[y][x] == 'E')
			(*map).e++;
	(*map).map[y][x] = 'F';
	if ((*map).map[y - 1][x] != '1' && (*map).map[y - 1][x] != 'F')
		flood_fill(map, x, y - 1);
	if ((*map).map[y + 1][x] != '1' && (*map).map[y + 1][x] != 'F')
		flood_fill(map, x, y + 1);
	if ((*map).map[y][x - 1] != '1' && (*map).map[y][x - 1] != 'F')
		flood_fill(map, x - 1, y);
	if ((*map).map[y][x + 1] != '1' && (*map).map[y][x + 1] != 'F')
		flood_fill(map, x + 1, y);
}

int	map_border(t_mlx *game)
{
	int	i;

	i = 0;
	while ((*game).map.map[0][i] && (*game).map.map[0][i] != '\n')
	{
		if ((*game).map.map[0][i] != '1'
			|| (*game).map.map[(*game).map.col_len - 1][i] != '1')
		{
			return (0);
		}
		i++;
	}
	i = 0;
	while ((*game).map.map[i])
	{
		if ((*game).map.map[i][0] != '1'
			|| (*game).map.map[i][(*game).map.row_len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	map_check(t_mlx *game)
{
	if (!(*game).map.map)
		ft_error(game, "no map\n");
	if (len_check(game) == 0)
		ft_error(game, "map not rectangular\n");
	if (map_border(game) == 0)
		ft_error(game, "border error\n");
	if (compte_cara(game) == 0)
		ft_error(game, "caractere error\n");
	if ((*game).map.p != 1)
		ft_error(game, "nb de spawn incorrect\n");
	if ((*game).map.e != 1)
		ft_error(game, "nb de sortie incorrect\n");
	if ((*game).map.c < 1)
		ft_error(game, "nb de collectible incorrect\n");
	player_init(game);
	map_comp(game);
}

void	map_comp(t_mlx *game)
{
	t_map	check;

	map_init(&check, (*game).path);
	flood_fill(&check, (*game).playeur.x, (*game).playeur.y);
	if (check.e != 1)
	{
		destroy_map(&check);
		ft_error(game, "sortie innacessible\n");
	}
	if ((*game).map.c != check.c)
	{
		destroy_map(&check);
		ft_error(game, "collectible innacessible\n");
	}
	destroy_map(&check);
}
