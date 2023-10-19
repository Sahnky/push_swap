/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:43:00 by julberna          #+#    #+#             */
/*   Updated: 2023/10/18 20:05:04 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*verification(int argc, char **argv)
{
	int		i;
	int		j;

	if (argc < 2)
		exit(1);
	if (argc == 2)
		argv = ft_split(argv[0], ' ');
	i = 0;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]) && !(ft_strchr("+-", argv[i][j]) && \
				ft_isdigit(argv[i][j + 1])))
			{
				write(2, "Error!\nThe list contains non-digit elements."
					" Please, provide a valid list of integers.\n", 87);
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (create_stack(argv));
}
