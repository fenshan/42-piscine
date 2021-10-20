/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 18:03:34 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/03 18:03:37 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		check_up(int size, int **sol, int col, int expected);
int		check_down(int size, int **sol, int col, int expected);
int		check_left(int size, int **sol, int row, int expected);
int		check_right(int size, int **sol, int row, int expected);
int		sol_correct(int size, int **sol, int **input);
int		check_errors_input(int size, char *argv, int **input);
void	ini_table(int **table, int n, int m);
int		free_table(int **table, int n);
int		finish_correct_recursion(int *table);
int		get_table_size(char *argv);

void	write_table(int **table, int n, int m)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			c = table[i][j] + '0';
			write(1, &c, 1);
			if (j < m - 1)
				write(1, " ", 1);
			else
				write(1, "\n", 1);
			++j;
		}
		++i;
	}
}

void	ini_possible_values(int size, int **sol, int index, int *possible_val)
{
	int	i;
	int	used_number;

	i = 0;
	while (i < size)
	{
		possible_val[i] = 1;
		++i;
	}
	i = index / size - 1;
	while (i >= 0)
	{
		used_number = sol[i][index % size];
		possible_val[used_number - 1] = 0;
		--i;
	}
	i = index % size - 1;
	while (i >= 0)
	{
		used_number = sol[index / size][i];
		possible_val[used_number - 1] = 0;
		--i;
	}
}

int	backtracking(int size, int **sol, int index, int **input)
{
	int	*possible_values;
	int	i;

	possible_values = (int *) malloc (sizeof(int) * size);
	ini_possible_values(size, sol, index, possible_values);
	i = 0;
	while (i < size)
	{
		if (possible_values[i])
		{
			sol[index / size][index % size] = i + 1;
			if (index == size * size - 1)
			{
				if (sol_correct(size, sol, input))
					return (finish_correct_recursion(possible_values));
			}
			else if (backtracking(size, sol, index + 1, input))
				return (finish_correct_recursion(possible_values));
		}
		++i;
	}
	return (0);
}

void	rush01(char *argv)
{
	int	**input;
	int	**sol;
	int	size;

	size = get_table_size(argv);
	if (!size)
		write(1, "Error\n", 6);
	else
	{
		input = (int **) malloc (sizeof(int *) * 4);
		sol = (int **) malloc (sizeof(int *) * size);
		ini_table(input, 4, size);
		ini_table(sol, size, size);
		if (check_errors_input(size, argv, input))
			write(1, "Error\n", 6);
		else
		{
			if (backtracking(size, sol, 0, input))
				write_table(sol, size, size);
			else
				write(1, "Error\n", 6);
		}
		free_table(input, 4);
		free_table(sol, size);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		++argv;
		rush01(*argv);
	}	
	else
		write(1, "Error\n", 6);
	return (0);
}
