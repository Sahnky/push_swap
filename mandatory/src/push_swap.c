/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:38:46 by julberna          #+#    #+#             */
/*   Updated: 2023/10/26 18:29:01 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_moves	*moves;

	verificate(argc, argv, &stack_a);
	add_index(&stack_a);
	sorting(&stack_a, &stack_b, &moves);
	conclude(&stack_a, &stack_b, &moves);
	return (SUCCESS);
}
