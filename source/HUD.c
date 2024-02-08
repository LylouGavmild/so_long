/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HUD.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:38:23 by abutet            #+#    #+#             */
/*   Updated: 2024/01/23 15:34:06 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	img_takeur2(t_mlx *game, int nb, int x, int y)
{
	if (nb == 5)
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.nb.img_5.img, x, y);
	else if (nb == 6)
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.nb.img_6.img, x, y);
	else if (nb == 7)
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.nb.img_7.img, x, y);
	else if (nb == 8)
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.nb.img_8.img, x, y);
	else if (nb == 9)
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.nb.img_9.img, x, y);
}

void	img_takeur(t_mlx *game, int nb, int x, int y)
{
	if (nb == 0)
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.nb.img_0.img, x, y);
	else if (nb == 1)
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.nb.img_1.img, x, y);
	else if (nb == 2)
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.nb.img_2.img, x, y);
	else if (nb == 3)
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.nb.img_3.img, x, y);
	else if (nb == 4)
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.nb.img_4.img, x, y);
	else
		img_takeur2(game, nb, x, y);
}

void	itw(t_mlx *game, int nb, int x, int y)
{
	int	d;
	int	i;

	if (nb >= 10)
	{
		i = 0;
		d = nb;
		while (d >= 10)
		{
			d = d / 10;
			i++;
		}
		itw(game, nb % 10, x + (i * 64), y);
		itw(game, nb / 10, x, y);
	}
	else
		img_takeur(game, nb, x, y);
}

void	step(t_mlx *game)
{
	mlx_put_image_to_window((*game).mlx, (*game).win.win,
		(*game).img.img_step.img, 32, 32);
	mlx_put_image_to_window((*game).mlx, (*game).win.win,
		(*game).img.img_x.img, 96, 32);
	itw(game, (*game).step, 160, 32);
}

void	coin(t_mlx *game)
{
	int	i;
	int	nb;

	mlx_put_image_to_window((*game).mlx, (*game).win.win,
		(*game).img.img_c_b.img, (*game).win.win_height - 96, 32);
	i = 1;
	nb = (*game).map.c;
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	itw(game, (*game).map.c, (*game).win.win_height - 96 - (i * 64), 32);
	mlx_put_image_to_window((*game).mlx, (*game).win.win,
		(*game).img.img_slash.img, (*game).win.win_height - 160 - (i * 64), 32);
	nb = (*game).playeur.c;
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	itw(game, (*game).playeur.c, (*game).win.win_height - 224 - (i * 64), 32);
}
