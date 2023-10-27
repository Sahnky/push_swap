/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:04:12 by julberna          #+#    #+#             */
/*   Updated: 2023/10/27 00:53:34 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_moves	*tries;
	t_moves	*moves;

	verify(argc, argv, &stack_a, &stack_b);
	add_index(&stack_a);
	get_movements(&tries, &moves);
	execute(&stack_a, &stack_b, tries, &moves);
	check_sorting(&stack_a, &stack_b);
	conclude(&stack_a, &stack_b, &moves);
	free_moves(&tries);
}
