/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:22:54 by abutet            #+#    #+#             */
/*   Updated: 2024/02/05 13:25:34 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	img_null2(t_mlx *game)
{
	(*game).img.nb.img_0.img = NULL;
	(*game).img.nb.img_1.img = NULL;
	(*game).img.nb.img_2.img = NULL;
	(*game).img.nb.img_3.img = NULL;
	(*game).img.nb.img_4.img = NULL;
	(*game).img.nb.img_5.img = NULL;
	(*game).img.nb.img_6.img = NULL;
	(*game).img.nb.img_7.img = NULL;
	(*game).img.nb.img_8.img = NULL;
	(*game).img.nb.img_9.img = NULL;
	(*game).img.img_s_h.img = NULL;
	(*game).img.img_s_v.img = NULL;
	(*game).img.img_bb.img = NULL;
	(*game).img.img_explosion.img = NULL;
	(*game).img.img_rock.img = NULL;
}

void	img_null(t_mlx *game)
{
	(*game).img.img_void.img = NULL;
	(*game).img.img_wall.img = NULL;
	(*game).img.img_sol.img = NULL;
	(*game).img.img_c.img = NULL;
	(*game).img.img_c_b.img = NULL;
	(*game).img.img_p.right.img = NULL;
	(*game).img.img_p.right_1.img = NULL;
	(*game).img.img_p.right_2.img = NULL;
	(*game).img.img_p.left.img = NULL;
	(*game).img.img_p.left_1.img = NULL;
	(*game).img.img_p.left_2.img = NULL;
	(*game).img.img_p.up.img = NULL;
	(*game).img.img_p.up_1.img = NULL;
	(*game).img.img_p.up_2.img = NULL;
	(*game).img.img_p.down.img = NULL;
	(*game).img.img_p.down_1.img = NULL;
	(*game).img.img_p.down_2.img = NULL;
	(*game).img.img_e.img = NULL;
	(*game).img.img_s.img = NULL;
	(*game).img.img_b.img = NULL;
	(*game).img.img_step.img = NULL;
	(*game).img.img_x.img = NULL;
	(*game).img.img_slash.img = NULL;
	img_null2(game);
}

void	init_null(t_mlx *game)
{
	img_null(game);
	(*game).map.map = NULL;
	(*game).mlx = NULL;
	(*game).win.win = NULL;
	(*game).path = NULL;
	(*game).senti = NULL;
	(*game).step = 0;
	(*game).exit.o = 0;
}

void	win_init(t_mlx *game)
{
	(*game).win.win_height = (*game).map.row_len * 64;
	(*game).win.win_width = ((*game).map.col_len + 2) * 64;
	(*game).win.win = mlx_new_window((*game).mlx, (*game).win.win_height,
			(*game).win.win_width, "TNTGIRL");
	if ((*game).win.win == NULL)
		ft_error(game, "windows error\n");
}
