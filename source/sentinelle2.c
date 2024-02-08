/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentinelle2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:00:49 by abutet            #+#    #+#             */
/*   Updated: 2024/02/05 11:49:55 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	s_rand2(t_mlx *game, t_s *senti, int num)
{
	if ((*game).map.map[(*senti).y][(*senti).x + 1] != '1' && num == 1
		&& !sui(game, (*senti).x + 1, (*senti).y))
	{
		make_case((*game).map.map[(*senti).y][(*senti).x], game, (*senti).y,
			(*senti).x);
		(*senti).x++;
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_s_h.img, (*senti).x * 64 - 32,
			(*senti).y * 64 + 128);
		(*senti).d = 'r';
	}
	if ((*game).map.map[(*senti).y][(*senti).x - 1] != '1' && num == 3
		&& !sui(game, (*senti).x - 1, (*senti).y))
	{
		make_case((*game).map.map[(*senti).y][(*senti).x], game, (*senti).y,
			(*senti).x);
		(*senti).x--;
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_s_h.img, (*senti).x * 64 + 32,
			(*senti).y * 64 + 128);
		(*senti).d = 'l';
	}
}

void	s_rand(t_mlx *game, t_s *senti)
{
	int	num;

	num = rand() % 4;
	if ((*game).map.map[(*senti).y + 1][(*senti).x] != '1' && num == 0
		&& !sui(game, (*senti).x, (*senti).y + 1))
	{
		make_case((*game).map.map[(*senti).y][(*senti).x], game, (*senti).y,
			(*senti).x);
		(*senti).y++;
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_s_v.img, (*senti).x * 64, (*senti).y * 64 + 96);
		(*senti).d = 'd';
	}
	if ((*game).map.map[(*senti).y - 1][(*senti).x] != '1' && num == 2
		&& !sui(game, (*senti).x, (*senti).y - 1))
	{
		make_case((*game).map.map[(*senti).y][(*senti).x], game, (*senti).y,
			(*senti).x);
		(*senti).y--;
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_s_v.img, (*senti).x * 64, (*senti).y * 64 + 160);
		(*senti).d = 'u';
	}
	s_rand2(game, senti, num);
}
