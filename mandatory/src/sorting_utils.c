/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:25:24 by julberna          #+#    #+#             */
/*   Updated: 2023/10/26 22:32:11 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	int		middle;

	middle = lstsize(*stack_a) / 2;
	while (lstsize(*stack_a) > middle && lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->index <= middle)
		{
			pb(stack_a, stack_b, moves);
		}
		else
			ra(stack_a, moves, 1);
	}
	while (lstsize(*stack_a) > 3)
		pb(stack_a, stack_b, moves);
}

void	push_to_a(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	if (*stack_b == NULL)
		return ;
	get_current_position(stack_b);
	get_current_position(stack_a);
	get_target_position(stack_a, stack_b);
	calculate_move_cost(stack_a, stack_b);
	execute_cheapest(stack_a, stack_b, moves);
	push_to_a(stack_a, stack_b, moves);
}

void	push_larger(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	t_stack	*chosen;
	t_stack	*temp_a;

	temp_a = *stack_a;
	chosen = *stack_a;
	get_current_position(stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->value > chosen->value)
			chosen = *stack_a;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = temp_a;
	if (chosen->current_pos <= lstsize(*stack_a))
	{
		while ((*stack_a)->value != chosen->value)
			ra(stack_a, moves, 1);
	}
	else
	{
		while ((*stack_a)->value != chosen->value)
			rra(stack_a, moves, 1);
	}
	pb(stack_a, stack_b, moves);
}

void	push_smaller(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	t_stack	*chosen;
	t_stack	*temp_a;

	temp_a = *stack_a;
	chosen = *stack_a;
	get_current_position(stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->value < chosen->value)
			chosen = *stack_a;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = temp_a;
	if (chosen->current_pos <= lstsize(*stack_a))
	{
		while ((*stack_a)->value != chosen->value)
			ra(stack_a, moves, 1);
	}
	else
	{
		while ((*stack_a)->value != chosen->value)
			rra(stack_a, moves, 1);
	}
	pb(stack_a, stack_b, moves);
}

int	moves_size(t_moves *moves)
{
	int	len;

	if (moves == NULL)
		return (0);
	len = 1;
	while (moves->next != NULL)
	{
		len++;
		moves = moves->next;
	}
	return (len);
}
