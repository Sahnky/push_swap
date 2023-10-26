/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:43:00 by julberna          #+#    #+#             */
/*   Updated: 2023/10/24 21:07:20 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	verificate(int argc, char **argv, t_stack **stack)
{
	check_elements(argc, &argv, -1, -1);
	create_stack(argv, stack);
	check_duplicate(stack);
	if (check_sort(*stack))
	{
		free_stack(stack);
		exit(SUCCESS);
	}
}

void	check_elements(int argc, char ***argv, int i, int j)
{
	(*argv)++;
	if (argc < 2)
		exit(FAILURE);
	if (ft_strlen(**argv) == 0)
	{
		write(2, "Error\n", 6);
		exit(FAILURE);
	}
	if (argc == 2)
		(*argv) = ft_split((*argv)[0], ' ');
	if (**argv == NULL)
	{
		write(2, "Error\n", 6);
		exit(FAILURE);
	}
	while ((*argv)[++i] != NULL)
	{
		j = -1;
		while ((*argv)[i][++j] != '\0')
			check_error((*argv)[i]);
	}
}

void	check_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !(ft_strchr("+-", str[i]) && \
			ft_isdigit(str[i + 1])))
		{
			write(2, "Error\n", 6);
			exit(FAILURE);
		}
		else if (ft_isdigit(str[i]) && ft_strlen(&str[i]) > 1 && \
				!ft_isdigit(str[i + 1]))
		{
			write(2, "Error\n", 6);
			exit(FAILURE);
		}
		i++;
	}
	if (ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
	{
		write(2, "Error\n", 6);
		exit(FAILURE);
	}
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
				write(2, "Error\n", 6);
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
