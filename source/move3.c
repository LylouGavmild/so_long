/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:08:44 by abutet            #+#    #+#             */
/*   Updated: 2024/02/02 13:42:26 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	move_anime_r(t_mlx *game)
{
	if ((*game).playeur.m == 1)
	{
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_p.right_1.img, (*game).playeur.x * 64 - 32,
			(*game).playeur.y * 64 + 128);
		(*game).playeur.m = 0;
	}
	else if ((*game).playeur.m == 0)
	{
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_p.right_2.img, (*game).playeur.x * 64 - 32,
			(*game).playeur.y * 64 + 128);
		(*game).playeur.m = 1;
	}
}

void	move_anim_r(t_mlx *game)
{
	if ((*game).playeur.time == 100)
		move_anime_r(game);
	if ((*game).playeur.time == 3500)
	{
		if ((*game).exit.o && (*game).map.map[(*game).playeur.y]
			[(*game).playeur.x] == 'E')
			ft_error(game, "YOU WON\n");
		make_case((*game).map.map[(*game).playeur.y][(*game).playeur.x],
			game, (*game).playeur.y, (*game).playeur.x - 1);
		make_p('r', (*game), (*game).playeur.y, (*game).playeur.x);
			(*game).step++;
		step(game);
		(*game).playeur.time = -1;
	}
}

void	move_anime_l(t_mlx *game)
{
	if ((*game).playeur.m == 1)
	{
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_p.left_1.img, (*game).playeur.x * 64 + 32,
			(*game).playeur.y * 64 + 128);
		(*game).playeur.m = 0;
	}
	else if ((*game).playeur.m == 0)
	{
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_p.left_2.img, (*game).playeur.x * 64 + 32,
			(*game).playeur.y * 64 + 128);
		(*game).playeur.m = 1;
	}
}

void	move_anim_l(t_mlx *game)
{
	if ((*game).playeur.time == 100)
		move_anime_l(game);
	if ((*game).playeur.time == 3500)
	{
		if ((*game).exit.o && (*game).map.map[(*game).playeur.y]
			[(*game).playeur.x] == 'E')
			ft_error(game, "YOU WON\n");
		make_case((*game).map.map[(*game).playeur.y][(*game).playeur.x],
			game, (*game).playeur.y, (*game).playeur.x + 1);
		make_p('l', (*game), (*game).playeur.y, (*game).playeur.x);
			(*game).step++;
		step(game);
		(*game).playeur.time = -1;
	}
}
