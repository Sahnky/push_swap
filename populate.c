/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:10:48 by julberna          #+#    #+#             */
/*   Updated: 2023/10/22 15:41:20 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	populate(t_stack **stack)
{
	add_index(stack);
}

void	create_stack(char **values, t_stack **stack_a)
{
	int		i;

	i = -1;
	*stack_a = NULL;
	while (values[++i] != NULL)
		new_stack(stack_a, ft_atoi(values[i]), i);
}

void	add_index(t_stack **stack)
{
	int			i;
	t_stack		*temp;
	t_stack		*dupe;
	const int	control = (*stack)->value;

	i = 0;
	duplicate(*stack, &dupe);
	sort(&dupe);
	temp = dupe;
	stack_last(*stack)->next = *stack;
	while (dupe)
	{
		if (dupe->value == (*stack)->value)
		{
			(*stack)->index = i++;
			dupe = dupe->next;
		}
		(*stack) = (*stack)->next;
	}
	while ((*stack)->next->value != control)
		(*stack) = (*stack)->next;
	free_stack(&temp);
	temp = (*stack)->next;
	(*stack)->next = NULL;
	(*stack) = temp;
}

void	duplicate(t_stack *stack, t_stack **dupe)
{
	*dupe = NULL;
	while (stack)
	{
		new_stack(dupe, stack->value, stack->current_pos);
		stack = stack->next;
	}
}

void	print_stack(t_stack *stack)
{
	ft_printf("Value: %d\nPosit: %d\nIndex: %d\n\n", \
	stack->value, stack->current_pos, stack->index);
}
