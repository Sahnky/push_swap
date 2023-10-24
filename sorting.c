/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:26:37 by julberna          #+#    #+#             */
/*   Updated: 2023/10/23 20:18:44 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	int	size_sa;

	*moves = NULL;
	*stack_b = NULL;
	size_sa = lstsize(*stack_a);
	if (size_sa == 2)
		sa(stack_a, moves);
	else if (size_sa == 3)
		sort_3(stack_a, moves);
	else
		sort_larger(stack_a, stack_b, moves);
	if (!check_sort(*stack_a))
		rotate_sort(stack_a, moves);
	print_moves(*moves);
}

void	sort_3(t_stack **stack_a, t_moves **moves)
{
	if (check_sort(*stack_a))
		return ;
	else if ((*stack_a)->index > (*stack_a)->next->index && \
			(*stack_a)->index > (*stack_a)->next->next->index)
		ra(stack_a, moves, 1);
	else if ((*stack_a)->next->index > (*stack_a)->index && \
			(*stack_a)->next->index > (*stack_a)->next->next->index)
		rra(stack_a, moves, 1);
	else
		sa(stack_a, moves);
	sort_3(stack_a, moves);
}

void	sort_larger(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	push_to_b(stack_a, stack_b, moves);
	sort_3(stack_a, moves);
	push_to_a(stack_a, stack_b, moves);
}

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
