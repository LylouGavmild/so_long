/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bombe_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:19:34 by abutet            #+#    #+#             */
/*   Updated: 2024/02/15 11:31:26 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ff2(t_mlx *game, t_coord *bombe)
{
	int		i;

	i = 0;
	while ((*game).map.map[(*bombe).y][(*bombe).x + i] != '1'
			&& i <= (*game).playeur.b.rayon
			&& (*game).map.map[(*bombe).y][(*bombe).x + i] != 'R')
	{
		if (collision((*game).playeur.x, (*game).playeur.y, (*bombe).x + i,
				(*bombe).y))
			ft_error(game, "MACRON EXPLOSION\n");
		i++;
	}
	i = 0;
	while ((*game).map.map[(*bombe).y][(*bombe).x - i] != '1'
			&& i <= (*game).playeur.b.rayon
			&& (*game).map.map[(*bombe).y][(*bombe).x - i] != 'R')
	{
		if (collision((*game).playeur.x, (*game).playeur.y, (*bombe).x - i,
				(*bombe).y))
			ft_error(game, "MACRON EXPLOSION\n");
		i++;
	}
}

void	ff(t_mlx *game, t_coord *bombe)
{
	int		i;

	i = 0;
	while ((*game).map.map[(*bombe).y + i][(*bombe).x] != '1'
			&& i <= (*game).playeur.b.rayon
			&& (*game).map.map[(*bombe).y + i][(*bombe).x] != 'R')
	{
		if (collision((*game).playeur.x, (*game).playeur.y, (*bombe).x,
				(*bombe).y + i))
			ft_error(game, "MACRON EXPLOSION\n");
		i++;
	}
	i = 0;
	while ((*game).map.map[(*bombe).y - i][(*bombe).x] != '1'
			&& i <= (*game).playeur.b.rayon
			&& (*game).map.map[(*bombe).y - i][(*bombe).x] != 'R')
	{
		if (collision((*game).playeur.x, (*game).playeur.y, (*bombe).x,
				(*bombe).y - i))
			ft_error(game, "MACRON EXPLOSION\n");
		i++;
	}
	ff2(game, bombe);
}

void	clean2(t_mlx *game, t_coord *bombe)
{
	int	i;

	i = 0;
	while ((*game).map.map[(*bombe).y][(*bombe).x + i] != '1'
			&& i <= (*game).playeur.b.rayon
			&& (*game).map.map[(*bombe).y][(*bombe).x + i] != 'R')
	{
		make_case((*game).map.map[(*bombe).y][(*bombe).x + i], game,
			(*bombe).y, (*bombe).x + i);
		i++;
	}
	i = 0;
	while ((*game).map.map[(*bombe).y][(*bombe).x - i] != '1'
			&& i <= (*game).playeur.b.rayon
			&& (*game).map.map[(*bombe).y][(*bombe).x - i] != 'R')
	{
		make_case((*game).map.map[(*bombe).y][(*bombe).x - i], game,
			(*bombe).y, (*bombe).x - i);
		i++;
	}
}

void	clean(t_mlx *game, t_coord *bombe)
{
	int	i;

	i = 0;
	(*game).map.map[(*bombe).y][(*bombe).x] = '0';
	while ((*game).map.map[(*bombe).y + i][(*bombe).x] != '1'
			&& i <= (*game).playeur.b.rayon
			&& (*game).map.map[(*bombe).y + i][(*bombe).x] != 'R')
	{
		make_case((*game).map.map[(*bombe).y + i][(*bombe).x], game,
			(*bombe).y + i, (*bombe).x);
		i++;
	}
	i = 0;
	while ((*game).map.map[(*bombe).y - i][(*bombe).x] != '1'
			&& i <= (*game).playeur.b.rayon
			&& (*game).map.map[(*bombe).y - i][(*bombe).x] != 'R')
	{
		make_case((*game).map.map[(*bombe).y - i][(*bombe).x], game,
			(*bombe).y - i, (*bombe).x);
		i++;
	}
	clean2(game, bombe);
}
