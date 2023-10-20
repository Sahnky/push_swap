/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:03:07 by julberna          #+#    #+#             */
/*   Updated: 2023/10/19 20:21:33 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(char **values, t_stack **stack_a)
{
	int		i;

	i = -1;
	*stack_a = NULL;
	while (values[++i] != NULL)
		*stack_a = lstnew(stack_a, ft_atoi(values[i]), i);
}

t_stack	*lstnew(t_stack **stack, int value, int pos)
{
	t_stack	*new_node;

	new_node = ft_calloc(1, sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->current_pos = pos;
	new_node->next = NULL;
	if (*stack == NULL)
		*stack = new_node;
	else
		lstlast(*stack)->next = new_node;
	return(*stack);
}

t_stack	*lstlast(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	lstiter(t_stack *stack, void (*f)(t_stack *))
{
	while (stack && f)
	{
		f(stack);
		stack = stack->next;
	}
}

int	lstsize(t_stack *stack)
{
	int	len;

	if (stack == NULL)
		return (0);
	len = 1;
	while (stack->next != NULL)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	print_stack(t_stack *stack)
{
	ft_printf("Element: %d\nValue: %d\n\n", stack->current_pos, stack->value);
}
