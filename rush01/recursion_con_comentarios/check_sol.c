/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 18:12:27 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/04 21:13:33 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//recibe la columna que hay que comprobar y el expected value
//la comprueba desde arriba y si da el valor esperado, devuelve true
//si no, devuelve false
int	check_up(int size, int **sol, int col, int expected)
{
	int	i; //indice para recorrer la columna 'col'
	int	pov; //lo que se ve desde el up de la columna 
	int	max; //auxiliar para calcular el valor de pov

	pov = 0;
	max = 0; //max se iniciliza a 0 y va tomando los valores del max visto
	i = 0;
	while (i < size) //recorremos la columna de arriba a abajo
	{
		if (max < sol[i][col]) //si max es menor que el valor por el que voy en sol
		{
			//max toma el nuevo valor máximo y sumo 1 a pov
			max = sol[i][col];
			++pov;
		}
		++i;
	}
	//si el pov calculado en funcion de los valores de sol, es distinto a el esperado 
	//que me dice el input, devuelvo false. si no, devuelvo true.
	if (pov != expected)
		return (0);
	return (1);
}

int	check_down(int size, int **sol, int col, int expected)
{
	int	i;
	int	pov;
	int	max;

	pov = 0;
	max = 0;
	i = size - 1; //inicializo la i a la última fila para checkear la columna 
	//de arriba a abajo
	while (i >= 0)
	{
		if (max < sol[i][col])
		{			
			max = sol[i][col];
			++pov;
		}
		--i; 
	}
	if (pov != expected)
		return (0);
	return (1);
}

int	check_left(int size, int **sol, int row, int expected)
{
	int	i;
	int	pov;
	int	max;

	pov = 0;
	max = 0;
	i = 0;
	//de la columna 0 a la size -1 para recorrer la fila hacia la derecha
	while (i < size)
	{
		if (max < sol[row][i]) //la i es la columna
		{			
			max = sol[row][i];
			++pov;
		}
		++i;
	}
	if (pov != expected)
		return (0);
	return (1);
}

int	check_right(int size, int **sol, int row, int expected)
{
	int	i;
	int	pov;
	int	max;

	pov = 0;
	max = 0;
	i = size - 1;
	while (i >= 0)
	{
		if (max < sol[row][i])
		{			
			max = sol[row][i];
			++pov;
		}
		--i;
	}
	if (pov != expected)
		return (0);
	return (1);
}

//se llama desde el backtracking cuando hemos llegado la última casilla, para comprobar
//si la solución es correcta
//devuelve true si la solucion cumple con los requisitos del input
//y false si no los cumple
int	sol_correct(int size, int **sol, int **input)
{
	int	i; //recorre filas
	int	j; //recorre columnas
	int	correct; //booleano auxiliar que guarda si un caso es correcto o no

	//bucle que recorre la tabla entera de input y comprueba cada uno de sus valores
	i = 0;
	while (i < 4) //4 filas
	{
		j = 0;
		while (j < size)
		{
			if (i == 0) //fila 0 son los valores de up
				correct = check_up(size, sol, j, input[i][j]);
			else if (i == 1) //fila 1 son los valores de down
				correct = check_down(size, sol, j, input[i][j]);
			else if (i == 2) //fila 2 son los valores de left
				correct = check_left(size, sol, j, input[i][j]);
			else //fila 3 son los valores de right
				correct = check_right(size, sol, j, input[i][j]);
			if (!correct) //si correct es false, devuelve false para que siga la recursion
				return (0);
			++j;
		}
		++i;
	}
	//cuando nada devuelve false, la solucion entera cumple con los requisitos, 
	//así que devuelvo true para acabar con la recursion
	return (1);
}
