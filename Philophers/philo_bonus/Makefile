# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/10 10:39:38 by mbiagi            #+#    #+#              #
#    Updated: 2025/06/10 10:39:39 by mbiagi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
OBJ_DIR = obj_dir
SRC = 	utils_bonus.c \
		routine_bonus.c \
		philo_parsing.c \
		memory_bonus.c \
		main_bonus.c \
		action_bonus.c \
		getter_setter_bonus.c \
		thread_bonus.c

OBJ    = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))
COMP = cc -g -Wall -Wextra -Werror
LFLAGS = -lpthread


$(NAME) : $(OBJ) $(OBJ_DIR)
	$(COMP) $(OBJ) -o $(NAME) $(LFLAGS)
	@echo "\n$(NAME) done!!"

all: $(NAME)


$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(COMP) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(sort $(dir $(OBJ)))

clean: 
	@rm -f $(OBJ) $(ALL) $(NAME) $(NAME_BONUS) *.out *.gdb  *.supp *.txt *.sh
	@rm -rf $(OBJ_DIR) $(BONUS_DIR) $(OBJ_BONUS_DIR)

clear: 
	clear

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus debug supp
