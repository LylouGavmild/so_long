# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abutet <abutet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 20:03:06 by abutet            #+#    #+#              #
#    Updated: 2023/11/15 14:19:46 by abutet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c\
		ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
		ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c\
		ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c\
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c\
		ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c\
		ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c

SRCSB =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c\
		ft_lstlast.c ft_lstadd_back.c ft_lstclear.c\
		ft_lstdelone.c ft_lstiter.c ft_lstmap.c

OBJSB = $(SRCSB:.c=.o)
OBJS	=  $(SRCS:.c=.o)

HEADERS	= libft.h/

NAME	= libft.a

%.o: %.c
	cc -Wall -Wextra -Werror -I $(HEADERS) -c $< -o $@


$(NAME) : $(OBJS)
		ar rcs $(NAME) $(OBJS)

all : $(NAME)

bonus: $(OBJSB)
	ar rcs $(NAME) $(OBJSB)

clean :
	rm -f $(OBJS)
	rm -f $(OBJSB)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all, clean, fclean, re, bonus

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCSB) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJSB) $(OBJS)