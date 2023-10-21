/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:10:48 by julberna          #+#    #+#             */
/*   Updated: 2023/10/21 14:10:02 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	populate(t_stack **stack)
{
	add_index(stack);
	lstiter(*stack, print_stack);
}

void	add_index(t_stack **stack)
{
	int			i;
	t_stack		*dupe;
	t_stack		*temp;
	const int	control = (*stack)->value;

	i = 0;
	dupe = duplicate(*stack);
	temp = dupe;
	sort(&dupe);
	lstlast(*stack)->next = *stack;
	while (dupe)
	{
		if (dupe->value == (*stack)->value)
		{
			(*stack)->index = i++;
			dupe = dupe->next;
		}
		(*stack) = (*stack)->next;
	}
	free_stack(&temp);
	while ((*stack)->next->value != control)
		(*stack) = (*stack)->next;
	temp = (*stack)->next;
	(*stack)->next = NULL;
	(*stack) = temp;
}

t_stack	*duplicate(t_stack *stack)
{
	t_stack	*dupe;

	if (stack == NULL)
		return (NULL);
	dupe = ft_calloc(1, sizeof(t_stack));
	dupe->value = stack->value;
	dupe->current_pos = stack->current_pos;
	dupe->next = duplicate(stack->next);
	return (dupe);
}
