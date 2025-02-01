# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 09:27:58 by mbiagi            #+#    #+#              #
#    Updated: 2025/02/01 10:16:37 by mbiagi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
LIB = -Lprintf -lftprintf -L./libft -lft -g

SRC = push_swap_utils.c push_swap.c operations.c algorithm.c push_swap_utils2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make bonus -C libft/
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