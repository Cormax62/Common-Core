# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/28 11:35:23 by mbiagi            #+#    #+#              #
#    Updated: 2025/06/10 10:26:07 by mbiagi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo
LIB = -g -pthread

SRC = main.c philo_parse.c philo_utils.c init_data.c getter_setter.c action.c \
	monitor.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -g -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	

re: fclean all

.PHONY: all clean fclean re

.SILENT:
