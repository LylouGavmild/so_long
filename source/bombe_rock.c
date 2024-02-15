/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bombe_rock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:19:34 by abutet            #+#    #+#             */
/*   Updated: 2024/02/15 13:11:42 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	rock4(t_mlx *game, t_coord *bombe)
{
	int		i;

	i = 0;
	while ((*game).map.map[(*bombe).y][(*bombe).x - i] != '1'
			&& i <= (*game).playeur.b.rayon)
	{
		if ((*game).map.map[(*bombe).y][(*bombe).x - i] == 'R')
		{
			(*game).map.map[(*bombe).y][(*bombe).x - i] = '0';
			make_case((*game).map.map[(*bombe).y][(*bombe).x - i], game,
				(*bombe).y, (*bombe).x - i);
			break ;
		}
		i++;
	}
}

void	rock3(t_mlx *game, t_coord *bombe)
{
	int		i;

	i = 0;
	while ((*game).map.map[(*bombe).y][(*bombe).x + i] != '1'
			&& i <= (*game).playeur.b.rayon)
	{
		if ((*game).map.map[(*bombe).y][(*bombe).x + i] == 'R')
		{
			(*game).map.map[(*bombe).y][(*bombe).x + i] = '0';
			make_case((*game).map.map[(*bombe).y][(*bombe).x + i], game,
				(*bombe).y, (*bombe).x + i);
			break ;
		}
		i++;
	}
	rock4(game, bombe);
}

void	rock2(t_mlx *game, t_coord *bombe)
{
	int		i;

	i = 0;
	while ((*game).map.map[(*bombe).y - i][(*bombe).x] != '1'
			&& i <= (*game).playeur.b.rayon)
	{
		if ((*game).map.map[(*bombe).y - i][(*bombe).x] == 'R')
		{
			(*game).map.map[(*bombe).y - i][(*bombe).x] = '0';
			make_case((*game).map.map[(*bombe).y - i][(*bombe).x], game,
				(*bombe).y - i, (*bombe).x);
			break ;
		}
		i++;
	}
	rock3(game, bombe);
}

void	rock(t_mlx *game, t_coord *bombe)
{
	int	i;

	i = 0;
	while ((*game).map.map[(*bombe).y + i][(*bombe).x] != '1'
		&& i <= (*game).playeur.b.rayon)
	{
		if ((*game).map.map[(*bombe).y + i][(*bombe).x] == 'R')
		{
			(*game).map.map[(*bombe).y + i][(*bombe).x] = '0';
			make_case((*game).map.map[(*bombe).y + i][(*bombe).x], game,
				(*bombe).y + i, (*bombe).x);
			break ;
		}
		i++;
	}
	rock2(game, bombe);
}
