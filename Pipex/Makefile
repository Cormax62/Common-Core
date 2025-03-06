# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 14:11:58 by mbiagi            #+#    #+#              #
#    Updated: 2025/03/06 12:50:23 by mbiagi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = pipex

LIB = -Lprintf -lftprintf -L./libft -lft -Lget_next_line -lget_next_line -g

SRC = pipex.c pipex_utils.c pipex_utils2.c

SRC_BONUS = pipex_bonus.c pipex_utils_bonus.c pipex_utils2_bonus.c here_doc_bonus.c

INCLUDES = libft/libft.a get_next_line/libget_next_line.a

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

$(NAME): $(OBJ)
	make -C libft/
	make -C printf/
	make -C get_next_line/
	$(CC) $(CFLAGS) $(SRC) $(LIB) -o $(NAME)

all: $(NAME) bonus

bonus: $(OBJ_BONUS)
	make -C libft/
	make -C printf/
	make -C get_next_line/
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -g -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	make clean -C libft/
	make clean -C printf/
	make clean -C get_next_line/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/
	make fclean -C printf/
	make fclean -C get_next_line/

re: fclean all

.PHONY: all clean fclean re bonus

.SILENT: