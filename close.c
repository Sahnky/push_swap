/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:34:59 by julberna          #+#    #+#             */
/*   Updated: 2023/10/21 14:18:01 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	conclude(t_stack **stack)
{
	free_stack(stack);
}

void	free_args(char ***argv)
{
	int	i;

	i = -1;
	while ((*argv)[++i] != NULL)
		free((*argv)[i]);
	free((*argv));
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack);
		(*stack) = (*stack)->next;
		free(temp);
	}
}

int	message(int msg_code)
{
	static char	*message[MSG_MAX] = {
		"No errors, all good! ^-^\n",
		"Error!\nThe list contains non-digit elements."
		" Please, provide a valid list of integers.\n",
		"Error!\nThe list contains values that don't fit an integer."
		" Please, provide a valid list of numbers.\n",
		"Error!\nThe list contains duplicate elements."
		" Please, provide a list of unique integers.\n"
	};

	write(2, message[msg_code], ft_strlen(message[msg_code]));
	return (msg_code);
}
