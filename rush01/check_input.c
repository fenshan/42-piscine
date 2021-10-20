/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 18:12:19 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/03 18:12:21 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	check_errors_input(int size, char *argv, int **input)
{
	int	i;
	int	j;
	int	aux;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < size)
		{
			aux = i * size + j;
			if (!argv[aux * 2] || argv[aux * 2] < '1'
				|| argv[aux * 2] > size + '0')
				return (1);
			else if (aux != 4 * size - 1 && argv[aux * 2 + 1] != ' ')
				return (1);
			else
				input[i][j] = argv[aux * 2] - '0';
			++j;
		}
		++i;
	}
	if (argv[4 * size * 2 - 1])
		return (1);
	return (0);
}

int	get_table_size(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		++i;
	i = (i + 1) / 2;
	if (i % 4)
		return (0);
	else if (i / 4 > 9 || i / 4 < 4)
		return (0);
	else
		return (i / 4);
}
