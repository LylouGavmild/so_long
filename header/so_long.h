/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:25:28 by abutet            #+#    #+#             */
/*   Updated: 2024/02/15 12:42:28 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <time.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include "../gnl/get_next_line.h"

typedef struct s_img
{
	int		img_width;
	int		img_height;
	void	*img;
}				t_img;

typedef struct s_p_img
{
	t_img	up;
	t_img	up_1;
	t_img	up_2;
	t_img	down;
	t_img	down_1;
	t_img	down_2;
	t_img	right;
	t_img	right_1;
	t_img	right_2;
	t_img	left;
	t_img	left_1;
	t_img	left_2;
}				t_p_img;

typedef struct s_nb_img
{
	t_img	img_0;
	t_img	img_1;
	t_img	img_2;
	t_img	img_3;
	t_img	img_4;
	t_img	img_5;
	t_img	img_6;
	t_img	img_7;
	t_img	img_8;
	t_img	img_9;
}				t_nb_img;

typedef struct s_img_list
{
	t_img		img_wall;
	t_img		img_sol;
	t_img		img_c;
	t_img		img_c_b;
	t_img		img_void;
	t_p_img		img_p;
	t_img		img_e;
	t_img		img_s;
	t_img		img_s_h;
	t_img		img_s_v;
	t_img		img_b;
	t_nb_img	nb;
	t_img		img_step;
	t_img		img_x;
	t_img		img_slash;
	t_img		img_bb;
	t_img		img_explosion;
	t_img		img_rock;
}				t_img_list;

typedef struct s_win
{
	int		win_width;
	int		win_height;
	void	*win;
}				t_win;

typedef struct s_map
{
	char	**map;
	int		row_len;
	int		col_len;
	int		c;
	int		e;
	int		p;
}				t_map;

typedef struct s_coord
{
	int				x;
	int				y;
	int				time;
	int				e;
	struct s_coord	*next;
}				t_coord;

typedef struct s_bomb
{
	int		nb;
	int		nb_max;
	int		speed;
	int		rayon;
	t_coord	*coord;
}				t_b;

typedef struct s_playeur
{
	int		x;
	int		y;
	int		c;
	int		m;
	int		time;
	char	d;
	t_b		b;
}				t_p;

typedef struct s_sentinelle
{
	int					x;
	int					y;
	int					live;
	int					time;
	char				d;
	struct s_sentinelle	*next;
}				t_s;

typedef struct s_exit
{
	int			x;
	int			y;
	int			o;
	time_t		time;
}				t_exit;

typedef struct s_mlx
{
	void		*mlx;
	t_p			playeur;
	t_win		win;
	t_img_list	img;
	t_map		map;
	t_s			*senti;
	t_exit		exit;
	int			step;
	char		*path;
}				t_mlx;

void			map_maker(t_mlx *game);
void			player_init(t_mlx *game);
void			make_case(char c, t_mlx *game, int col, int row);
void			make_p(char c, t_mlx game, int col, int row);
void			make_s(t_mlx *game, int col, int row);
char			**read_map(char *file);
int				key_press(int keysym, t_mlx *game);
void			set_img(t_mlx *game, t_img *img, char *path);
void			destroy_map(t_map *map);
void			move_r(t_mlx *game);
void			move_l(t_mlx *game);
void			move_d(t_mlx *game);
void			move_u(t_mlx *game);
int				len_check(t_mlx *game);
int				compte_cara(t_mlx *game);
void			map_comp(t_mlx *game);
void			c_check(t_mlx *game);
int				end(t_mlx *game);
void			map_check(t_mlx *game);
void			flood_fill(t_map *map, int x, int y);
void			map_init(t_map *map, char *path);
void			img_init(t_mlx *game);
void			init_null(t_mlx *game);
void			win_init(t_mlx *game);
void			check_path(t_mlx *game, char *path);
void			ft_error(t_mlx *game, char *msg);
int				main_senti(t_mlx *game);
void			ft_sadd_back(t_s **lst, t_s *newnode);
t_s				*ft_snew(int x, int y);
int				collision(int x1, int y1, int x2, int y2);
int				sui(t_mlx *game, int x, int y);
void			hud(t_mlx *game);
void			step(t_mlx *game);
void			coin(t_mlx *game);
void			exit_anim(t_mlx	*game);
int				main_loop(t_mlx *game);
void			move_anim_u(t_mlx *game);
void			move_anim_d(t_mlx *game);
void			move_anim_l(t_mlx *game);
void			move_anim_r(t_mlx *game);
void			s_rand(t_mlx *game, t_s *senti);
void			destroy_img(t_mlx *game);
void			planto_bombo(t_mlx *game);
void			spreed(t_mlx *game, t_coord *bombe);
void			explosion(t_mlx *game);
void			rock(t_mlx *game, t_coord *bombe);
void			kill(t_mlx *game, t_coord *bombe);
void			ff(t_mlx *game, t_coord *bombe);
void			chaine(t_mlx *game, t_coord *bombe);
void			clean(t_mlx *game, t_coord *bombe);
void			clean_lst(t_coord **lst, t_coord **bombe);

#endif