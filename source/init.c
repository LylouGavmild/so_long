/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:17:37 by abutet            #+#    #+#             */
/*   Updated: 2024/02/07 09:49:46 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	map_init(t_map *map, char *path)
{
	(*map).map = read_map(path);
	(*map).c = 0;
	(*map).col_len = 0;
	(*map).row_len = 0;
	(*map).e = 0;
	(*map).p = 0;
}

void	player_init(t_mlx *game)
{
	int	i;
	int	j;

	i = 0;
	while ((*game).map.map[i])
	{
		j = 0;
		while ((*game).map.map[i][j])
		{
			if ((*game).map.map[i][j] == 'P')
			{
				(*game).playeur.x = j;
				(*game).playeur.y = i;
				(*game).playeur.c = 0;
				(*game).playeur.m = 0;
				(*game).playeur.time = -1;
				return ;
			}
			j++;
		}
		i++;
	}
	ft_error(game, "NO PLAYEUR\n");
	return ;
}

void	img_init2(t_mlx *game)
{
	set_img(game, &(*game).img.nb.img_0, "sprite/0.xpm");
	set_img(game, &(*game).img.nb.img_1, "sprite/1.xpm");
	set_img(game, &(*game).img.nb.img_2, "sprite/2.xpm");
	set_img(game, &(*game).img.nb.img_3, "sprite/3.xpm");
	set_img(game, &(*game).img.nb.img_4, "sprite/4.xpm");
	set_img(game, &(*game).img.nb.img_5, "sprite/5.xpm");
	set_img(game, &(*game).img.nb.img_6, "sprite/6.xpm");
	set_img(game, &(*game).img.nb.img_7, "sprite/7.xpm");
	set_img(game, &(*game).img.nb.img_8, "sprite/8.xpm");
	set_img(game, &(*game).img.nb.img_9, "sprite/9.xpm");
	set_img(game, &(*game).img.img_s_v, "sprite/sentinelle_v.xpm");
	set_img(game, &(*game).img.img_s_h, "sprite/sentinelle_h.xpm");
	set_img(game, &(*game).img.img_bb, "sprite/bombe.xpm");
	set_img(game, &(*game).img.img_explosion, "sprite/explosion.xpm");
	set_img(game, &(*game).img.img_rock, "sprite/rock.xpm");
}

void	img_init(t_mlx *game)
{
	set_img(game, &(*game).img.img_void, "sprite/void.xpm");
	set_img(game, &(*game).img.img_wall, "sprite/wall.xpm");
	set_img(game, &(*game).img.img_sol, "sprite/sol.xpm");
	set_img(game, &(*game).img.img_c, "sprite/collectible.xpm");
	set_img(game, &(*game).img.img_c_b, "sprite/collectible_bleu.xpm");
	set_img(game, &(*game).img.img_p.right, "sprite/playeur_R.xpm");
	set_img(game, &(*game).img.img_p.right_1, "sprite/playeur_R_anim1.xpm");
	set_img(game, &(*game).img.img_p.right_2, "sprite/playeur_R_anim2.xpm");
	set_img(game, &(*game).img.img_p.left, "sprite/playeur_L.xpm");
	set_img(game, &(*game).img.img_p.left_1, "sprite/playeur_L_anim1.xpm");
	set_img(game, &(*game).img.img_p.left_2, "sprite/playeur_L_anim2.xpm");
	set_img(game, &(*game).img.img_p.up, "sprite/playeur_U.xpm");
	set_img(game, &(*game).img.img_p.up_1, "sprite/playeur_U_anim1.xpm");
	set_img(game, &(*game).img.img_p.up_2, "sprite/playeur_U_anim2.xpm");
	set_img(game, &(*game).img.img_p.down, "sprite/playeur_D.xpm");
	set_img(game, &(*game).img.img_p.down_1, "sprite/playeur_D_anim1.xpm");
	set_img(game, &(*game).img.img_p.down_2, "sprite/playeur_D_anim2.xpm");
	set_img(game, &(*game).img.img_e, "sprite/exit_close.xpm");
	set_img(game, &(*game).img.img_s, "sprite/sentinelle.xpm");
	set_img(game, &(*game).img.img_b, "sprite/bleu.xpm");
	set_img(game, &(*game).img.img_step, "sprite/step.xpm");
	set_img(game, &(*game).img.img_x, "sprite/X.xpm");
	set_img(game, &(*game).img.img_slash, "sprite/slash.xpm");
	img_init2(game);
}

void	set_img(t_mlx *game, t_img *img, char *path)
{
	(*img).img = mlx_xpm_file_to_image((*game).mlx,
			path, &(*img).img_width,
			&(*img).img_width);
	if (!(*img).img)
		ft_error(game, "immage error\n");
}
