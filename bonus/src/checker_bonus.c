/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:04:12 by julberna          #+#    #+#             */
/*   Updated: 2023/10/25 23:45:38 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	print_stack(t_stack *stack)
{
	ft_printf("Value: %d\nPosit: %d\nIndex: %d\n\n", \
	stack->value, stack->current_pos, stack->index);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_moves	*tries;
	t_moves	*moves;

	verificate(argc, argv, &stack_a);
	populate(&stack_a);
	get_movements(&tries);
	execute_moves(&stack_a, &stack_b, &tries, &moves);
	check_sorting(&stack_a);
	conclude(&stack_a, &stack_b, &moves);
	free_moves(&tries);
}
