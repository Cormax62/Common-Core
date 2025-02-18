# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 14:11:58 by mbiagi            #+#    #+#              #
#    Updated: 2025/02/17 15:16:16 by mbiagi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
LIB = -Lprintf -lftprintf -L./libft -lft -g

SRC = pipex.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C printf/
	$(CC) $(OBJ) $(LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -g -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C libft/
	make clean -C printf/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/
	make fclean -C printf/
	

re: fclean all

.PHONY: all clean fclean re

.SILENT: