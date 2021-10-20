/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:21:49 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/06 22:20:29 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_table(int *a)
{
	char	aux;
	int		i;

	i = -1;
	while (++i < 10)
	{
		aux = a[i] + '0';
		write(1, &aux, 1);
	}
	write(1, "\n", 1);
}

int	check_queen(int *a, int i)
{
	int	j;
	int	epsilon;

	j = i - 1;
	epsilon = 1;
	while (j >= 0)
	{
		if (a[j] == a[i])
			return (0);
		if (a[j] == a[i] - epsilon || a[j] == a[i] + epsilon)
			return (0);
		--j;
		++epsilon;
	}
	return (1);
}

int	recursion(int *a, int index)
{
	int	j;
	int	cont;

	if (index == 10)
	{
		print_table(a);
		return (1);
	}
	cont = 0;
	j = 0;
	while (j < 10)
	{
		a[index] = j;
		if (check_queen(a, index))
			cont += recursion(a, index + 1);
		++j;
	}
	return (cont);
}

int	ft_ten_queens_puzzle(void)
{
	int	a[10];

	return (recursion (a, 0));
}
