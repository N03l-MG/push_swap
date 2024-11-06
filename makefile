NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
SOURCE = push_swap.c push_swap_operations.c rotation_operations.c \
		 sorting.c algorithm_utils.c node_transfer_utils.c simultaneous_rotation_utils.c 
LIB = libft/libft.a

OBJ = $(SOURCE:.c=.o)

all: $(LIB) $(NAME)

$(LIB):
	$(MAKE) -C libft

$(NAME): $(OBJ) $(LIB)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean 

re: fclean all

.PHONY: all clean fclean re
