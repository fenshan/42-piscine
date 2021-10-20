//by fnicolas
#include <stdio.h>

const int MAX_INT = 2147483647; //169;
const int SQRT_MAX_INT = 46340; //13
//const int N_PRIMES = 105097565;
const int N_PRIMES_SQRT = 4792; //6

int main()
{
    int primes[N_PRIMES_SQRT];
    int curret_n_of_primes = 0;

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
        while (is_prime && i < curret_n_of_primes && primes[i] * primes[i] <= n)
        {
            if (!(n % primes[i]))
                is_prime = 0;
            ++i;
        }
        if (is_prime)
        {
            fprintf(fp, "%d\n", n);
            if (curret_n_of_primes < N_PRIMES_SQRT)
                primes[curret_n_of_primes++] = n;
        }
    }

    //close the file
    fclose(fp);

    return (0);
}