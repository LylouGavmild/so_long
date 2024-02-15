/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bombe_spreed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:19:34 by abutet            #+#    #+#             */
/*   Updated: 2024/02/15 14:46:23 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	make_e2(t_mlx *game, t_coord *bombe)
{
	int	i;

	i = 0;
	while ((*game).map.map[(*bombe).y][(*bombe).x + i] != '1'
			&& i <= (*game).playeur.b.rayon
			&& (*game).map.map[(*bombe).y][(*bombe).x + i] != 'R')
	{
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_explosion.img, ((*bombe).x + i) * 64,
			(*bombe).y * 64 + 128);
		i++;
	}
	i = 0;
	while ((*game).map.map[(*bombe).y][(*bombe).x - i] != '1'
			&& i <= (*game).playeur.b.rayon
			&& (*game).map.map[(*bombe).y][(*bombe).x - i] != 'R')
	{
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_explosion.img, ((*bombe).x - i) * 64,
			(*bombe).y * 64 + 128);
		i++;
	}
}

void	make_e(t_mlx *game, t_coord *bombe)
{
	int	i;

	i = 0;
	while ((*game).map.map[(*bombe).y + i][(*bombe).x] != '1'
			&& i <= (*game).playeur.b.rayon
			&& (*game).map.map[(*bombe).y + i][(*bombe).x] != 'R')
	{
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_explosion.img, (*bombe).x * 64,
			((*bombe).y + i) * 64 + 128);
		i++;
	}
	i = 0;
	while ((*game).map.map[(*bombe).y - i][(*bombe).x] != '1'
			&& i <= (*game).playeur.b.rayon
			&& (*game).map.map[(*bombe).y - i][(*bombe).x] != 'R')
	{
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_explosion.img, (*bombe).x * 64,
			((*bombe).y - i) * 64 + 128);
		i++;
	}
	make_e2(game, bombe);
}

void	spreed(t_mlx *game, t_coord *bombe)
{
	kill(game, bombe);
	(*bombe).e = 0;
	chaine(game, bombe);
	ff(game, bombe);
	if ((*bombe).time >= (*game).playeur.b.speed
		&& (*bombe).time <= (*game).playeur.b.speed + 5)
		make_e(game, bombe);
	if ((*bombe).time == (*game).playeur.b.speed)
		pouf(game, bombe);
}

void	explosion(t_mlx *game)
{
	t_coord	*tmp;

	tmp = (*game).playeur.b.coord;
	while (tmp)
	{
		if ((*tmp).time >= (*game).playeur.b.speed
			&& (*tmp).time < (*game).playeur.b.speed + 5000)
			spreed(game, tmp);
		else if ((*tmp).time == (*game).playeur.b.speed + 5002)
		{
			clean(game, tmp);
			rock(game, tmp);
			clean_lst(&(*game).playeur.b.coord, &tmp);
			(*game).playeur.b.nb--;
			continue ;
		}
		(*tmp).time++;
		tmp = (*tmp).next;
	}
}
