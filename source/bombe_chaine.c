/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bombe_chaine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:19:34 by abutet            #+#    #+#             */
/*   Updated: 2024/02/15 12:58:56 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	chaine4(t_mlx *game, t_coord *bombe, t_coord *other)
{
	int		i;

	i = 0;
	while ((*game).map.map[(*bombe).y][(*bombe).x - i] != '1'
			&& i <= (*game).playeur.b.rayon
			&& (*game).map.map[(*bombe).y][(*bombe).x - i] != 'R')
	{
		if (collision((*other).x, (*other).y, (*bombe).x - i, (*bombe).y)
			&& (*other).e)
		{
			if ((*other).time != (*game).playeur.b.speed)
				(*other).time = (*game).playeur.b.speed;
			spreed(game, other);
		}
		i++;
	}
}

void	chaine3(t_mlx *game, t_coord *bombe, t_coord *other)
{
	int		i;

	i = 0;
	while ((*game).map.map[(*bombe).y][(*bombe).x + i] != '1'
			&& i <= (*game).playeur.b.rayon
			&& (*game).map.map[(*bombe).y][(*bombe).x + i] != 'R')
	{
		if (collision((*other).x, (*other).y, (*bombe).x + i, (*bombe).y)
			&& (*other).e)
		{
			if ((*other).time != (*game).playeur.b.speed)
				(*other).time = (*game).playeur.b.speed;
			spreed(game, other);
		}
		i++;
	}
	chaine4(game, bombe, other);
}

void	chaine2(t_mlx *game, t_coord *bombe, t_coord *other)
{
	int		i;

	i = 0;
	while ((*game).map.map[(*bombe).y - i][(*bombe).x] != '1'
			&& i <= (*game).playeur.b.rayon
			&& (*game).map.map[(*bombe).y - i][(*bombe).x] != 'R')
	{
		if (collision((*other).x, (*other).y, (*bombe).x, (*bombe).y - i)
			&& (*other).e)
		{
			if ((*other).time != (*game).playeur.b.speed)
				(*other).time = (*game).playeur.b.speed;
			spreed(game, other);
		}
		i++;
	}
	chaine3(game, bombe, other);
}

void	chaine(t_mlx *game, t_coord *bombe)
{
	t_coord	*other;
	int		i;

	i = 0;
	other = (*game).playeur.b.coord;
	while (other)
	{
		while ((*game).map.map[(*bombe).y + i][(*bombe).x] != '1'
			&& i <= (*game).playeur.b.rayon
			&& (*game).map.map[(*bombe).y + i][(*bombe).x] != 'R')
		{
			if (collision((*other).x, (*other).y, (*bombe).x, (*bombe).y + i)
				&& (*other).e)
			{
				if ((*other).time != (*game).playeur.b.speed)
					(*other).time = (*game).playeur.b.speed;
				spreed(game, other);
			}
			i++;
		}
		chaine2(game, bombe, other);
		other = (*other).next;
	}
}
