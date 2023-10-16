/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:43:00 by julberna          #+#    #+#             */
/*   Updated: 2023/10/15 22:57:33 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	verification(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
		exit(1);
	i = 0;
	while (argv[++i] != NULL)
	{
		j = -1;
		while (argv[i][++j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
			{
				write(2, "Error!\nThe list contains non-digit elements."
					" Please, provide a valid list of integers.\n", 87);
				exit(1);
			}
		}
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
		{
			write(2, "Error!\nSome argument is bigger/smaller than an integer."
				" Please, check the list and run the program again.\n", 106);
		}
	}
}
