/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 18:12:19 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/04 21:13:38 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

//devuelve 0 si el input no tiene un formato correcto
//devuelve true si el input es correcto en formato
int	check_errors_input(int size, char *argv, int **input)
{
	int	i; //indice para recorrer filas de la tabla bidimensional
	int	j; //indice para columnas de la tabla bidimensional
	int	aux; 

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < size)
		{
			aux = i * size + j; //posicion en mi array unidimensional
			//si el caracter es nulo (oseea que el input se ha acabado antes de la cuenta)
			//o es un caracter distinto de 1 a size
			//devuelvo 1 (error)
			if (!argv[aux * 2] || argv[aux * 2] < '1'
				|| argv[aux * 2] > size + '0') 
				return (1);
			//si el siguiente caracter, que tiene que ser un espacio, no es un espacio
			//da error. solo si no estamos en el último entero
			else if (aux != 4 * size - 1 && argv[aux * 2 + 1] != ' ')
				return (1);
			//en caso de que nada haya dado error, se asigna a la tabla de enteros
			//el valor del char convertido a int
			else
				input[i][j] = argv[aux * 2] - '0';
			++j;
		}
		++i;
	}
	//si el caracter nulo de final de string
	//no está donde debería estar, devolvemos error
	if (argv[4 * size * 2 - 1])
		return (1);
	//en caso de que nada haya dado error, devuelve 0 (no error)
	return (0);
}

//dado el argumento del main, devuelve el tamaño de la tabla en funcion de lo que 
//mida el argumento. si el tamaño está mal, o es > 9 o < 4, devuelve 0
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
