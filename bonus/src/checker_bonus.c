/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:04:12 by julberna          #+#    #+#             */
/*   Updated: 2023/10/25 21:14:34 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	t_moves	*moves;
	t_stack	*stack_a;
	// t_stack	*stack_b;

	verificate(argc, argv, &stack_a);
	get_movements(&moves);
	// execute_movements(&stack_a, &stack_b, &moves);
}
