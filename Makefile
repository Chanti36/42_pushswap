CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = push_swap
NAME_BONUS = checker

SRCS =	code/algorithm.c			\
		code/algorithm_find.c		\
		code/algorithm_find_aux.c	\
		code/algorithm_move.c		\
		code/initialize.c 			\
		code/main.c 				\
		code/operations_one.c		\
		code/operations_two.c		\
		code/order_code.c			\
		code/check_input.c

BONUS_SRCS = 	bonus/check_input_bonus.c	\
				bonus/gnl_bonus.c			\
				bonus/gnl_utils_bonus.c 	\
				bonus/initialize_bonus.c 	\
				bonus/main_bonus.c			\
				bonus/operations_one_bonus.c\
				bonus/operations_two_bonus.c\

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

OBJS = $(SRCS:.c=.o)

all: $(NAME) 

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(OBJS) -o $(NAME) -Llibft/ -lft

libft/libft.a:
	make -C libft/

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS) libft/libft.a
	$(CC) $(BONUS_OBJS) -o $(NAME_BONUS) -Llibft/ -lft

clean:
	rm -rf $(OBJS)
	rm -rf $(BONUS_OBJS)
	make -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)
	make -C libft/ fclean

re: fclean $(NAME)
	make -C libft/ re


.PHONY: clean fclean re

del:
	@./a.out