# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/13 10:03:42 by elefonta          #+#    #+#              #
#    Updated: 2024/09/24 09:08:28 by elefonta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_lib = libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3


SRCS_noprefix = main.c map_parser.c free_errors.c map.c

INCLUDES = -I./include -I./libft -I./minilibx-linux

MLX_FLAGS = -L./minilibx-linux -lmlx -L./usr/lib/X11 -lXext -lX11 -L lib/mlx -l mlx -I mlx -lXext -lX11 -lm -lz
LIBFT_FLAGS = -Llibft -lft

SRCS = $(addprefix src/, $(SRCS_noprefix))

OBJECTS = $(SRCS:src/%.c=obj/%.o)


all: $(NAME)


$(NAME): MINILIBX $(OBJECTS)
	make -C libft
	@$(CC) $(SRCS) $(CFLAGS) $(INCLUDES) -o $(NAME) $(MLX_FLAGS) $(LIBFT_FLAGS)
	@echo "Building so_long"

MINILIBX:
	make -C minilibx-linux


obj/%.o: src/%.c
	@mkdir -p obj
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


clean:
	@echo "Cleaning up object files"
	@rm -f $(OBJECTS)
	make -C libft clean


fclean: clean
	@echo "Cleaning up executables"
	@rm -f $(NAME)


re: fclean all


.PHONY: re all fclean clean
