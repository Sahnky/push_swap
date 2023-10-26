/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:40:19 by julberna          #+#    #+#             */
/*   Updated: 2023/10/21 18:40:56 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_move(t_moves **moves, int move)
{
	t_moves	*new_node;

	new_node = ft_calloc(1, sizeof(t_moves));
	if (new_node == NULL)
		return ;
	new_node->move = move;
	new_node->next = NULL;
	if (*moves == NULL)
		*moves = new_node;
	else
		moves_last(*moves)->next = new_node;
}

t_moves	*moves_last(t_moves *moves)
{
	if (moves == NULL)
		return (NULL);
	while (moves->next != NULL)
		moves = moves->next;
	return (moves);
}

void	print_moves(t_moves *moves)
{
	while (moves)
	{
		moves_message(moves->move);
		moves = moves->next;
	}
}

void	moves_message(int msg_code)
{
	static char	*message[OP_MAX] = {
		"pa\n",
		"pb\n",
		"sa\n",
		"sb\n",
		"ss\n",
		"ra\n",
		"rb\n",
		"rr\n",
		"rra\n",
		"rrb\n",
		"rrr\n"
	};

	write(1, message[msg_code], ft_strlen(message[msg_code]));
}
