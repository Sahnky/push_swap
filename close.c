/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:34:59 by julberna          #+#    #+#             */
/*   Updated: 2023/10/23 21:57:20 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	conclude(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	free_stack(stack_a);
	if (*stack_b)
		free_stack(stack_b);
	free_moves(moves);
}

void	free_args(char ***argv)
{
	int	i;

	i = -1;
	while ((*argv)[++i] != NULL)
		free((*argv)[i]);
	free((*argv));
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack);
		(*stack) = (*stack)->next;
		free(temp);
	}
}

void	free_moves(t_moves **moves)
{
	t_moves	*temp;

	while (*moves)
	{
		temp = (*moves);
		(*moves) = (*moves)->next;
		free(temp);
	}
}
