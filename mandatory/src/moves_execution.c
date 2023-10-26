/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:17:39 by julberna          #+#    #+#             */
/*   Updated: 2023/10/24 18:30:08 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_cheapest(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	t_stack	*chosen;

	chosen = choose_cheapest(*stack_b);
	if (chosen->cost_a > 0 && chosen->cost_b > 1)
		dual_rx(stack_a, stack_b, moves, chosen);
	else if (chosen->cost_a < 0 && chosen->cost_b < -1)
		dual_rrx(stack_a, stack_b, moves, chosen);
	else
		sole_rx(stack_a, stack_b, moves, chosen);
	pa(stack_a, stack_b, moves);
}

void	dual_rx(t_stack **a, t_stack **b, t_moves **move, t_stack *chosen)
{
	while (chosen->cost_a > 0 && chosen->cost_b > 1)
	{
		rr(a, b, move);
		chosen->cost_a--;
		chosen->cost_b--;
	}
	while (chosen->cost_a-- > 0)
		ra(a, move, 1);
	while (chosen->cost_b-- > 1)
		rb(b, move, 1);
}

void	dual_rrx(t_stack **a, t_stack **b, t_moves **move, t_stack *chosen)
{
	while (chosen->cost_a < 0 && chosen->cost_b < -1)
	{
		rrr(a, b, move);
		chosen->cost_a++;
		chosen->cost_b++;
	}
	while (chosen->cost_a++ < 0)
		rra(a, move, 1);
	while (chosen->cost_b++ < -1)
		rrb(b, move, 1);
}

void	sole_rx(t_stack **a, t_stack **b, t_moves **move, t_stack *chosen)
{
	if (chosen->cost_a > 0)
	{
		while (chosen->cost_a-- > 0)
			ra(a, move, 1);
	}
	else
	{
		while (chosen->cost_a++ < 0)
			rra(a, move, 1);
	}
	if (chosen->cost_b > 1)
	{
		while (chosen->cost_b-- > 1)
			rb(b, move, 1);
	}
	else if (chosen->cost_b < -1)
	{
		while (chosen->cost_b++ < -1)
			rrb(b, move, 1);
	}
}
