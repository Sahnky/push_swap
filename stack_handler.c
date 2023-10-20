/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:03:07 by julberna          #+#    #+#             */
/*   Updated: 2023/10/20 15:29:52 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(char **values, t_stack **stack_a)
{
	int		i;

	i = -1;
	*stack_a = NULL;
	while (values[++i] != NULL)
		lstnew(stack_a, ft_atoi(values[i]), i);
}

void	lstnew(t_stack **stack, int value, int pos)
{
	t_stack	*new_node;

	new_node = ft_calloc(1, sizeof(t_stack));
	if (new_node == NULL)
		return ;
	new_node->value = value;
	new_node->current_pos = pos;
	new_node->next = NULL;
	if (*stack == NULL)
		*stack = new_node;
	else
		lstlast(*stack)->next = new_node;
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
