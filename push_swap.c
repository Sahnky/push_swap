/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:38:46 by julberna          #+#    #+#             */
/*   Updated: 2023/10/20 19:25:40 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	check_digit(argc, &argv);
	create_stack(argv, &stack_a);
	check_duplicate(&argv, &stack_a);
	if (check_sort(stack_a))
		return (SUCCESS);
	add_index(&stack_a);
	lstiter(stack_a, print_stack);
	free_stack(&stack_a);
	free_args(&argv);
	return (SUCCESS);
}

void	print_stack(t_stack *stack)
{
	ft_printf("Value: %d\nPosit: %d\nIndex: %d\n\n", \
	stack->value, stack->current_pos, stack->index);
}
