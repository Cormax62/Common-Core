# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 13:47:55 by mbiagi            #+#    #+#              #
#    Updated: 2025/01/27 09:29:53 by mbiagi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
LIB = -Lminilibx-linux -lmlx -lXext -lX11 -Lget_next_line -lget_next_line -Lprintf -lftprintf -L./libft -lft

SRC = so_long_map.c so_long_utils.c so_long.c map_control.c destroy.c immage_control.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C printf/
	make -C get_next_line/
	make -C libft/
	$(CC) $(OBJ) $(LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -g -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C printf/
	make clean -C get_next_line/
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C printf/
	make fclean -C get_next_line/
	make fclean -C libft/
	

re: fclean all

.PHONY: all clean fclean re

.SILENT: