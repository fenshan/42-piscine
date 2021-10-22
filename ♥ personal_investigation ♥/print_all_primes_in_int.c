/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all_primes_in_int.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:09:51 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/22 ‏‎12:56:25 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

const int MAX_INT = 2147483647; //169;
const int SQRT_MAX_INT = 46340; //13
//const int N_PRIMES = 105097565;
const int N_PRIMES_SQRT = 4792; //6

/* Program that creates a file with all the prime numbers up to max_int (105097565 primes and 1.1 GB aprox)
/* I tried to optimize it by storing all the primes up to sqrt(max_int) in an array
/* The algorithm complexity is O(n * primes_in(sqrt(n))) and it takes 10 mins approx, which I think is quite okay
/* If you are able to optimize it, please let me know!!!
*/
int main()
{
    int primes[N_PRIMES_SQRT];
    int current_n_of_primes = 0;

    //open the file
    char filename[] = "primes";
    FILE* fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error opening the file %s", filename);
        return (-1);
    }
   
    //primes
    int n = 1;
    while (n++ < MAX_INT)
    {
        int is_prime = 1;
        int i = 0;
        while (is_prime && i < current_n_of_primes && primes[i] * primes[i] <= n)
        {
            if (!(n % primes[i]))
                is_prime = 0;
            ++i;
        }
        if (is_prime)
        {
            fprintf(fp, "%d\n", n);
            if (current_n_of_primes < N_PRIMES_SQRT)
                primes[current_n_of_primes++] = n;
        }
    }

    //close the file
    fclose(fp);

    return (0);
}