/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:10:48 by julberna          #+#    #+#             */
/*   Updated: 2023/10/20 17:35:11 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_index(t_stack **stack)
{
	int		i;
	int		control;
	t_stack	*dupe;
	t_stack	*temp;

	i = 0;
	dupe = duplicate(*stack);
	sort(&dupe);
	control = (*stack)->value;
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
	while ((*stack)->next->value != control)
		(*stack) = (*stack)->next;
	temp = (*stack)->next;
	(*stack)->next = NULL;
	(*stack) = temp;
	free_stack(&dupe);
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

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while ((*stack))
	{
		temp = (*stack);
		(*stack) = (*stack)->next;
		free(temp);
	}
}
