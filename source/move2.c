/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:08:44 by abutet            #+#    #+#             */
/*   Updated: 2024/02/13 13:49:15 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	move_anime_u(t_mlx *game)
{
	if ((*game).playeur.m == 1)
	{
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_p.up_1.img, (*game).playeur.x * 64,
			(*game).playeur.y * 64 + 160);
		(*game).playeur.m = 0;
	}
	else if ((*game).playeur.m == 0)
	{
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_p.up_2.img, (*game).playeur.x * 64,
			(*game).playeur.y * 64 + 160);
		(*game).playeur.m = 1;
	}
}

void	move_anim_u(t_mlx *game)
{
	if ((*game).playeur.time == 100)
		move_anime_u(game);
	if ((*game).playeur.time == 3500)
	{
		if ((*game).exit.o && (*game).map.map[(*game).playeur.y]
			[(*game).playeur.x] == 'E')
			ft_error(game, "YOU WON\n");
		make_case((*game).map.map[(*game).playeur.y + 1][(*game).playeur.x],
			game, (*game).playeur.y + 1, (*game).playeur.x);
		make_p('u', (*game), (*game).playeur.y, (*game).playeur.x);
			(*game).step++;
		step(game);
		(*game).playeur.time = -1;
	}
}

void	move_anime_d(t_mlx *game)
{
	if ((*game).playeur.m == 1)
	{
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_p.down_1.img, (*game).playeur.x * 64,
			(*game).playeur.y * 64 + 96);
		(*game).playeur.m = 0;
	}
	else if ((*game).playeur.m == 0)
	{
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_p.down_2.img, (*game).playeur.x * 64,
			(*game).playeur.y * 64 + 96);
		(*game).playeur.m = 1;
	}
}

void	move_anim_d(t_mlx *game)
{
	if ((*game).playeur.time == 100)
		move_anime_d(game);
	if ((*game).playeur.time == 3500)
	{
		if ((*game).exit.o && (*game).map.map[(*game).playeur.y]
			[(*game).playeur.x] == 'E')
			ft_error(game, "YOU WON\n");
		make_case((*game).map.map[(*game).playeur.y - 1][(*game).playeur.x],
			game, (*game).playeur.y - 1, (*game).playeur.x);
		make_p('d', (*game), (*game).playeur.y, (*game).playeur.x);
			(*game).step++;
		step(game);
		(*game).playeur.time = -1;
	}
}
