/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:46:44 by julberna          #+#    #+#             */
/*   Updated: 2023/10/20 16:11:12 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **stack)
{
	t_stack	*head;
	t_stack	*left;
	t_stack	*right;

	head = *stack;
	if ((head == NULL) || (head->next == NULL))
		return ;
	stack_split(*stack, &left, &right);
	sort(&left);
	sort(&right);
	*stack = merge(left, right);
}

void	stack_split(t_stack *stack, t_stack **right, t_stack **left)
{
	t_stack	*tortoise;
	t_stack	*hare;

	tortoise = stack;
	hare = stack->next;
	while (hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;
	}
	*left = stack;
	*right = tortoise->next;
	tortoise->next = NULL;
}

t_stack	*merge(t_stack *left, t_stack *right)
{
	t_stack	*sorted;

	sorted = NULL;
	if (left == NULL)
		return (right);
	else if (right == NULL)
		return (left);
	if (left->value <= right->value)
	{
		sorted = left;
		sorted->next = merge(left->next, right);
	}
	else
	{
		sorted = right;
		sorted->next = merge(left, right->next);
	}
	return (sorted);
}
