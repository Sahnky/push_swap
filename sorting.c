/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:26:37 by julberna          #+#    #+#             */
/*   Updated: 2023/10/21 21:37:45 by julberna         ###   ########.fr       */
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
		sort_2(stack_a, moves);
	else if (size_sa == 3)
		sort_3(stack_a, moves);
	else
		sort_larger(stack_a, stack_b, moves);
	print_moves(*moves);
}

void	sort_2(t_stack **stack_a, t_moves **moves)
{
	sa(stack_a, moves);
}

void	sort_3(t_stack **stack_a, t_moves **moves)
{
	if (check_sort(*stack_a))
		return ;
	else if ((*stack_a)->index == 2)
		ra(stack_a, moves);
	else if ((*stack_a)->next->index == 2)
		rra(stack_a, moves);
	else
		sa(stack_a, moves);
	sort_3(stack_a, moves);
}

void	sort_larger(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	sa(stack_a, moves);
	sb(stack_b, moves);
}
