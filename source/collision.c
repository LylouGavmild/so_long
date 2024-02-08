/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:32:42 by abutet            #+#    #+#             */
/*   Updated: 2024/01/12 14:34:10 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	collision(int x1, int y1, int x2, int y2)
{
	if (x1 == x2 && y1 == y2)
		return (1);
	return (0);
}

int	sui(t_mlx *game, int x, int y)
{
	t_s	*tmp;

	tmp = (*game).senti;
	while (tmp)
	{
		if (collision((*tmp).x, (*tmp).y, x, y))
			return (1);
		tmp = (*tmp).next;
	}
	return (0);
}
