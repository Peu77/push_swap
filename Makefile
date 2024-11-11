NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(FTPRINTF_DIR)/src -I $(FTPRINTF_DIR)/libft/

FTPRINTF_DIR = ft_printf
FTPRINTF_LIB = $(FTPRINTF_DIR)/libftprintf.a

COMMON_SRC = operations_utils.c operations.c operations2.c operations3.c parse.c

SRC = push_swap.c sort.c longest_sequence.c costs.c moves.c array_utils.c special_sort.c $(COMMON_SRC)
SRC_BONUS = checker.c visualizer.c $(COMMON_SRC)

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

GREEN = \e[32m
RED = \e[31m
BLUE = \e[34m
RESET = \e[0m

all: $(NAME) $(NAME_BONUS)

run: all
	./$(NAME) 2 1 3 6 5 8 7 4

$(NAME): $(OBJ) $(FTPRINTF_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(FTPRINTF_LIB)

bonus: $(NAME_BONUS)

bonus_bonus: CFLAGS += -DBONUS_BONUS
bonus_bonus: re

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

test: all
	@printf "$(BLUE)Running 500 tests with 100 numbers...$(RESET)\n"
	@printf "$(BLUE)=========================$(RESET)\n"
	@SUM_100=0; \
	OK_COUNT_100=0; \
	for i in {1..500}; do \
		COUNT=100; \
		NUMBERS=`seq 1 $$COUNT | shuf`; \
		MOVES=`./$(NAME) $$NUMBERS | wc -l`; \
		SUM_100=$$((SUM_100 + MOVES)); \
		printf "Test $$i ($$COUNT numbers): "; \
		if [ $$MOVES -le 700 ]; then \
			printf "$(GREEN)OK$(RESET) "; \
			OK_COUNT_100=$$((OK_COUNT_100 + 1)); \
		else \
			printf "$(RED)KO$(RESET) "; \
		fi; \
		printf "$$MOVES moves\n"; \
		OUTPUT=`./$(NAME) $$NUMBERS | ./$(NAME_BONUS) $$NUMBERS`; \
		if [ "$$OUTPUT" = "OK" ]; then \
			printf "$(GREEN)Checker: OK$(RESET)\n"; \
		else \
			printf "$(RED)Checker: KO$(RESET)\n"; \
		fi; \
		printf "\n"; \
	done; \
	AVG_100=$$((SUM_100 / 500)); \
	printf "$(BLUE)Results for 100 numbers:$(RESET)\n"; \
	printf "Average moves: $$AVG_100\n"; \
	printf "Tests within limit: $$OK_COUNT_100/500\n\n"; \
	\
	printf "$(BLUE)Running 500 tests with 500 numbers...$(RESET)\n"
	@printf "$(BLUE)=========================$(RESET)\n"
	@SUM_500=0; \
	OK_COUNT_500=0; \
	for i in {1..500}; do \
		COUNT=500; \
		NUMBERS=`seq 1 $$COUNT | shuf`; \
		MOVES=`./$(NAME) $$NUMBERS | wc -l`; \
		SUM_500=$$((SUM_500 + MOVES)); \
		printf "Test $$i ($$COUNT numbers): "; \
		if [ $$MOVES -le 5700 ]; then \
			printf "$(GREEN)OK$(RESET) "; \
			OK_COUNT_500=$$((OK_COUNT_500 + 1)); \
		else \
			printf "$(RED)KO$(RESET) "; \
		fi; \
		printf "$$MOVES moves\n"; \
		OUTPUT=`./$(NAME) $$NUMBERS | ./$(NAME_BONUS) $$NUMBERS`; \
		if [ "$$OUTPUT" = "OK" ]; then \
			printf "$(GREEN)Checker: OK$(RESET)\n"; \
		else \
			printf "$(RED)Checker: KO$(RESET)\n"; \
		fi; \
		printf "\n"; \
	done; \
	AVG_500=$$((SUM_500 / 500)); \
	printf "$(BLUE)Results for 500 numbers:$(RESET)\n"; \
	printf "Average moves: $$AVG_500\n"; \
	printf "Tests within limit: $$OK_COUNT_500/500\n\n"; \
	printf "$(BLUE)Overall Summary:$(RESET)\n"; \
	printf "100 numbers - Average moves: $$AVG_100 (Limit: 700)\n"; \
	printf "500 numbers - Average moves: $$AVG_500 (Limit: 5500)\n"

.PHONY: all clean fclean re bonus test