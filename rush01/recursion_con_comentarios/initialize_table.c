/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 22:37:44 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/04 20:59:31 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//recibe una tabla, un número de filas n y un número de columnas m
//y reserva el espacio deseado con malloc
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

//libera la memoria de una tabla 'table' con número de filas n
void	free_table(int **table, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(table[i]); //libera la memoria de cada fila
		++i;
	}
	free(table); //libera la memoria del puntero inicial
}

//acaba la recursión, liberando el espacio de la tabla de valores y devolviendo true
int	finish_correct_recursion(int *table)
{
	free(table);
	return (1);
}
