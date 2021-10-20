/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 18:03:34 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/04 21:13:36 by fnicolas         ###   ########.fr       */
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

//imprimir la tabla 'table'con n filas y m columnas
void	write_table(int **table, int n, int m)
{
	int		i; //index para recorrer filas
	int		j; //index para recorrer columnas
	char	c; //auxiliar

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			//c toma el valor en char del int en la posicion que toca
			c = table[i][j] + '0';
			write(1, &c, 1); //se escribe el numero
			if (j < m - 1)
				write(1, " ", 1); // si no es la última columna se mete un espacio
			else
				write(1, "\n", 1); //si es la última columna se mete un enter
			++j;
		}
		++i;
	}
}

//dado la tabla sol y un indice con una posicion, inicializa 'possible_val' poniendo
//0 en los valores no posibles para la posicion index y 1 para los valores sí posibles
void	ini_possible_values(int size, int **sol, int index, int *possible_val)
{
	int	i; 
	int	used_number; 

	//primero inicializamos todos los valores del array a true
	i = 0;
	while (i < size)
	{
		possible_val[i] = 1; 
		++i;
	}
	//recorremos las columnas hacia arriba y ponemos 0 en la posicion de possible_values
	//que encontremos
	i = index / size - 1; //inicializamos la i a la fila -1
	while (i >= 0) //hasta la fila 0
	{
		used_number = sol[i][index % size]; //used_number es el valor de sol en la posicion
		//fila i (va cambiando) y columna index. es decir, un número que se ha usado en esa columna
		
		//le pongo un 0 en el array possible_val al número que está usado
		possible_val[used_number - 1] = 0;
		--i; //recorremos la columna hacia arriba
	}

	//recorremos las filas hacia la izq y ponemos 0 en la posicion de possible_values
	//que encontremos
	i = index % size - 1; //inicializamos la i a la columna -1
	while (i >= 0) //hasta la columna más a la izq
	{
		//used_number es el valor de sol en la posicion fila indice y columna i (va cambiando)
		//es decir, un número que se ha usado en esa fila
		used_number = sol[index / size][i];
		//le pongo un 0 en el array possible_val al número que está usado
		possible_val[used_number - 1] = 0;
		--i; //recorremos la fila hacia la izq
	}
}

//funcion recursiva que asigna valores a ls posicion index de la tabla sol
//index va de 0 a size*size - 1. empieza en 0 y cada nivel de recursion aumenta
//hasta llegar a la última casilla
int	backtracking(int size, int **sol, int index, int **input)
{
	//array que va a guardar todos los valores posibles de sol en la posicion index
	//es decir, los valores que no están colocados ni a su izq ni arriba por el momento 
	int	*possible_values;
	int	i; //indice para recorrer el array possible_values

	//reservamos memoria en possible_values. tantos espacios como size
	possible_values = (int *) malloc (sizeof(int) * size);
	//llamamos a la funcion que inicializa los valores posibles
	ini_possible_values(size, sol, index, possible_values);
	i = 0;
	while (i < size)
	{
		//si el array en la posicion i da true, significa que ese valor se puede asignar
		//a sol en la posicion index, así que se asigna.
		//en caso contrario, se sigue el while
		if (possible_values[i])
		{
			//asigno a sol en la posicion index el valor i + 1
			sol[index / size][index % size] = i + 1;
			//si es la última casilla, compruebo si la tabla solucion
			//está correcta en funcion del input
			if (index == size * size - 1)
			{
				//si la solucion es correcta, se llama a finish_correct_recursion
				//para liberar el espacio de possible_solutions y devolver true
				if (sol_correct(size, sol, input))
					return (finish_correct_recursion(possible_values));
			}
			//si no es la última casilla, la funcion se llama a sí misma
			//sumando 1 al index, y si la llamada a esa funcion devuelve true
			//devolvemos true tambien 
			//si no devuelve true, simplemente seguimos con el while
			else if (backtracking(size, sol, index + 1, input))
				return (finish_correct_recursion(possible_values));
		}
		++i;
	}
	//si ninguna opcion funciona, devuelve 0
	//es decir, no hemos encontrado solucion posible en este nivel
	return (0);
}

//función principal
void	rush01(char *argv)
{
	int	**input; //tabla de input convertido a ints
	int	**sol; //tabla con las soluciones
	int	size; //tamaño de la tabla de soluciones

	size = get_table_size(argv); //llamamos a la funcion que devuelve el tamaño
	if (!size) //si la funcion devuelve 0, sacamos error y acaba la funcion
		write(1, "Error\n", 6);
	else
	{
		//reservamos el espacio en la memoria en funcion de size en las dos tablas
		input = (int **) malloc (sizeof(int *) * 4); //el input siempre tiene 4 filas 
		sol = (int **) malloc (sizeof(int *) * size);
		//reservamos el espacio en la segunda dimension de las tablas
		ini_table(input, 4, size);
		ini_table(sol, size, size);
		//se llama a la funcion que comprueba el formato del input
		//si devuelve un valor distinto de 0, significa que hay error, 
		//así que escribimos error, liberamos el espacio y acabamos la funcion
		if (check_errors_input(size, argv, input))
			write(1, "Error\n", 6);
		//si no hay error en el formato del input, intenta encontrar una solución 
		//correcta en función de dicho input
		else
		{
			//se llama al backtracking y si devuelve un valor distinto de 0
			//significa que ha encontrado una solución, así que se escribe la solución, 
			//se libera la memoria y se acaba la función
			if (backtracking(size, sol, 0, input)) //se llama a la recursión con la casilla 0
				write_table(sol, size, size); //escribe la solucion
			//si no encuentra ninguna solución, saca error, libera la memoria y acaba la función
			else
				write(1, "Error\n", 6);
		}
		//liberar la memoria de input y de sol
		free_table(input, 4);
		free_table(sol, size);
	}
}

//recibe los argumentos desde consola
int	main(int argc, char **argv)
{
	//si el número de argumetnos es dos, llama a rush01
	if (argc == 2)
	{
		++argv;
		rush01(*argv);
	}
	//si no, escribe error y acaba la funcion
	else
		write(1, "Error\n", 6);
	return (0);
}
