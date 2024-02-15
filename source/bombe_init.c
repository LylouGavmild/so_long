/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bombe_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:19:34 by abutet            #+#    #+#             */
/*   Updated: 2024/02/15 11:07:25 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

t_coord	*ft_bnew(int x, int y)
{
	t_coord	*b;

	b = malloc(sizeof(t_coord));
	if (!b)
		return (NULL);
	(*b).next = NULL;
	(*b).x = x;
	(*b).y = y;
	(*b).e = 1;
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

void	planto_bombo(t_mlx *game)
{
	t_coord	*bombe;

	if ((*game).playeur.b.nb < (*game).playeur.b.nb_max
		&& (*game).map.map[(*game).playeur.y][(*game).playeur.x] != 'E'
		&& (*game).map.map[(*game).playeur.y][(*game).playeur.x] != 'B')
	{
		bombe = ft_bnew((*game).playeur.x, (*game).playeur.y);
		ft_badd_back(&(*game).playeur.b.coord, bombe);
		(*game).map.map[(*game).playeur.y][(*game).playeur.x] = 'B';
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_bb.img, (*bombe).x * 64, (*bombe).y * 64 + 128);
		(*game).playeur.b.nb++;
	}
}

void	clean_lst(t_coord **lst, t_coord **bombe)
{
	t_coord	*tmp;

	tmp = *lst;
	while (tmp != *bombe && tmp)
		tmp = tmp->next;
	*lst = (*tmp).next;
	if ((*bombe)->next)
		*bombe = (*bombe)->next;
	else
		*bombe = NULL;
	free(tmp);
}
