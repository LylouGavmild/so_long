/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:49:53 by abutet            #+#    #+#             */
/*   Updated: 2024/02/14 11:49:10 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	destroy_s(t_mlx *game)
{
	t_s	*tmp;

	while ((*game).senti)
	{
		tmp = (*(*game).senti).next;
		free((*game).senti);
		(*game).senti = tmp;
	}
}

void	destroy_b(t_mlx *game)
{
	t_coord	*tmp;

	while ((*game).playeur.b.coord)
	{
		tmp = (*(*game).playeur.b.coord).next;
		free((*game).playeur.b.coord);
		(*game).playeur.b.coord = tmp;
	}
	
}

int	end(t_mlx *game)
{	
	destroy_img(game);
	destroy_s(game);
	destroy_b(game);
	if ((*game).map.map)
		destroy_map(&(*game).map);
	if ((*game).win.win)
		mlx_destroy_window((*game).mlx, (*game).win.win);
	if (game->mlx)
	{
		mlx_destroy_display((*game).mlx);
		free((*game).mlx);
	}
	exit(0);
}
