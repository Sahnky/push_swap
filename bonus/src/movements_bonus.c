/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:02:46 by julberna          #+#    #+#             */
/*   Updated: 2023/10/26 00:11:16 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	get_movements(t_moves **tries)
{
	char	*move;

	*tries = NULL;
	while (42)
	{
		move = get_next_line(0);
		if (move)
			validate_move(move, tries);
		else
			break ;
	}
}

void	validate_move(char *move, t_moves **tries)
{
	int			i;
	int			size;
	const char	*valid_moves[OP_MAX] = {
		"sa", "sb", "ra", "rb", "rra", "rrb", "pa", "pb", "rr", "rrr", "ss"
	};

	i = 0;
	size = ft_strlen(move) - 1;
	if (size == 0)
		return ;
	while (i < OP_MAX)
	{
		if (!ft_strncmp(valid_moves[i], move, size))
		{
			new_move(tries, i);
			return ;
		}
		i++;
	}
	write(2, "Error\n", 6);
	exit(FAILURE);
}

void	execute_moves(t_stack **stack_a, t_stack **stack_b, t_moves **tries, \
						t_moves **moves)
{
	*moves = NULL;
	while (*tries)
	{
		if ((*tries)->move == SA)
			sa(stack_a, moves);
		else if ((*tries)->move == SB)
			sb(stack_b, moves);
		else if ((*tries)->move == RA)
			ra(stack_a, moves, 1);
		else if ((*tries)->move == RB)
			rb(stack_b, moves, 1);
		else if ((*tries)->move == RRA)
			rra(stack_a, moves, 1);
		else if ((*tries)->move == RRB)
			rrb(stack_b, moves, 1);
		else if ((*tries)->move == PA)
			pa(stack_a, stack_b, moves);
		else if ((*tries)->move == PB)
			pb(stack_a, stack_b, moves);
		else if ((*tries)->move == RR)
			rr(stack_a, stack_b, moves);
		else if ((*tries)->move == RRR)
			rrr(stack_a, stack_b, moves);
		*tries = (*tries)->next;
	}
}

void	check_sorting(t_stack **stack_a)
{
	if (check_sort(*stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
