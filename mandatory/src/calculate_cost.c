/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:12:17 by julberna          #+#    #+#             */
/*   Updated: 2023/10/24 18:17:36 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_move_cost(t_stack **stack_a, t_stack **stack_b)
{
	int		size_a;
	int		size_b;
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	size_a = lstsize(*stack_a);
	size_b = lstsize(*stack_b);
	while (*stack_b)
	{
		(*stack_b)->cost_a = 0;
		b_cost(stack_b, size_b);
		a_cost(stack_a, stack_b, size_a);
		*stack_b = (*stack_b)->next;
		*stack_a = temp_a;
	}
	*stack_b = temp_b;
}

void	b_cost(t_stack **stack_b, int size_b)
{
	if ((*stack_b)->current_pos <= size_b / 2 || size_b == 1)
	{
		(*stack_b)->cost_b = 1;
		(*stack_b)->cost_b += (*stack_b)->current_pos;
	}
	else
	{
		(*stack_b)->cost_b = -1;
		(*stack_b)->cost_b += -1 * (size_b - (*stack_b)->current_pos);
	}
}

void	a_cost(t_stack **stack_a, t_stack **stack_b, int size_a)
{
	while ((*stack_a)->current_pos != (*stack_b)->target_pos)
		*stack_a = (*stack_a)->next;
	if ((*stack_a)->current_pos <= size_a / 2)
			(*stack_b)->cost_a += (*stack_a)->current_pos;
	else
		(*stack_b)->cost_a += -1 * (size_a - (*stack_a)->current_pos);
}
