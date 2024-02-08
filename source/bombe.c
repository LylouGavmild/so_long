/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bombe.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:19:34 by abutet            #+#    #+#             */
/*   Updated: 2024/02/07 11:40:59 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	planto_bombo(t_mlx *game)
{
	if ((*game).playeur.b.nb < (*game).playeur.b.nb_max)
	{
		ft_badd_back(&(*game).playeur.b.coord, ft_bnew((*game).playeur.x,
				(*game).playeur.y));
	}
}

t_coord	*ft_bnew(int x, int y)
{
	t_coord	*b;

	b = malloc(sizeof(t_coord));
	if (!b)
		return (NULL);
	(*b).next = NULL;
	(*b).x = x;
	(*b).y = y;
	(*b).time = 0;
	return (b);
}

void	ft_badd_back(t_coord **lst, t_coord *newnode)
{
	t_coord	*start;

	start = *lst;
	if (*lst)
	{
		while (start->next)
			start = start->next;
		start->next = newnode;
	}
	else
		*lst = newnode;
}

void	img_explo(t_mlx *game, t_coord **bombe)
{
	mlx_put_image_to_window((*game).mlx, (*game).win.win,
		(*game).img.img_explosion.img, ((*bombe)->x + 1) * 64,
		(*bombe)->y * 64 + 128);
	mlx_put_image_to_window((*game).mlx, (*game).win.win,
		(*game).img.img_explosion.img, ((*bombe)->x - 1) * 64,
		(*bombe)->y * 64 + 128);
	mlx_put_image_to_window((*game).mlx, (*game).win.win,
		(*game).img.img_explosion.img, (*bombe)->x * 64,
		((*bombe)->y + 1) * 64 + 128);
	mlx_put_image_to_window((*game).mlx, (*game).win.win,
		(*game).img.img_explosion.img, (*bombe)->x * 64,
		((*bombe)->y - 1) * 64 + 128);
}

void	spreed(t_mlx *game, t_coord **bombe)
{
	t_coord	*next;
	t_s		*tmp;

	tmp = (*game).senti;
	while (tmp)
	{
		if (collision((*tmp).x, (*tmp).y, (*bombe)->x + 1, (*bombe)->y)
			|| collision((*tmp).x, (*tmp).y, (*bombe)->x - 1, (*bombe)->y)
			|| collision((*tmp).x, (*tmp).y, (*bombe)->x, (*bombe)->y + 1)
			|| collision((*tmp).x, (*tmp).y, (*bombe)->x, (*bombe)->y - 1))
			(*tmp).live = 0;
		tmp = (*tmp).next;
	}
	next = (*bombe)->next;
	free(*bombe);
	bombe = &next;
}

void	explosion(t_mlx *game)
{
	t_coord	*tmp;

	if ((*game).playeur.b.coord)
	{
		tmp = (*game).playeur.b.coord;
		while (tmp)
		{
			if ((*tmp).time == (*game).playeur.b.speed)
			{
				spreed(game, &tmp);
				(*game).playeur.b.nb--;
			}
			else
				(*tmp).time++;
			tmp = (*tmp).next;
		}
	}
}
