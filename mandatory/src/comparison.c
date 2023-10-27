/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:58:07 by julberna          #+#    #+#             */
/*   Updated: 2023/10/27 00:53:09 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	one_way(t_stack **a, t_stack **b, t_stack **dupe_1, t_moves	**one_way)
{
	*one_way = NULL;
	duplicate(*a, dupe_1);
	add_index(dupe_1);
	while (lstsize(*dupe_1) > 3)
		pb(dupe_1, b, one_way);
	sort_3(dupe_1, one_way);
	push_to_a(dupe_1, b, one_way);
}

void	another(t_stack **a, t_stack **b, t_stack **dupe_2,	t_moves	**another)
{
	*another = NULL;
	duplicate(*a, dupe_2);
	add_index(dupe_2);
	if (lstsize(*dupe_2) > 3)
		push_larger(dupe_2, b, another);
	if (lstsize(*dupe_2) > 3)
		push_smaller(dupe_2, b, another);
	sort_3(dupe_2, another);
	push_to_a(dupe_2, b, another);
}
