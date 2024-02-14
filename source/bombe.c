/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bombe.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:19:34 by abutet            #+#    #+#             */
/*   Updated: 2024/02/14 14:56:07 by abutet           ###   ########.fr       */
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
		&& (*game).map.map[(*game).playeur.y][(*game).playeur.x] != 'E')
	{
		bombe = ft_bnew((*game).playeur.x, (*game).playeur.y);
		ft_badd_back(&(*game).playeur.b.coord, bombe);
		(*game).map.map[(*game).playeur.y][(*game).playeur.x] = 'B';
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_bb.img, (*bombe).x * 64, (*bombe).y * 64 + 128);
		(*game).playeur.b.nb++;
	}
}

void	chaine(t_mlx *game, t_coord *bombe)
{
	t_coord	*other;
	int		i;

	other = (*game).playeur.b.coord;
	while (other)
	{
		i = 0;
		while (i <= (*game).playeur.b.rayon)
		{
			if ((collision((*other).x, (*other).y, (*bombe).x + i, (*bombe).y)
					|| collision((*other).x, (*other).y, (*bombe).x - i,
						(*bombe).y) || collision((*other).x, (*other).y,
						(*bombe).x, (*bombe).y + i)
					|| collision((*other).x, (*other).y, (*bombe).x,
						(*bombe).y - i)) && (*other).e)
			{
				if ((*other).time != (*game).playeur.b.speed)
					(*other).time = (*game).playeur.b.speed;
				spreed(game, other);
			}
			i++;
		}
		other = (*other).next;
	}
}

void	make_e2(t_mlx *game, t_coord *bombe)
{
	int	i;

	i = 0;
	while ((*game).map.map[(*bombe).y][(*bombe).x + i] != '1'
			&& i <= (*game).playeur.b.rayon)
	{
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_explosion.img, ((*bombe).x + i) * 64,
			(*bombe).y * 64 + 128);
		i++;
	}
	i = 0;
	while ((*game).map.map[(*bombe).y][(*bombe).x - i] != '1'
			&& i <= (*game).playeur.b.rayon)
	{
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_explosion.img, ((*bombe).x - i) * 64,
			(*bombe).y * 64 + 128);
		i++;
	}
}

void	make_e(t_mlx *game, t_coord *bombe)
{
	int	i;

	i = 0;
	while ((*game).map.map[(*bombe).y + i][(*bombe).x] != '1'
			&& i <= (*game).playeur.b.rayon)
	{
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_explosion.img, (*bombe).x * 64,
			((*bombe).y + i) * 64 + 128);
		i++;
	}
	i = 0;
	while ((*game).map.map[(*bombe).y - i][(*bombe).x] != '1'
			&& i <= (*game).playeur.b.rayon)
	{
		mlx_put_image_to_window((*game).mlx, (*game).win.win,
			(*game).img.img_explosion.img, (*bombe).x * 64,
			((*bombe).y - i) * 64 + 128);
		i++;
	}
	make_e2(game, bombe);
}

void	ff(t_mlx *game, t_coord *bombe)
{
	int		i;

	i = 0;
	while (i <= (*game).playeur.b.rayon)
	{
		if (collision((*game).playeur.x, (*game).playeur.y, (*bombe).x + i,
				(*bombe).y)
			|| collision((*game).playeur.x, (*game).playeur.y, (*bombe).x - i,
				(*bombe).y)
			|| collision((*game).playeur.x, (*game).playeur.y, (*bombe).x,
				(*bombe).y + i)
			|| collision((*game).playeur.x, (*game).playeur.y, (*bombe).x,
				(*bombe).y - i))
			ft_error(game, "MACRON EXPLOSION\n");
		i++;
	}
}

void	spreed(t_mlx *game, t_coord *bombe)
{
	t_s		*tmp;
	int		i;

	tmp = (*game).senti;
	while (tmp)
	{
		i = 0;
		while (i <= (*game).playeur.b.rayon)
		{
			if (collision((*tmp).x, (*tmp).y, (*bombe).x + i, (*bombe).y)
				|| collision((*tmp).x, (*tmp).y, (*bombe).x - i, (*bombe).y)
				|| collision((*tmp).x, (*tmp).y, (*bombe).x, (*bombe).y + i)
				|| collision((*tmp).x, (*tmp).y, (*bombe).x, (*bombe).y - i))
				(*tmp).live = 0;
			i++;
		}
		tmp = (*tmp).next;
	}
	(*bombe).e = 0;
	chaine(game, bombe);
	ff(game, bombe);
	if ((*bombe).time == (*game).playeur.b.speed)
		make_e(game, bombe);
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

void	clean2(t_mlx *game, t_coord *bombe)
{
	int	i;

	i = 0;
	while ((*game).map.map[(*bombe).y][(*bombe).x + i] != '1'
			&& i <= (*game).playeur.b.rayon)
	{
		make_case((*game).map.map[(*bombe).y][(*bombe).x + i], game,
			(*bombe).y, (*bombe).x + i);
		i++;
	}
	i = 0;
	while ((*game).map.map[(*bombe).y][(*bombe).x - i] != '1'
			&& i <= (*game).playeur.b.rayon)
	{
		make_case((*game).map.map[(*bombe).y][(*bombe).x - i] , game,
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
			&& i <= (*game).playeur.b.rayon)
	{
		make_case((*game).map.map[(*bombe).y + i][(*bombe).x], game,
			(*bombe).y + i, (*bombe).x);
		i++;
	}
	i = 0;
	while ((*game).map.map[(*bombe).y - i][(*bombe).x] != '1'
			&& i <= (*game).playeur.b.rayon)
	{
		make_case((*game).map.map[(*bombe).y - i][(*bombe).x], game,
			(*bombe).y - i, (*bombe).x);
		i++;
	}
	clean2(game, bombe);
}

void	explosion(t_mlx *game)
{
	t_coord	*tmp;

	tmp = (*game).playeur.b.coord;
	while (tmp)
	{
		if ((*tmp).time >= (*game).playeur.b.speed
			&& (*tmp).time < (*game).playeur.b.speed + 5000)
			spreed(game, tmp);
		else if ((*tmp).time == (*game).playeur.b.speed + 5002)
		{
			clean(game, tmp);
			clean_lst(&(*game).playeur.b.coord, &tmp);
			(*game).playeur.b.nb--;
			continue ;
		}
		(*tmp).time++;
		tmp = (*tmp).next;
	}
}
