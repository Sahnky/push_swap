/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:02:46 by julberna          #+#    #+#             */
/*   Updated: 2023/10/27 00:50:33 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	verify(int argc, char **argv, t_stack **stack_a, t_stack **stack_b)
{
	*stack_b = NULL;
	check_elements(argc, argv, stack_a, -1);
	check_duplicate(stack_a);
}

void	get_movements(t_moves **tries, t_moves **moves)
{
	char	*move;

	*tries = NULL;
	*moves = NULL;
	while (42)
	{
		move = get_next_line(0);
		if (move && ft_strlen(move) > 0)
			validate_move(move, tries);
		else
			break ;
		free(move);
	}
}

void	validate_move(char *move, t_moves **tries)
{
	int			i;
	int			size;
	const char	*valid_moves[OP_MAX] = {
		"sa", "sb", "ra", "rb", "rr", "rra", "rrb", "pa", "pb", "rrr", "ss"
	};

	i = 0;
	while (i < OP_MAX)
	{
		size = ft_strlen(move) - 1;
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

void	execute(t_stack **a, t_stack **b, t_moves *tries, t_moves **moves)
{
	while (tries)
	{
		if (tries->move == SA)
			sa(a, moves);
		else if (tries->move == SB)
			sb(b, moves);
		else if (tries->move == RA)
			ra(a, moves, 1);
		else if (tries->move == RB)
			rb(b, moves, 1);
		else if (tries->move == RR)
			rr(a, b, moves);
		else if (tries->move == RRA)
			rra(a, moves, 1);
		else if (tries->move == RRB)
			rrb(b, moves, 1);
		else if (tries->move == PA)
			pa(a, b, moves);
		else if (tries->move == PB)
			pb(a, b, moves);
		else if (tries->move == RRR)
			rrr(a, b, moves);
		tries = tries->next;
	}
}

void	check_sorting(t_stack **stack_a, t_stack **stack_b)
{
	if (check_sort(*stack_a) && lstsize(*stack_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
