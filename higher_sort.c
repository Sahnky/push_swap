/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   higher_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:52:13 by julberna          #+#    #+#             */
/*   Updated: 2023/10/24 18:13:17 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_current_position(t_stack **stack)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = *stack;
	while (*stack)
	{
		(*stack)->current_pos = i++;
		*stack = (*stack)->next;
	}
	*stack = temp;
}

void	get_target_position(t_stack **stack_a, t_stack **stack_b)
{
	int		highest;
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	while (*stack_b)
	{
		highest = INT_MAX;
		while (*stack_a)
		{
			if ((*stack_a)->index > (*stack_b)->index && \
				(*stack_a)->index < highest)
			{
				highest = (*stack_a)->index;
				(*stack_b)->target_pos = (*stack_a)->current_pos;
			}
			*stack_a = (*stack_a)->next;
		}
		*stack_a = temp_a;
		if (highest == INT_MAX)
			(*stack_b)->target_pos = get_smallest_index(*stack_a);
		*stack_b = (*stack_b)->next;
	}
	*stack_b = temp_b;
}

int	get_smallest_index(t_stack *stack)
{
	int	smallest;
	int	current_pos;

	smallest = stack->index;
	current_pos = stack->current_pos;
	while (stack)
	{
		if (stack->index < smallest)
		{
			smallest = stack->index;
			current_pos = stack->current_pos;
		}
		stack = stack->next;
	}
	return (current_pos);
}

t_stack	*choose_cheapest(t_stack *stack_b)
{
	int		cheapest;
	int		abs_a;
	int		abs_b;
	t_stack	*chosen;

	cheapest = INT_MAX;
	while (stack_b)
	{
		abs_a = stack_b->cost_a - (stack_b->cost_a < 0) * stack_b->cost_a * 2;
		abs_b = stack_b->cost_b - (stack_b->cost_b < 0) * stack_b->cost_b * 2;
		if (abs_a + abs_b < cheapest)
		{
			cheapest = abs_a + abs_b;
			chosen = stack_b;
		}
		stack_b = stack_b->next;
	}
	return (chosen);
}

void	rotate_sort(t_stack **stack, t_moves **moves)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->index != 0)
		temp = temp->next;
	if (temp->current_pos < lstsize(*stack) / 2)
	{
		while ((*stack)->value != temp->value)
			ra(stack, moves, 1);
	}
	else
	{
		while ((*stack)->value != temp->value)
			rra(stack, moves, 1);
	}
}
