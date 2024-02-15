/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentinelle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:00:49 by abutet            #+#    #+#             */
/*   Updated: 2024/02/15 14:43:55 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	live(t_mlx *game, t_s *senti)
{
	if ((*senti).time < 2750)
		make_case((*game).map.map[(*senti).y][(*senti).x], game,
			(*senti).y, (*senti).x);
	else
	{
		if ((*senti).d == 'u')
			make_case((*game).map.map[(*senti).y + 1][(*senti).x], game,
				(*senti).y + 1, (*senti).x);
		if ((*senti).d == 'd')
			make_case((*game).map.map[(*senti).y - 1][(*senti).x], game,
				(*senti).y - 1, (*senti).x);
		if ((*senti).d == 'l')
			make_case((*game).map.map[(*senti).y][(*senti).x + 1], game,
				(*senti).y, (*senti).x + 1);
		if ((*senti).d == 'r')
			make_case((*game).map.map[(*senti).y][(*senti).x - 1], game,
				(*senti).y, (*senti).x - 1);
		make_case((*game).map.map[(*senti).y][(*senti).x], game,
			(*senti).y, (*senti).x);
	}
	(*senti).time = -1;
}

void	move_s(t_mlx *game, t_s *senti)
{
	if ((*senti).time == 2750)
	{
		s_rand(game, senti);
		if (collision((*senti).x, (*senti).y, (*game).playeur.x,
				(*game).playeur.y))
			ft_error(game, "TOULOUSE\n");
	}
	if ((*senti).time == 5500)
	{
		if ((*senti).d == 'u')
			make_case((*game).map.map[(*senti).y + 1][(*senti).x], game,
				(*senti).y + 1, (*senti).x);
		if ((*senti).d == 'd')
			make_case((*game).map.map[(*senti).y - 1][(*senti).x], game,
				(*senti).y - 1, (*senti).x);
		if ((*senti).d == 'l')
			make_case((*game).map.map[(*senti).y][(*senti).x + 1], game,
				(*senti).y, (*senti).x + 1);
		if ((*senti).d == 'r')
			make_case((*game).map.map[(*senti).y][(*senti).x - 1], game,
				(*senti).y, (*senti).x - 1);
		make_s(game, (*senti).y, (*senti).x);
		(*senti).time = 0;
	}
}

int	main_senti(t_mlx *game)
{
	t_s	*tmp;

	tmp = (*game).senti;
	while (tmp)
	{
		if ((*tmp).live == 1 && (*tmp).time >= 0)
		{
			(*tmp).time++;
			move_s(game, tmp);
		}
		else if ((*tmp).live == 0 && (*tmp).time >= 0)
			live(game, tmp);
		tmp = (*tmp).next;
	}
	return (0);
}

t_s	*ft_snew(int x, int y)
{
	t_s	*s;

	s = malloc(sizeof(t_s));
	if (!s)
		return (NULL);
	(*s).live = 1;
	(*s).next = NULL;
	(*s).x = x;
	(*s).y = y;
	(*s).time = 0;
	(*s).d = 'd';
	return (s);
}

void	ft_sadd_back(t_s **lst, t_s *newnode)
{
	t_s	*start;

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
