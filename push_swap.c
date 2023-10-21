/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:38:46 by julberna          #+#    #+#             */
/*   Updated: 2023/10/21 14:18:10 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	verificate(argc, argv, &stack_a);
	populate(&stack_a);
	conclude(&stack_a);
	return (SUCCESS);
}

void	print_stack(t_stack *stack)
{
	ft_printf("Value: %d\nPosit: %d\nIndex: %d\n\n", \
	stack->value, stack->current_pos, stack->index);
}
