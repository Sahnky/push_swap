NAME 	=	push_swap
BONUS	=	checker

CC		=	cc
CFLAGS	=	-Werror -Wall -Wextra -g3 -O3
LIBFT 	=	./libft/libft.a
INC_L	=	-I ./libft

OM_DIR	=	mandatory/obj/
SM_DIR	=	mandatory/src/
OB_DIR	=	bonus/obj/
SB_DIR	=	bonus/src/

M_ONE 	=	$(addprefix $(SM_DIR), push_swap.c)
M_TWO	=	$(addprefix $(SM_DIR), verification.c stack_handler.c sorting.c \
			moves_handler.c merge_sort.c populate.c moves_1.c sorting_utils.c \
			moves_2.c close.c higher_sort.c moves_execution.c calculate_cost.c \
			comparison.c)
SRC_M	+=	$(M_ONE)
SRC_M	+=	$(M_TWO)
OBJ_M 	=	$(SRC_M:$(SM_DIR)%.c=$(OM_DIR)%.o)
INC_M	=	-I ./mandatory/src

SRC_B	+=	$(addprefix $(SB_DIR), checker_bonus.c movements_bonus.c)
SRC_B	+=	$(M_TWO)
OBJ_B	=	$(SRC_B:$(SB_DIR)%.c=$(OB_DIR)%.o)

BLUE 	=	\033[1;36m
WHITE 	=	\033[0;39m
T_LIB	=	$(shell test -f ./libft/get_next_line_utils.o && echo "yes" 2>&1)

all: libft $(NAME)

$(NAME): $(OBJ_M)
	$(CC) $(CFLAGS) $(OBJ_M) $(INC_L) $(LIBFT) -o $@

bonus: libft $(BONUS)

$(BONUS): $(OBJ_B)
	$(CC) $(CFLAGS) $(OBJ_B) $(INC_L) $(INC_M) $(LIBFT) -o $@

$(OM_DIR)%.o: $(SM_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC_L) -c $< -o $@

$(OB_DIR)%.o: $(SB_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC_L) $(INC_M) -c $< -o $@

libft:
	@if ! [ $(T_LIB) ]; then echo "$(BLUE)-*- Creating libft library. -*-$(WHITE)";fi
	@make -C libft/ --no-print-directory

clean:
	@make clean -C ./libft --no-print-directory
	rm -rf $(OM_DIR)
	rm -rf $(OB_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all bonus libft clean fclean re
