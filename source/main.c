/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:47:01 by abutet            #+#    #+#             */
/*   Updated: 2024/02/14 11:05:48 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	transi(t_mlx game, t_img img)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i - j < game.win.win_height / 64)
	{
		j = 0;
		while (j < game.win.win_width / 64)
		{
			mlx_put_image_to_window(game.mlx, game.win.win, img.img,
				(i - j) * 64, j * 64);
			j++;
		}
		usleep(10000);
		i++;
	}
}

int	transition(t_mlx game)
{
	transi(game, game.img.img_wall);
	transi(game, game.img.img_void);
	return (1);
}

int	main(int argc, char **argv)
{
	t_mlx	game;

	if (argc == 2)
	{
		init_null(&game);
		check_path(&game, argv[1]);
		game.mlx = mlx_init();
		if (game.mlx == NULL)
			ft_error(&game, "mlx crash\n");
		img_init(&game);
		map_init(&game.map, game.path);
		map_check(&game);
		win_init(&game);
		hud(&game);
		map_maker(&game);
		mlx_hook(game.win.win, KeyPress, KeyPressMask, &key_press, &game);
		mlx_hook(game.win.win, DestroyNotify, NoEventMask, &end, &game);
		mlx_loop_hook(game.mlx, &main_loop, &game);
		mlx_loop(game.mlx);
	}
	return (0);
}

int	key_press(int keysym, t_mlx *game)
{
	if (keysym == XK_Escape)
		end(game);
	else if (keysym == XK_Return)
		transition((*game));
	else if (keysym == XK_Up)
		move_u(game);
	else if (keysym == XK_Down)
		move_d(game);
	else if (keysym == XK_Right)
		move_r(game);
	else if (keysym == XK_Left)
		move_l(game);
	else if (keysym == XK_space)
	{
		write(1, "a\n", 2);
		planto_bombo(game);
	}
	return (0);
}
