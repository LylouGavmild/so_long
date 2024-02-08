/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HUD2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:45:30 by abutet            #+#    #+#             */
/*   Updated: 2024/01/23 14:47:55 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	hud(t_mlx *game)
{
	int	i;

	i = 0;
	while (i < (*game).win.win_height)
	{
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_b.img, i * 64, 0);
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_b.img, i * 64, 64);
		i++;
	}
	step(game);
	coin(game);
}
