# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 14:11:58 by mbiagi            #+#    #+#              #
#    Updated: 2025/02/26 08:46:34 by mbiagi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
BONUS = pipex_bonus
LIB = -Lprintf -lftprintf -L./libft -lft -Lget_next_line -lget_next_line -g

SRC = pipex.c pipex_utils.c

SRC_BONUS = pipex_bonus.c pipex_utils_bonus.c here_doc.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

$(NAME): $(OBJ)
	make -C libft/
	make -C printf/
	make -C get_next_line/
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

all: $(NAME) $(BONUS)

bonus: $(BONUS)

$(BONUS): $(OBJ_BONUS)
	make -C libft/
	make -C printf/
	make -C get_next_line/
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIB) -o $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -g -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	make clean -C libft/
	make clean -C printf/
	make clean -C get_next_line/

fclean: clean
	rm -f $(NAME) $(BONUS)
	make fclean -C libft/
	make fclean -C printf/
	make fclean -C get_next_line/
	

re: fclean all

.PHONY: all clean fclean re

.SILENT: