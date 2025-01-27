# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 14:52:54 by mbiagi            #+#    #+#              #
#    Updated: 2025/01/21 15:35:14 by mbiagi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
CP = cp
NAME = libftprintf.a

SRC = ft_printf.c ft_putnbr_hex.c ft_putnbr_long.c ft_putnbr_un.c ft_putchar.c \
	ft_putstr.c ft_putnbr.c

OBJ = $(SRC:.c=.o)

all: $(NAME) $(LIBFT)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re