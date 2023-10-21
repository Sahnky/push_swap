/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:43:00 by julberna          #+#    #+#             */
/*   Updated: 2023/10/21 13:45:45 by julberna         ###   ########.fr       */
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
		j = -1;
		while ((*argv)[i][++j] != '\0')
			check_error((*argv)[i]);
	}
}

void	check_error(char *str)
{
	if (!ft_isdigit(*str) && !(ft_strchr("+-", *str) && ft_isdigit(*(str + 1))))
		message(NON_DIGIT);
	else if (ft_atoi(str) > INT_MAX || ft_atoi(str) < INT_MIN)
		message(OUT_LIMIT);
	else
		return ;
	exit(FAILURE);
}

void	check_duplicate(t_stack **stack)
{
	t_stack	*stack_copy;
	t_stack	*temp;

	temp = *stack;
	while (*stack)
	{
		stack_copy = (*stack)->next;
		while (stack_copy)
		{
			if ((*stack)->value == stack_copy->value)
			{
				message(REPEAT);
				free_stack(&temp);
				exit(FAILURE);
			}
			stack_copy = stack_copy->next;
		}
		*stack = (*stack)->next;
	}
	*stack = temp;
}

int	check_sort(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
