/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:39:09 by julberna          #+#    #+#             */
/*   Updated: 2023/10/21 14:18:36 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define FAILURE	-1
# define INT_MAX	2147483647
# define INT_MIN	-2147483647

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

typedef enum msg
{
	SUCCESS = 0,
	NON_DIGIT,
	OUT_LIMIT,
	REPEAT,
	MSG_MAX,
}			t_msg;

int		message(int msg_code);
int		lstsize(t_stack *stack);
int		check_sort(t_stack *stack);

void	sort(t_stack **stack);
void	check_error(char *str);
void	free_args(char ***argv);
void	conclude(t_stack **stack);
void	populate(t_stack **stack);
void	add_index(t_stack **stack);
void	free_stack(t_stack **stack);
void	print_stack(t_stack *stack);
void	check_duplicate(t_stack **stack);
void	check_elements(int argc, char ***argv);
void	lstnew(t_stack **stack, int value, int pos);
void	lstiter(t_stack *stack, void (*f)(t_stack *));
void	create_stack(char **values, t_stack **stack_a);
void	verificate(int argc, char **argv, t_stack **stack);
void	stack_split(t_stack *stack, t_stack **right, t_stack **left);

t_stack	*lstlast(t_stack *stack);
t_stack	*duplicate(t_stack *stack);
t_stack	*merge(t_stack *left, t_stack *right);

#endif
