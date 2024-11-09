NAME = push_swap
BONUS = checker
CC = gcc
FLAGS = -Wall -Wextra -Werror
SOURCE = main_push_swap.c parsing.c push_swap_operations.c rotation_operations.c seal.c \
		 sorting.c algorithm_utils.c node_transfer_utils.c simultaneous_rotation_utils.c

BONUS_SOURCE = bonus/checker_bonus.c bonus/utils_bonus.c bonus/parsing_bonus.c \
			   bonus/ps_ops_bonus.c bonus/rot_ops_bonus.c bonus/seal_bonus.c

LIB = libft/libft.a

OBJ = $(SOURCE:.c=.o)
BONUS_OBJ = $(BONUS_SOURCE:.c=.o)

all: $(LIB) $(NAME) $(BONUS)

$(LIB):
	$(MAKE) -C libft

$(NAME): $(OBJ) $(LIB)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB)

$(BONUS): $(BONUS_OBJ) $(OBJ) $(LIB)
	$(CC) $(FLAGS) -o $(BONUS) $(BONUS_OBJ) $(LIB)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

bonus/%.o: bonus/%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME) $(BONUS)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
