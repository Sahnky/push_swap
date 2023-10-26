/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:59:26 by julberna          #+#    #+#             */
/*   Updated: 2023/10/25 23:41:54 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "push_swap.h"

# define FAILURE	-1
# define SUCCESS	0
# define INT_MAX	2147483647
# define INT_MIN	-2147483648

void	get_movements(t_moves **moves);
void	check_sorting(t_stack **stack_a);
void	validate_move(char *move, t_moves **moves);
void	execute_moves(t_stack **stack_a, t_stack **stack_b, t_moves **tries, \
						t_moves **moves);

#endif
