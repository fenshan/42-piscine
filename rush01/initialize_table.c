/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 22:37:44 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/03 22:37:46 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ini_table(int **table, int n, int m)
{
	int	i;

	i = 0;
	while (i < n)
	{
		table[i] = (int *) malloc (sizeof(int) * m);
		++i;
	}
}

void	free_table(int **table, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(table[i]);
		++i;
	}
	free(table);
}

int	finish_correct_recursion(int *table)
{
	free(table);
	return (1);
}
