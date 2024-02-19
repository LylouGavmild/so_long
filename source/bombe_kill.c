/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bombe_kill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:19:34 by abutet            #+#    #+#             */
/*   Updated: 2024/02/19 12:11:11 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	kill4(t_mlx *game, t_coord *bombe, t_s *tmp)
{
	int		i;

	i = 0;
	while ((*game).map.map[(*bombe).y][(*bombe).x - i] != '1'
			&& i <= (*game).playeur.b.rayon
			&& (*game).map.map[(*bombe).y][(*bombe).x - i] != 'R')
	{
		if (collision((*tmp).x, (*tmp).y, (*bombe).x - i, (*bombe).y))
			(*tmp).live = 0;
		i++;
	}
}

void	kill3(t_mlx *game, t_coord *bombe, t_s *tmp)
{
	int		i;

	i = 0;
	while ((*game).map.map[(*bombe).y][(*bombe).x + i] != '1'
			&& i <= (*game).playeur.b.rayon
			&& (*game).map.map[(*bombe).y][(*bombe).x + i] != 'R')
	{
		if (collision((*tmp).x, (*tmp).y, (*bombe).x + i, (*bombe).y))
			(*tmp).live = 0;
		i++;
	}
	kill4(game, bombe, tmp);
}

void	kill2(t_mlx *game, t_coord *bombe, t_s *tmp)
{
	int		i;

	i = 0;
	while ((*game).map.map[(*bombe).y - i][(*bombe).x] != '1'
			&& i <= (*game).playeur.b.rayon
			&& (*game).map.map[(*bombe).y - i][(*bombe).x] != 'R')
	{
		if (collision((*tmp).x, (*tmp).y, (*bombe).x, (*bombe).y - i))
			(*tmp).live = 0;
		i++;
	}
	kill3(game, bombe, tmp);
}

void	kill(t_mlx *game, t_coord *bombe)
{
	t_s	*tmp;
	int	i;

	tmp = (*game).senti;
	while (tmp)
	{
		i = 0;
		while ((*game).map.map[(*bombe).y + i][(*bombe).x] != '1'
			&& i <= (*game).playeur.b.rayon
				&& (*game).map.map[(*bombe).y + i][(*bombe).x] != 'R')
		{
			if (collision((*tmp).x, (*tmp).y, (*bombe).x, (*bombe).y + i))
				(*tmp).live = 0;
			i++;
		}
		kill2(game, bombe, tmp);
		tmp = (*tmp).next;
	}
}
