# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 10:54:47 by mbiagi            #+#    #+#              #
#    Updated: 2025/07/17 14:59:07 by mbiagi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROGRAM NAME
NAME = megaphone

# SRCS
SRC = megaphone.cpp

CC = c++
RM = rm -rf
FLAGS = -Wall -Werror -Wextra -g
LIBX = -std=c++98

# FUNCTIONS

all: $(NAME)

clean: 
	@echo "Cleaning object_files..."
	@$(RM) $(OBJ)

fclean: clean
	@echo "Cleaning executable"
	@$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean re fclean

# .SILENT: