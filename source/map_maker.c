/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:02:40 by abutet            #+#    #+#             */
/*   Updated: 2024/02/14 17:30:49 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	map_maker(t_mlx *game)
{
	int		i;
	int		j;

	i = 0;
	while ((*game).map.map[i])
	{
		j = 0;
		while ((*game).map.map[i][j])
		{
			make_case((*game).map.map[i][j], game, i, j);
			if ((*game).map.map[i][j] == 'P')
				make_p('r', (*game), i, j);
			if ((*game).map.map[i][j] == 'S')
			{
				make_s(game, i, j);
				ft_sadd_back(&(*game).senti, ft_snew(j, i));
			}
			j++;
		}
		i++;
	}
}

void	make_case(char c, t_mlx *game, int col, int row)
{
	if (c == '1')
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_wall.img, row * 64, col * 64 + 128);
	if (c == '0' || c == 'S' || c == 'P')
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_sol.img, row * 64, col * 64 + 128);
	if (c == 'C')
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_c.img, row * 64, col * 64 + 128);
	if (c == 'R')
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_rock.img, row * 64, col * 64 + 128);
	if (c == 'B')
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_bb.img, row * 64, col * 64 + 128);
	if (c == 'R')
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_rock.img, row * 64, col * 64 + 128);
	if (c == 'E')
	{
		(*game).exit.x = row;
		(*game).exit.y = col;
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_e.img, row * 64, col * 64 + 128);
	}
}

void	make_p(char c, t_mlx game, int col, int row)
{
	if (c == 'u')
		mlx_put_image_to_window(game.mlx, game.win.win,
			game.img.img_p.up.img, row * 64, col * 64 + 128);
	if (c == 'd')
		mlx_put_image_to_window(game.mlx, game.win.win,
			game.img.img_p.down.img, row * 64, col * 64 + 128);
	if (c == 'l')
		mlx_put_image_to_window(game.mlx, game.win.win,
			game.img.img_p.left.img, row * 64, col * 64 + 128);
	if (c == 'r')
		mlx_put_image_to_window(game.mlx, game.win.win,
			game.img.img_p.right.img, row * 64, col * 64 + 128);
}

void	make_s(t_mlx *game, int col, int row)
{
	mlx_put_image_to_window((*game).mlx, (*game).win.win,
		(*game).img.img_s.img, row * 64, col * 64 + 128);
}
