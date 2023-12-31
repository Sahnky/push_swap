/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:39:09 by julberna          #+#    #+#             */
/*   Updated: 2023/10/27 00:51:54 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../../libft/libft.h"

# define FAILURE	-1
# define SUCCESS	0
# define INT_MAX	2147483647
# define INT_MIN	-2147483648

typedef struct s_stack
{
	int				value;
	int				index;
	int				current_pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}				t_stack;

typedef struct s_moves
{
	int				move;
	struct s_moves	*next;
}				t_moves;

typedef enum e_operations
{
	SA = 0,
	SB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	PA,
	PB,
	RRR,
	SS,
	OP_MAX,
}			t_operations;

/* Main calls */
void	add_index(t_stack **stack);
void	verificate(int argc, char **argv, t_stack **stack);
void	sorting(t_stack **stack_a, t_stack **stack_b, t_moves **moves);
void	conclude(t_stack **stack_a, t_stack **stack_b, t_moves **moves);

/* Verification */
int		check_error(char *str);
int		check_sort(t_stack *stack);
void	check_duplicate(t_stack **stack);
char	**copy_argv(int argc, char **argv);
void	duplicate(t_stack *stack, t_stack **dupe);
int		copy_single_argv(char **argv, char ***arguments);
int		copy_multi_argv(int argc, char **argv, char ***arguments);
void	check_elements(int argc, char **argv, t_stack **stack, int i);

/* List manipulation */
int		lstsize(t_stack *stack);
int		moves_size(t_moves *moves);
void	moves_message(int msg_code);
void	print_moves(t_moves *moves);
void	new_move(t_moves **moves, int move);
void	lstiter(t_stack *stack, void (*f)(t_stack *));
void	new_stack(t_stack **stack, int value, int pos);
void	create_stack(char **values, t_stack **stack_a);
t_moves	*moves_last(t_moves *moves);
t_stack	*stack_last(t_stack *stack);
t_stack	*stack_penult(t_stack *stack);

/* Merge sort */
void	sort(t_stack **stack);
void	stack_split(t_stack *stack, t_stack **right, t_stack **left);
t_stack	*merge(t_stack *left, t_stack *right);

/* Push Swap movements */
void	sa(t_stack **stack_a, t_moves **moves);
void	sb(t_stack **stack_b, t_moves **moves);
void	ra(t_stack **stack_a, t_moves **moves, int flag);
void	rb(t_stack **stack_b, t_moves **moves, int flag);
void	rra(t_stack **stack_a, t_moves **moves, int flag);
void	rrb(t_stack **stack_b, t_moves **moves, int flag);
void	rr(t_stack **stack_a, t_stack **stack_b, t_moves **moves);
void	pa(t_stack **stack_a, t_stack **stack_b, t_moves **moves);
void	pb(t_stack **stack_a, t_stack **stack_b, t_moves **moves);
void	rrr(t_stack **stack_a, t_stack **stack_b, t_moves **moves);

/* Push Swap logic */
void	sort_3(t_stack **stack_a, t_moves **moves);
void	sort_5(t_stack **stack_a, t_stack **stack_b, t_moves **moves);
void	push_to_b(t_stack **stack_a, t_stack **stack_b, t_moves **moves);
void	push_to_a(t_stack **stack_a, t_stack **stack_b, t_moves **moves);
void	sort_larger(t_stack **stack_a, t_stack **stack_b, t_moves **moves);
void	push_larger(t_stack **stack_a, t_stack **stack_b, t_moves **moves);
void	push_smaller(t_stack **stack_a, t_stack **stack_b, t_moves **moves);
void	one_way(t_stack **a, t_stack **b, t_stack **dupe_1, t_moves	**one_way);
void	another(t_stack **a, t_stack **b, t_stack **dupe_2, t_moves	**another);

/* Push Swap logic utils */
int		get_smallest_index(t_stack *stack);
void	get_current_position(t_stack **stack);
void	b_cost(t_stack **stack_b, int size_b);
void	rotate_sort(t_stack **stack, t_moves **moves);
void	a_cost(t_stack **stack_a, t_stack **stack_b, int size_a);
void	get_target_position(t_stack **stack_a, t_stack **stack_b);
void	calculate_move_cost(t_stack **stack_a, t_stack **stack_b);
void	execute_cheapest(t_stack **stack_a, t_stack **stack_b, t_moves **moves);
void	dual_rx(t_stack **a, t_stack **b, t_moves **move, t_stack *chosen);
void	dual_rrx(t_stack **a, t_stack **b, t_moves **move, t_stack *chosen);
void	sole_rx(t_stack **a, t_stack **b, t_moves **move, t_stack *chosen);
t_stack	*choose_cheapest(t_stack *stack_b);

/* Conclude */
void	free_stack(t_stack **stack);
void	free_moves(t_moves **moves);
void	error_handling(char **arguments, int flag, int size);

#endif
