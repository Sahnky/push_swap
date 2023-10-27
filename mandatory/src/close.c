/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:34:59 by julberna          #+#    #+#             */
/*   Updated: 2023/10/26 20:42:27 by julberna         ###   ########.fr       */
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

void	error_handling(char **arguments, int flag, int size)
{
	int	i;

	i = 0;
	if (flag == 2 || flag == 3)
	{
		while (i <= size)
		{
			free(arguments[i]);
			i++;
		}
		free(arguments);
	}
	if (flag == 1 || flag == 2)
	{
		write(2, "Error\n", 6);
		exit (FAILURE);
	}
}
