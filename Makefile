NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_split.c init_stack.c main.c push_ops.c r_rotate_ops.c rotate_ops.c sort_utils.c swap_utils.c swap_ops.c sort.c init_stack2.c

OBJ = $(SRC:.c=.o)

INCLUDES = push_swap.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re