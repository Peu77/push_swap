NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(FTPRINTF_DIR)/src -I $(FTPRINTF_DIR)/libft/

FTPRINTF_DIR = ft_printf
FTPRINTF_LIB = $(FTPRINTF_DIR)/libftprintf.a

COMMON_SRC = operations_utils.c operations.c operations2.c operations3.c

SRC = push_swap.c  parse.c sort.c stack.c longest_sequence.c costs.c moves.c array_utils.c $(COMMON_SRC)
SRC_BONUS = checker.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

run: all
	./$(NAME) 2 1 3 6 5 8 7 4

$(NAME): $(OBJ) $(FTPRINTF_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(FTPRINTF_LIB)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)  $(FTPRINTF_LIB)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(FTPRINTF_LIB)

$(FTPRINTF_LIB):
	make -C $(FTPRINTF_DIR)

clean:
	make -C $(FTPRINTF_DIR) clean
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	make -C $(FTPRINTF_DIR) fclean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus