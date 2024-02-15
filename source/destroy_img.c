/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:49:53 by abutet            #+#    #+#             */
/*   Updated: 2024/02/15 13:28:16 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	destroy_img4(t_mlx *game)
{
	if ((*game).img.img_bb.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_bb.img);
	if ((*game).img.img_explosion.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_explosion.img);
	if ((*game).img.img_rock.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_rock.img);
	if ((*game).img.img_pouf.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_pouf.img);
}

void	destroy_img3(t_mlx *game)
{
	if ((*game).img.img_slash.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_slash.img);
	if ((*game).img.img_p.down_1.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_p.down_1.img);
	if ((*game).img.img_p.down_2.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_p.down_2.img);
	if ((*game).img.img_p.up_1.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_p.up_1.img);
	if ((*game).img.img_p.up_2.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_p.up_2.img);
	if ((*game).img.img_p.right_1.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_p.right_1.img);
	if ((*game).img.img_p.right_2.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_p.right_2.img);
	if ((*game).img.img_p.left_1.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_p.left_1.img);
	if ((*game).img.img_p.left_2.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_p.left_2.img);
	if ((*game).img.img_s_h.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_s_h.img);
	if ((*game).img.img_s_v.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_s_v.img);
	destroy_img4(game);
}

void	destroy_img2(t_mlx *game)
{
	if ((*game).img.nb.img_0.img)
		mlx_destroy_image((*game).mlx, (*game).img.nb.img_0.img);
	if ((*game).img.nb.img_1.img)
		mlx_destroy_image((*game).mlx, (*game).img.nb.img_1.img);
	if ((*game).img.nb.img_2.img)
		mlx_destroy_image((*game).mlx, (*game).img.nb.img_2.img);
	if ((*game).img.nb.img_3.img)
		mlx_destroy_image((*game).mlx, (*game).img.nb.img_3.img);
	if ((*game).img.nb.img_4.img)
		mlx_destroy_image((*game).mlx, (*game).img.nb.img_4.img);
	if ((*game).img.nb.img_5.img)
		mlx_destroy_image((*game).mlx, (*game).img.nb.img_5.img);
	if ((*game).img.nb.img_6.img)
		mlx_destroy_image((*game).mlx, (*game).img.nb.img_6.img);
	if ((*game).img.nb.img_7.img)
		mlx_destroy_image((*game).mlx, (*game).img.nb.img_7.img);
	if ((*game).img.nb.img_8.img)
		mlx_destroy_image((*game).mlx, (*game).img.nb.img_8.img);
	if ((*game).img.nb.img_9.img)
		mlx_destroy_image((*game).mlx, (*game).img.nb.img_9.img);
	if ((*game).img.img_x.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_x.img);
	if ((*game).img.img_step.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_step.img);
	destroy_img3(game);
}

void	destroy_img(t_mlx *game)
{
	if ((*game).img.img_wall.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_wall.img);
	if ((*game).img.img_sol.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_sol.img);
	if ((*game).img.img_c.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_c.img);
	if ((*game).img.img_c_b.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_c_b.img);
	if ((*game).img.img_void.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_void.img);
	if ((*game).img.img_p.down.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_p.down.img);
	if ((*game).img.img_p.up.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_p.up.img);
	if ((*game).img.img_p.right.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_p.right.img);
	if ((*game).img.img_p.left.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_p.left.img);
	if ((*game).img.img_e.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_e.img);
	if ((*game).img.img_s.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_s.img);
	if ((*game).img.img_b.img)
		mlx_destroy_image((*game).mlx, (*game).img.img_b.img);
	destroy_img2(game);
}
