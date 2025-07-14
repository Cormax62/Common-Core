
# PROGRAM NAME
NAME = cub3D
BONUS = cub3D_bonus

# SRCS
SRC = $(addprefix src/, \
		main.c parse_file.c utils.c free.c \
		init_all.c engine.c utils2.c raycasting_2d.c \
		colors.c init_engine.c move.c raycasting_2d_2.c)
BONUSSRC = $(addprefix bonus/, \
		main_bonus.c parse_file_bonus.c utils_bonus.c free_bonus.c \
		init_all_bonus.c engine_bonus.c utils2_bonus.c minimap_bonus.c \
		raycasting_2d_bonus.c colors_bonus.c init_engine_bonus.c \
		mouse_bonus.c move_bonus.c raycasting_2d_2_bonus.c action_bonus.c \
		init_sprites_bonus.c features_bonus.c sprites_bonus.c)

GNL = $(addprefix gnl/, get_next_line.c)
LIBFT = libft/libft.a
LIBFTDIR = libft
CC = cc
RM = rm -rf
FLAGS = -Wall -Werror -Wextra -g
MINILIBX = minilibx-linux
LIBX = -Lminilibx-linux -lmlx -lXext -lX11 -lm

# FUNCTIONS

all: minilibx libft $(NAME)
	@$(RM) $(BONUS)

$(NAME): $(GNL) $(SRC)
	$(CC) $(FLAGS) $^ $(LIBFT) $(LIBX) -o $(NAME)

minilibx:
	@make -C $(MINILIBX)

bonus: minilibx libft $(BONUS)
	@$(RM) $(NAME)

$(BONUS): $(GNL) $(BONUSSRC)
	$(CC) $(FLAGS) $^ $(LIBFT) $(LIBX) -o $(BONUS)
	
libft:
	@make -C $(LIBFTDIR)

clean: 
	@echo "Cleaning object_files..."
	@$(RM) $(OBJ)
	@make clean -C $(LIBFTDIR)

fclean: clean
	@echo "Cleaning executable"
	@$(RM) $(NAME) $(BONUS)
	@make fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all clean re fclean libft bonus

# .SILENT: