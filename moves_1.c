/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:56:37 by julberna          #+#    #+#             */
/*   Updated: 2023/10/21 17:54:02 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	t_stack	*temp;

	new_move(moves, PA);
	if (lstsize(*stack_a) <= 1)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
}

void	pb(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	t_stack	*temp;

	new_move(moves, PB);
	if (lstsize(*stack_b) <= 1)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
}

void	sa(t_stack **stack_a, t_moves **moves)
{
	t_stack	*temp;

	new_move(moves, SA);
	if (lstsize(*stack_a) <= 1)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = (*stack_a)->next;
	(*stack_a)->next = temp;
}

void	sb(t_stack **stack_b, t_moves **moves)
{
	t_stack	*temp;

	new_move(moves, SB);
	if (lstsize(*stack_b) <= 1)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = (*stack_b)->next;
	(*stack_b)->next = temp;
}
