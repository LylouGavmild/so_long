/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:28:50 by abutet            #+#    #+#             */
/*   Updated: 2024/02/19 11:45:45 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_win(t_mlx *game, char *msg)
{
	write(1, msg, ft_strl(msg));
	end(game);
}

void	ft_error(t_mlx *game, char *msg)
{
	write(1, "Error\n", 6);
	write(1, msg, ft_strl(msg));
	end(game);
}

void	map_len_check(t_mlx *game)
{
	int	sizex;
	int	sizey;

	mlx_get_screen_size((*game).mlx, &sizex, &sizey);
	if (sizex < (*game).map.row_len * 64
		|| sizey < ((*game).map.col_len * 64) + 126)
		ft_error(game, "too big map\n");
	if ((*game).map.row_len * 64 < 15 * 64)
		ft_error(game, "too small map for the user interface\n");
}
