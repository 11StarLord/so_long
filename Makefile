# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djoao <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 20:50:28 by djoao             #+#    #+#              #
#    Updated: 2024/11/01 20:50:32 by djoao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft -Iminilibx-linux
LIB = -lXext -lX11

LIBFT_DIR = ./libs/libft
PRINTF_DIR = ./libs/ft_printf
MINILIBX_DIR = ./libs/minilibx-linux

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
MINILIBX = $(MINILIBX_DIR)/libmlx_Linux.a

SRCS =	./srcs/so_long.c	\
	./srcs/initializer.c	\
	./srcs/init.c		\
	./srcs/map.c		\
	./srcs/player.c		\
	./srcs/draw.c		\
	./srcs/verify.c		\
	./srcs/verify_two.c	\
	./srcs/end_game.c	\
	./srcs/flood_fill_implementation.c
OBJS = $(SRCS:.c=.o)

$(NAME):	$(LIBFT) $(PRINTF) $(MINILIBX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF)  $(MINILIBX) $(LIB) -o $(NAME)
	@sleep 1
	clear

all:	$(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

$(MINILIBX):
	@make -C $(MINILIBX_DIR)

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)
	@make clean -C $(MINILIBX_DIR)
	clear

fclean:	clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)
	@sleep 1
	clear

re:	fclean all

.PHONY: all clean fclean re
