/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almferna <almferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:01:27 by alvicent          #+#    #+#             */
/*   Updated: 2021/10/03 13:34:05 by almferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include< unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2) 
	{
		argv++;
		rush01(*argv);
	}	
	else
	{
		write(1, "Error",5); 
		write(1,"\n",1);
	}
}

void rush01(char *argv)
{
	// array [5][5]
    char	**matrix; 
	char	**input;

	// malloc guarda memoria para el array
    matrix = malloc(sizeof(char *) * 5);
    int i = 0;
	// iterramos para rellenar las dos matrices
    while (i < 4)
    {
		// guardamos espacio para tener un array dentro de la matriz
        matrix[i] = malloc(sizeof(char) * 5);
        matrix[i] = '\0';
	   	i++;
    }
	i = 0;
	
	intiliazeArray(sol);
	intiliazeArray(input);
	// guardamos el input el argv
	while( argv != '\0')
	{
		if(argv < 48 || argv > 53) // comprobar numeros entre 1 y 4 
		{	
			write(1, "Error", 5);	
			write (1, "\n", 1);
		}
		input[i] = (int) argv;		
		i++;	
		argv = argv + 2;
		if(i > 3 && i<7 || i >=11 && i <16) 
		{
			if (input[i] + input[i-4] > 5) || input [i] + input[i-4] <3) /// las rows falta  y menos de 3 
			{
				write(1, "Error", 5);
				write (1, "\n", 1);
				return;	
			}
		}
	}
	if(i != 16) 
	{
		write(1,"Error", 5);
		return;
	}
}
// iniciliaza arrays
void initializeArray(int **matrix)
{
	matrix = malloc(sizeof(char *) * 5 * 4);

    int i;
	int j;
	i = 0; 

    while (i < 5)
    {
		j = 0;

		while(j < 5) {
        	matrix[i][j] = '\0';
			j++;
		}
        i++;
    }
}

//añadimos o borramos posibilidades
void posibilities(char **matrix, int i, int x , int y, int possibility)
{
	if(matrix[x][y][possibility] == possibility)
	{	
		if(i == 1)
		{
			matrix[x][y][possibility] = '\0'; 
		}	
		else
		{
			return;
		}
	}
	else if(matrix[x][j][possibility] == '\0')
	{
		matrix[x][j][possibility] = possibility;
		}		
		// matrix[x][y][0] hay un 1 o un '\0'   
		// matrix [x][y][1] hay un 2 o un '\0'
		}	
	}
}

void placeNumber(int * matrix, int *sol) 
{
	int i;
   	int j;
	int p; 
	int empty;
	int pos;
	i = 0;
	while (i < 4)
	{
		 j= 0;
		while(j < 4)	   	
		{ 
			empty = 0;
			p = 0;
			while(p > 4)
			{
				if(matrix[i][j][p] != '\0')
				{
					empty++;
					pos = p;
				}	
			}
			if(empty = 1)
			{
				sol[x][y] = pos;
			}
		j++;	
		}
	i++;
	}
}  /////                           filas coumnas
void checkInput(int *input, int p, int i , int j)
{
	//7 si es un 3 no se puedo colocar el 3 n el  0
	if()

}


void checkPosibilities (int * matrix, int *input, int *sol){
    int i;
    int j;
	int p;
	i = 0;
	j = 0;
    while(i < 4)
	{
        j = 0;
        while(j < 4)
		{
             p = 0;
            while(p < 4)
			{
				if(sol[i][j] != '\0')
				{
					if(matrix[i][j][p] == '\0') // si no hay posibilidad de numero p pero si8 se puedo colocar añadir al numero de posibilidades
					{
						if (checkcol(matrix[i][j][p], i, j, sol) == checkRow(matrix[i][j][p], i, j, sol) == 0) && checkInput(input, matrix[i][j][p],i, j))
				   			matrix[i][j][p] = p;
					}
					p++;
				}
			}
			j++;
	}
	i++;
}

int checkcol(int pos , int x, int y, int *sol) { // returnea 0 si no encuentra el numero que buscamos en las columnas

	while(x < 4){
		if ((sol[x][y]) == pos) {
			return -1;
			
		x++;
		}
	return 0;
}
int checkRow(int pos, int x, int y, int *sol ) {

	while(y < 4){
		if ((sol[x][y]) == pos) 
		return -1;
			
		y++;
	}
	return 0;
}
// algoritmo base

void first(int i)
{
	// si e de columnas
	// base case encontrar el cuatro
		if(input[i] = 4) 
		{
			if(i <= 3){ // esta en la primera fila( col0up, col1up...col3up)
				sol[0][i] = 1; // -> al resto de la fila el 1
				sol[1][i] = 2;
				sol[2][i] = 3;
				sol[3][i] = 4; 
			}
			else if(4 <= i <= 7){ // esta en la ultima fil( col1down, col 2down...)
				sol[0][i] = 4; // -> al resto de la fila el 1
				sol[1][i] = 3;
				sol[2][i] = 2;
				sol[3][i] = 1; 
			}
			else if(7 > i >= 11){ // estamos en la columnas ( row1left, row2left...)
				sol[i][0] = 1; // -> al resto de la fila el 1
				sol[i][1] = 2;
				sol[i][2] = 3;
				sol[i][3] = 4; 
		else
		{
				sol[i][3] = 1; // -> al resto de la fila el 1
				sol[i][2] = 2;
				sol[i][1] = 3;
				sol[i][0] = 4;
		}
	}
			else{ // si suma 5 se puede colocar el 4 a n posiciones ex  3 __ 4_  2
				// si tienes un 1 por narices va un 4  1 4 ___ 3
			// si tiens un 2___2 no puedes poner el 3 en la segunda casilla

				i = 4;
				while(i < 16) 
				{
					if(input[i] + input[i-4] == 5){
                    
                            if(4 <= i <= 7){ // esta en la ultima fil( col1down, col 2down...)
                              // esto es si hay
                                sol[input[i] -1][input[i-4]-1] = 4;
                                if(input[i] == 1){
                                    sol[3][input[i]-1] = 4;
                                }else if (input[i -4] == 1)
                                {
    
                                    sol[0][input[i-4]-1] = 4;
                                }
                            }
                            else if(11 > i >16){ // estamos en la columnas ( row1left, row2left...)
                                {
                                    sol[input[i -4] -1][input[i]-1] =4;
                                    if(input[i] == 1) {
                                        sol[input[i] -1][3] = 4; // dudoso
                                }
                                    else if (input [i-4] ==1)
                                    {
                                        sol[input[i-4] -1][0] = 4;
                                    }
                                }
							}
    		                i++;
	
						
					}
      
				}
			}
		
    return false

}

