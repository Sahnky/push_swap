/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:26:37 by julberna          #+#    #+#             */
/*   Updated: 2023/10/27 00:52:16 by julberna         ###   ########.fr       */
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
	else if (size_sa <= 5)
		sort_5(stack_a, stack_b, moves);
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

void	sort_5(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	t_moves	*oneway;
	t_moves	*other;
	t_stack	*dupe_1;
	t_stack	*dupe_2;

	one_way(stack_a, stack_b, &dupe_1, &oneway);
	another(stack_a, stack_b, &dupe_2, &other);
	free_stack(stack_a);
	*stack_a = NULL;
	if (moves_size(oneway) < moves_size(other))
	{
		*moves = oneway;
		*stack_a = dupe_1;
		free_stack(&dupe_2);
		free_moves(&other);
	}
	else
	{
		*moves = other;
		*stack_a = dupe_2;
		free_stack(&dupe_1);
		free_moves(&oneway);
	}
}

void	sort_larger(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	push_to_b(stack_a, stack_b, moves);
	sort_3(stack_a, moves);
	push_to_a(stack_a, stack_b, moves);
}
