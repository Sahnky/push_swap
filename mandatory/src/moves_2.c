/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:57:00 by julberna          #+#    #+#             */
/*   Updated: 2023/10/22 16:38:53 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a, t_moves **moves, int flag)
{
	t_stack	*temp;

	if (flag)
		new_move(moves, RA);
	if (lstsize(*stack_a) <= 1)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	stack_last(*stack_a)->next = temp;
}

void	rb(t_stack **stack_b, t_moves **moves, int flag)
{
	t_stack	*temp;

	if (flag)
		new_move(moves, RB);
	if (lstsize(*stack_b) <= 1)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = NULL;
	stack_last(*stack_b)->next = temp;
}

void	rra(t_stack **stack_a, t_moves **moves, int flag)
{
	t_stack	*temp;

	if (flag)
		new_move(moves, RRA);
	if (lstsize(*stack_a) <= 1)
		return ;
	temp = stack_last(*stack_a);
	stack_penult(*stack_a)->next = NULL;
	temp->next = *stack_a;
	*stack_a = temp;
}

void	rrb(t_stack **stack_b, t_moves **moves, int flag)
{
	t_stack	*temp;

	if (flag)
		new_move(moves, RRB);
	if (lstsize(*stack_b) <= 1)
		return ;
	temp = stack_last(*stack_b);
	stack_penult(*stack_b)->next = NULL;
	temp->next = *stack_b;
	*stack_b = temp;
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	new_move(moves, RRR);
	rra(stack_a, moves, 0);
	rrb(stack_b, moves, 0);
}
