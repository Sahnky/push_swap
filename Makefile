NAME 	= push_swap

CC		= cc
CFLAGS	= -Werror -Wall -Wextra -g3
LIBFT 	= ./libft/libft.a

SRC 	= push_swap.c verification.c
OBJ 	= $(SRC:%.c=%.o)
INC		= -I push_swap.h

BLUE 		= \033[1;36m
WHITE 		= \033[0;39m
T_LIB		= $(shell test -f ./libft/get_next_line_utils.o && echo "yes" 2>&1)

all: libft $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INC) $(LIBFT) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	@if ! [ $(T_LIB) ]; then echo "$(BLUE)-*- Creating libft library. -*-$(WHITE)";fi
	@make -C libft/ --no-print-directory

clean:
	@make clean -C ./libft --no-print-directory
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all libft clean fclean re
