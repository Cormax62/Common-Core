# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/22 15:09:04 by mbiagi            #+#    #+#              #
#    Updated: 2025/07/22 15:09:58 by mbiagi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROGRAM NAME
NAME =   Unnecessary_violence

# SRCS
SRC =  main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

CC = c++
RM = rm -rf
FLAGS = -Wall -Werror -Wextra -g
LIBX = -std=c++98

# FUNCTIONS

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(LIBX) $(SRC) -o $(NAME)

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