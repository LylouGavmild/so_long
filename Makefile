# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abutet <abutet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/26 15:30:32 by abutet            #+#    #+#              #
#    Updated: 2024/02/14 11:01:36 by abutet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=	cc

FLAG		=	-Wall -Wextra -Werror

LIBFT_PATH	=	./libft/

LIBFT_FILE	=	libft.a

MLX_FILE	=	libmlx.a

LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

MLX_FLAG	=	-lX11 -lXext -Lmlx  -L/usr/lib/X11

MLX_PATH	=	./minilibx-linux/

MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))

MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

C_FILE		=	main.c map_maker.c destroy.c destroy2.c read_map.c move.c map_check.c compte_cara.c \
				init.c init2.c error.c check_path.c sentinelle.c collision.c HUD.c HUD2.c exit.c \
				move2.c move3.c sentinelle2.c destroy_img.c bombe.c

SRC_DIR		=	./source/

GNL_FILE		=	get_next_line.c get_next_line_utils.c

GNL_DIR		=	./gnl/

INC_DIR		=	./header/

SRC			=	$(addprefix $(SRC_DIR),$(C_FILE))

GNL			=	$(addprefix $(GNL_DIR),$(GNL_FILE))

OBJ			=	$(SRC:.c=.o) $(GNL:.c=.o)

.c.o:
	$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

lib:
	make -C $(LIBFT_PATH)

mlx:
	make -sC $(MLX_PATH)

$(NAME): lib mlx $(OBJ)
	$(CC) $(OBJ) $(LIBFT_LIB) $(MLX_EX) -o $(NAME)

clean:
	make clean -sC $(MLX_PATH)
	make clean -sC $(LIBFT_PATH)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re