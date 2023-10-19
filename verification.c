/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:43:00 by julberna          #+#    #+#             */
/*   Updated: 2023/10/19 16:33:26 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_digit(int argc, char ***argv)
{
	int		i;
	int		j;

	(*argv)++;
	if (argc < 2)
		exit(1);
	if (argc == 2)
		(*argv) = ft_split((*argv)[0], ' ');
	i = -1;
	while ((*argv)[++i] != NULL)
	{
		j = 0;
		while ((*argv)[i][++j] != '\0')
		{
			if (!ft_isdigit((*argv)[i][j]) && !(ft_strchr("+-", (*argv)[i][j]) && \
				ft_isdigit((*argv)[i][j + 1])))
			{
				write(2, "Error!\nThe list contains non-digit elements."
					" Please, provide a valid list of integers.\n", 87);
				exit(1);
			}
		}
	}
}

void	check_duplicate(t_stack *stack)
{
	t_stack	*stack_copy;

	while (stack)
	{
		stack_copy = stack->next;
		while (stack_copy) 
		{
			if (stack->value == stack_copy->value)
			{
				write(2, "Error!\nThe list contains duplicate elements."
					" Please, provide a list of unique integers.\n", 88);
				exit(1);
			}
			stack_copy = stack_copy->next;
		}
		stack = stack->next;
	}
}
