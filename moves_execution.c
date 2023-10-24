/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:17:39 by julberna          #+#    #+#             */
/*   Updated: 2023/10/23 20:11:48 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_cheapest(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	t_stack	*chosen;

	chosen = choose_cheapest(*stack_b);
	if (chosen->cost_a > 0 && chosen->cost_b > 1)
		double_rotation(stack_a, stack_b, moves, chosen);
	else if (chosen->cost_a < 0 && chosen->cost_b < -1)
		double_reverse(stack_a, stack_b, moves, chosen);
	else
		single_rotations(stack_a, stack_b, moves, chosen);
	pa(stack_a, stack_b, moves);
}

void	double_rotation(t_stack **stack_a, t_stack **stack_b, \
						t_moves **moves, t_stack *chosen)
{
	while (chosen->cost_a > 0 && chosen->cost_b > 1)
	{
		rr(stack_a, stack_b, moves);
		chosen->cost_a--;
		chosen->cost_b--;
	}
	while (chosen->cost_a-- > 0)
		ra(stack_a, moves, 1);
	while (chosen->cost_b-- > 1)
		rb(stack_b, moves, 1);
}

void	double_reverse(t_stack **stack_a, t_stack **stack_b, \
						t_moves **moves, t_stack *chosen)
{
	while (chosen->cost_a < 0 && chosen->cost_b < 1)
	{
		rrr(stack_a, stack_b, moves);
		chosen->cost_a++;
		chosen->cost_b++;
	}
	while (chosen->cost_a++ < 0)
		rra(stack_a, moves, 1);
	while (chosen->cost_b++ < 1)
		rrb(stack_b, moves, 1);
}

void	single_rotations(t_stack **stack_a, t_stack **stack_b, \
						t_moves **moves, t_stack *chosen)
{
	if (chosen->cost_a > 0)
	{
		while (chosen->cost_a-- > 0)
			ra(stack_a, moves, 1);
	}
	else
	{
		while (chosen->cost_a++ < 0)
			rra(stack_a, moves, 1);
	}
	if (chosen->cost_b > 1)
	{
		while (chosen->cost_b-- > 1)
			rb(stack_b, moves, 1);
	}
	else if (chosen->cost_b < -1)
	{
		while (chosen->cost_b++ < -1)
			rrb(stack_b, moves, 1);
	}
}
