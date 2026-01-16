NAME = pushswap.a
FLAGS = -Wall -Wextra -Werror
SRC = main.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

clean:
	rm -rvf $(OBJ)

fclean: clean
	rm -rvf $(NAME)

re: fclean all

.PHONY: all clean fclean re