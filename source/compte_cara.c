/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compte_cara.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:18:53 by abutet            #+#    #+#             */
/*   Updated: 2024/01/11 11:44:32 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	len_check(t_mlx *game)
{
	int	i;
	int	j;

	i = 0;
	while ((*game).map.map[i] && (*game).map.map[i][0] != '\n')
	{
		j = 0;
		while ((*game).map.map[i][j] && (*game).map.map[i][j] != '\n')
			j++;
		if ((*game).map.row_len == 0)
			(*game).map.row_len = j;
		else if ((*game).map.row_len != j)
			return (0);
		i++;
	}
	(*game).map.col_len = i;
	while ((*game).map.map[i] && (*game).map.map[i][0] == '\n')
		i++;
	if ((*game).map.map[i])
		return (0);
	return (1);
}

int	compte_cara(t_mlx *game)
{
	int		i;
	int		j;

	i = 0;
	while ((*game).map.map[i] && (*game).map.map[i][0] != '\n')
	{
		j = 0;
		while ((*game).map.map[i][j] && (*game).map.map[i][j] != '\n')
		{
			if ((*game).map.map[i][j] == 'P')
				(*game).map.p++;
			else if ((*game).map.map[i][j] == 'E')
				(*game).map.e++;
			else if ((*game).map.map[i][j] == 'C')
				(*game).map.c++;
			else if (!((*game).map.map[i][j] == '1'
				|| (*game).map.map[i][j] == '0'
				|| (*game).map.map[i][j] == 'S'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
