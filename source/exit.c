/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:52:25 by abutet            #+#    #+#             */
/*   Updated: 2024/02/14 11:27:53 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	exit_anim(t_mlx	*game)
{
	if ((*game).map.c == (*game).playeur.c)
	{
		if ((*game).exit.o == 1 && difftime(time(NULL), (*game).exit.time) > 0)
		{
			mlx_destroy_image((*game).mlx, (*game).img.img_e.img);
			set_img(game, &(*game).img.img_e, "sprite/exit_open.xpm");
			mlx_put_image_to_window((*game).mlx, (*game).win.win,
				(*game).img.img_e.img, (*game).exit.x * 64,
				(*game).exit.y * 64 + 128);
			(*game).exit.o = 2;
		}
		else if ((*game).exit.o == 0)
		{
			mlx_destroy_image((*game).mlx, (*game).img.img_e.img);
			set_img(game, &(*game).img.img_e, "sprite/exit_semi_open.xpm");
			mlx_put_image_to_window((*game).mlx, (*game).win.win,
				(*game).img.img_e.img, (*game).exit.x * 64,
				(*game).exit.y * 64 + 128);
			(*game).exit.o = 1;
			(*game).exit.time = time(NULL);
		}
	}
}

int	main_loop(t_mlx *game)
{
	if ((*game).playeur.time >= 0)
	{
		(*game).playeur.time++;
		if ((*game).playeur.d == 'u')
			move_anim_u(game);
		else if ((*game).playeur.d == 'd')
			move_anim_d(game);
		else if ((*game).playeur.d == 'r')
			move_anim_r(game);
		else if ((*game).playeur.d == 'l')
			move_anim_l(game);
	}
	main_senti(game);
	if ((*game).exit.o != 2)
		exit_anim(game);
	if ((*game).playeur.b.coord)
		explosion(game);
	return (1);
}
