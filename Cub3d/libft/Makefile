
NAME = libft.a

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c  ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_itoa.c ft_split.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_is_quotes.c ft_isspace.c ft_rejoin.c ft_dup_matrix.c \
	ft_rematrix.c free_matrix.c matrix_len.c ft_restr.c \
	ft_strcmp.c ft_strncmp_2.c ft_atol.c ft_matrix_realloc.c

OBJ = $(SRC:.c=.o)

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUSOBJ = $(BONUS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ) $(BONUSOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all 

bonus: $(OBJ) $(BONUSOBJ)
	ar rcs $(NAME) $(OBJ) $(BONUSOBJ)

.PHONY: all clean fclean re bonus