/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:38:46 by julberna          #+#    #+#             */
/*   Updated: 2023/10/19 19:45:58 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	
	check_digit(argc, &argv);
	create_stack(argv, &stack_a);
	check_duplicate(stack_a);
	if (check_sort(stack_a))
		return (0);
	add_index(&stack_a);
	lstiter(stack_a, print_stack);
	return (0);
}
