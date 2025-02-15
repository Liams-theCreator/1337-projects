NAME = push_swap
CC = cc
FLAGS = -Werror -Wextra -Wall
SRC = pushswap.c input.c operations.c operations2.c operations3.c strfunc.c strfunc2.c strfunc3.c listfunc.c error_handling.c utils.c perfoms.c sorting.c sorting2.c algo_sort.c push_a2b.c push_b2a.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: clean fclean all re

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
