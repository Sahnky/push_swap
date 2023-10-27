/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:43:00 by julberna          #+#    #+#             */
/*   Updated: 2023/10/26 21:17:36 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	verificate(int argc, char **argv, t_stack **stack)
{
	check_elements(argc, argv, stack, -1);
	check_duplicate(stack);
	if (check_sort(*stack))
	{
		free_stack(stack);
		exit(SUCCESS);
	}
}

void	check_elements(int argc, char **argv, t_stack **stack, int i)
{
	int		j;
	int		size;
	char	**arguments;

	argv++;
	if (argc < 2)
		exit(FAILURE);
	arguments = NULL;
	if (ft_strlen(*argv) == 0)
		error_handling(arguments, 1, 0);
	if (argc == 2)
		size = copy_single_argv(argv, &arguments);
	else
		size = copy_multi_argv(argc, argv, &arguments);
	if (*arguments == NULL)
		error_handling(arguments, 2, size);
	while (++i < size)
	{
		j = -1;
		while (arguments[i][++j] != '\0')
			if (check_error(arguments[i]))
				error_handling(arguments, 2, size);
	}
	create_stack(arguments, stack);
	error_handling(arguments, 3, size);
}

int	check_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !(ft_strchr("+-", str[i]) && \
			ft_isdigit(str[i + 1])))
			return (1);
		else if (ft_isdigit(str[i]) && ft_strlen(&str[i]) > 1 && \
				!ft_isdigit(str[i + 1]))
			return (1);
		i++;
	}
	if (ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
		return (1);
	return (0);
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
