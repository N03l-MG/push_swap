################################################################################
#                                                                              #
#                                    MAKEFILE                                  #
# Project:     push_swap                                                       #
# Created:     01/11/2024                                                      #
# Author:      kixk                                                            #
#                                                                              #
################################################################################

################################################################################
###############                     BUILD SETUP                  ###############
################################################################################

NAME = push_swap
BONUS = checker
CC = cc
FLAGS = -Wall -Wextra -Werror -Iinclude

################################################################################
###############                     DIRECTORIES                  ###############
################################################################################

SRC_DIR = src
BONUS_DIR = $(SRC_DIR)/bonus
COMMON_DIR = $(SRC_DIR)/common
MAIN_DIR = $(SRC_DIR)/main
LIBFT_DIR = libft

################################################################################
###############                    SOURCE FILES                  ###############
################################################################################

MAIN_SRC = main_push_swap.c sorting.c algorithm_utils.c node_transfer_utils.c \
		   simultaneous_rotation_utils.c
BONUS_SRC = checker_bonus.c
COMMON_SRC = parsing.c check_utils.c push_swap_operations.c rotation_operations.c \
			 seal.c ps_stacknew.c ps_stacksize.c ps_stackadd_top.c ps_stackadd_bottom.c

MAIN_SRC := $(addprefix $(MAIN_DIR)/, $(MAIN_SRC))
BONUS_SRC := $(addprefix $(BONUS_DIR)/, $(BONUS_SRC))
COMMON_SRC := $(addprefix $(COMMON_DIR)/, $(COMMON_SRC))

MAIN_OBJ = $(MAIN_SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
COMMON_OBJ = $(COMMON_SRC:.c=.o)

LIB = $(LIBFT_DIR)/libft.a

################################################################################
###############                 COMPILATION RULES                ###############
################################################################################

all: $(LIB) $(NAME) $(BONUS)

$(LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(MAIN_OBJ) $(COMMON_OBJ) $(LIB)
	$(CC) $(FLAGS) -o $(NAME) $(MAIN_OBJ) $(COMMON_OBJ) $(LIB)

$(BONUS): $(BONUS_OBJ) $(COMMON_OBJ) $(LIB)
	$(CC) $(FLAGS) -o $(BONUS) $(BONUS_OBJ) $(COMMON_OBJ) $(LIB)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(MAIN_OBJ) $(BONUS_OBJ) $(COMMON_OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re