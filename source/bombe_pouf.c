/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bombe_pouf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:19:34 by abutet            #+#    #+#             */
/*   Updated: 2024/02/15 13:38:13 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	pouf4(t_mlx *game, t_coord *bombe)
{
	int		i;

	i = 0;
	while ((*game).map.map[(*bombe).y][(*bombe).x - i] != '1'
			&& i <= (*game).playeur.b.rayon)
	{
		if ((*game).map.map[(*bombe).y][(*bombe).x - i] == 'R')
		{
			mlx_put_image_to_window((*game).mlx, (*game).win.win,
				(*game).img.img_pouf.img, ((*bombe).x - i) * 64,
				(*bombe).y * 64 + 128);
			break ;
		}
		i++;
	}
}

void	pouf3(t_mlx *game, t_coord *bombe)
{
	int		i;

	i = 0;
	while ((*game).map.map[(*bombe).y][(*bombe).x + i] != '1'
			&& i <= (*game).playeur.b.rayon)
	{
		if ((*game).map.map[(*bombe).y][(*bombe).x + i] == 'R')
		{
			mlx_put_image_to_window((*game).mlx, (*game).win.win,
				(*game).img.img_pouf.img, ((*bombe).x + i) * 64,
				(*bombe).y * 64 + 128);
			break ;
		}
		i++;
	}
	pouf4(game, bombe);
}

void	pouf2(t_mlx *game, t_coord *bombe)
{
	int		i;

	i = 0;
	while ((*game).map.map[(*bombe).y - i][(*bombe).x] != '1'
			&& i <= (*game).playeur.b.rayon)
	{
		if ((*game).map.map[(*bombe).y - i][(*bombe).x] == 'R')
		{
			mlx_put_image_to_window((*game).mlx, (*game).win.win,
				(*game).img.img_pouf.img, (*bombe).x * 64,
				((*bombe).y - i) * 64 + 128);
			break ;
		}
		i++;
	}
	pouf3(game, bombe);
}

void	pouf(t_mlx *game, t_coord *bombe)
{
	int	i;

	i = 0;
	while ((*game).map.map[(*bombe).y + i][(*bombe).x] != '1'
		&& i <= (*game).playeur.b.rayon)
	{
		if ((*game).map.map[(*bombe).y + i][(*bombe).x] == 'R')
		{
			mlx_put_image_to_window((*game).mlx, (*game).win.win,
				(*game).img.img_pouf.img, (*bombe).x * 64,
				((*bombe).y + i) * 64 + 128);
			break ;
		}
		i++;
	}
	pouf2(game, bombe);
}
