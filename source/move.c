/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:08:44 by abutet            #+#    #+#             */
/*   Updated: 2024/02/14 17:34:47 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	move_u(t_mlx *game)
{
	if ((*game).map.map[(*game).playeur.y - 1][(*game).playeur.x] != '1'
		&& (*game).map.map[(*game).playeur.y - 1][(*game).playeur.x] != 'R')
	{
		if ((*game).playeur.time == -1)
		{
			make_case((*game).map.map[(*game).playeur.y][(*game).playeur.x],
				game, (*game).playeur.y, (*game).playeur.x);
			(*game).playeur.y--;
			(*game).playeur.d = 'u';
			(*game).playeur.time = 0;
		}
	}
	if (sui(game, (*game).playeur.x, (*game).playeur.y))
		ft_error(game, "SUICIDE\n");
	c_check(game);
}

void	move_d(t_mlx *game)
{
	if ((*game).map.map[(*game).playeur.y + 1][(*game).playeur.x] != '1'
		&& (*game).map.map[(*game).playeur.y + 1][(*game).playeur.x] != 'R')
	{
		if ((*game).playeur.time == -1)
		{
			make_case((*game).map.map[(*game).playeur.y][(*game).playeur.x],
				game, (*game).playeur.y, (*game).playeur.x);
			(*game).playeur.y++;
			(*game).playeur.d = 'd';
			(*game).playeur.time = 0;
		}
	}
	if (sui(game, (*game).playeur.x, (*game).playeur.y))
		ft_error(game, "SUICIDE\n");
	c_check(game);
}

void	move_l(t_mlx *game)
{
	if ((*game).map.map[(*game).playeur.y][(*game).playeur.x - 1] != '1'
		&& (*game).map.map[(*game).playeur.y][(*game).playeur.x - 1] != 'R')
	{
		if ((*game).playeur.time == -1)
		{
			make_case((*game).map.map[(*game).playeur.y][(*game).playeur.x],
				game, (*game).playeur.y, (*game).playeur.x);
			(*game).playeur.x--;
			(*game).playeur.d = 'l';
			(*game).playeur.time = 0;
		}
	}
	if (sui(game, (*game).playeur.x, (*game).playeur.y))
		ft_error(game, "SUICIDE\n");
	c_check(game);
}

void	move_r(t_mlx *game)
{
	if ((*game).map.map[(*game).playeur.y][(*game).playeur.x + 1] != '1'
		&& (*game).map.map[(*game).playeur.y][(*game).playeur.x + 1] != 'R')
	{
		if ((*game).playeur.time == -1)
		{
			if ((*game).exit.o == 2 && (*game).map.map[(*game).playeur.y]
				[(*game).playeur.x + 1] == 'E')
				ft_error(game, "YOU WON\n");
			make_case((*game).map.map[(*game).playeur.y][(*game).playeur.x],
				game, (*game).playeur.y, (*game).playeur.x);
			(*game).playeur.x++;
			(*game).playeur.d = 'r';
			(*game).playeur.time = 0;
		}
	}
	if (sui(game, (*game).playeur.x, (*game).playeur.y))
		ft_error(game, "SUICIDE\n");
	c_check(game);
}

void	c_check(t_mlx *game)
{
	if ((*game).map.map[(*game).playeur.y][(*game).playeur.x] == 'C')
	{
		(*game).playeur.c++;
		coin(game);
		(*game).map.map[(*game).playeur.y][(*game).playeur.x] = '0';
	}
}
