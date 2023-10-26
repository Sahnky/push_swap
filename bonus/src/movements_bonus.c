/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:02:46 by julberna          #+#    #+#             */
/*   Updated: 2023/10/25 20:35:28 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	get_movements(t_moves **moves)
{
	char	*move;

	*moves = NULL;
	while (42)
	{
		move = get_next_line(0);
		if (move)
			validate_move(move, moves);
		else
			break ;
	}
}

void	validate_move(char *move, t_moves **moves)
{
	int			i;
	int			size;
	const char	*valid_moves[OP_MAX] = {
		"pa", "pb", "sa", "sb", "ss", "ra", "rb", "rr", "rra", "rrb", "rrr"
	};

	i = 0;
	size = ft_strlen(move) - 1;
	if (size == 0)
		return ;
	while (i < OP_MAX)
	{
		if (!ft_strncmp(valid_moves[i], move, size))
		{
			new_move(moves, i);
			return ;
		}
		i++;
	}
	write(2, "Error\n", 6);
	exit(FAILURE);
}
