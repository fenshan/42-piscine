/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:22:00 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/06 23:25:12 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb);
int	ft_recursive_factorial(int nb);
int	ft_iterative_power(int nb, int power);
int	ft_recursive_power(int nb, int power);
int	ft_fibonacci(int index);
int	ft_sqrt(int nb);
int	ft_is_prime(int nb);
int	ft_find_next_prime(int nb);
int	ft_ten_queens_puzzle(void);

int	main(void)
{
	printf("ft_iterative_factorial\n");
	printf("%d\n", ft_iterative_factorial(0));
	printf("%d\n", ft_iterative_factorial(1));
	printf("%d\n", ft_iterative_factorial(2));
	printf("%d\n", ft_iterative_factorial(12));
	printf("%d\n", ft_iterative_factorial(-3));

	printf("\n");

	printf("ft_recursive_factorial\n");
	printf("%d\n", ft_recursive_factorial(0));
	printf("%d\n", ft_recursive_factorial(1));
	printf("%d\n", ft_recursive_factorial(2));
	printf("%d\n", ft_recursive_factorial(12));
	printf("%d\n", ft_recursive_factorial(-3));

	printf("\n");

	printf("ft_iterative_power\n");
	printf("%d\n", ft_iterative_power(0, 0));
	printf("%d\n", ft_iterative_power(10, 0));
	printf("%d\n", ft_iterative_power(0, -1));
	printf("%d\n", ft_iterative_power(10, -1));
	printf("%d\n", ft_iterative_power(2, 3));
	printf("%d\n", ft_iterative_power(2, 16));
	printf("%d\n", ft_iterative_power(5, 5));
	printf("%d\n", ft_iterative_power(-2, 3));
	printf("%d\n", ft_iterative_power(-2, 16));
	printf("%d\n", ft_iterative_power(-5, 5));

	printf("\n");

	printf("ft_recursive_power\n");
	printf("%d\n", ft_recursive_power(0, 0));
	printf("%d\n", ft_recursive_power(10, 0));
	printf("%d\n", ft_recursive_power(0, -1));
	printf("%d\n", ft_recursive_power(10, -1));
	printf("%d\n", ft_recursive_power(2, 3));
	printf("%d\n", ft_recursive_power(2, 16));
	printf("%d\n", ft_recursive_power(5, 5));
	printf("%d\n", ft_recursive_power(-2, 3));
	printf("%d\n", ft_recursive_power(-2, 16));
	printf("%d\n", ft_recursive_power(-5, 5));

	printf("\n");

	printf("ft_fibonacci\n");
	printf("%d\n", ft_fibonacci(-1));
	printf("%d\n", ft_fibonacci(0));
	printf("%d\n", ft_fibonacci(1));
	printf("%d\n", ft_fibonacci(2));
	printf("%d\n", ft_fibonacci(3));
	printf("%d\n", ft_fibonacci(4));
	printf("%d\n", ft_fibonacci(5));
	printf("%d\n", ft_fibonacci(6));
	printf("%d\n", ft_fibonacci(7));
	printf("%d\n", ft_fibonacci(8));
	printf("%d\n", ft_fibonacci(9));
	printf("%d\n", ft_fibonacci(10));

	printf("\n");

	printf("ft_sqrt\n");
	printf("%d\n", ft_sqrt(-1));
	printf("%d\n", ft_sqrt(0));
	printf("%d\n", ft_sqrt(1));
	printf("%d\n", ft_sqrt(2));
	printf("%d\n", ft_sqrt(3));
	printf("%d\n", ft_sqrt(4));
	printf("%d\n", ft_sqrt(5));
	printf("%d\n", ft_sqrt(9));
	printf("%d\n", ft_sqrt(16));
//	printf("%d\n", ft_sqrt(2147395600));
//	printf("%d\n", ft_sqrt(2147395599));
//	printf("%d\n", ft_sqrt(2147483647));
	printf("%d\n", ft_sqrt(-2147483648));

	printf("\n");

	printf("ft_is_prime\n");
	printf("%d\n", ft_is_prime(-2147483648));
	printf("%d\n", ft_is_prime(-1));
	printf("%d\n", ft_is_prime(0));
	printf("%d\n", ft_is_prime(1));
	printf("%d\n", ft_is_prime(2));
	printf("%d\n", ft_is_prime(3));
	printf("%d\n", ft_is_prime(4));
	printf("%d\n", ft_is_prime(5));
	printf("%d\n", ft_is_prime(6));
	printf("%d\n", ft_is_prime(7));
	printf("%d\n", ft_is_prime(8));
	printf("%d\n", ft_is_prime(9));
	printf("%d\n", ft_is_prime(10));
	printf("%d\n", ft_is_prime(11));
	printf("%d\n", ft_is_prime(12));
	printf("%d\n", ft_is_prime(2147483646));
	printf("%d\n", ft_is_prime(2147483647));

	printf("\n");

	printf("ft_find_next_prime\n");
	printf("%d\n", ft_find_next_prime(-2147483648));
	printf("%d\n", ft_find_next_prime(-1));
	printf("%d\n", ft_find_next_prime(0));
	printf("%d\n", ft_find_next_prime(1));
	printf("%d\n", ft_find_next_prime(2));
	printf("%d\n", ft_find_next_prime(3));
	printf("%d\n", ft_find_next_prime(4));
	printf("%d\n", ft_find_next_prime(5));
	printf("%d\n", ft_find_next_prime(6));
	printf("%d\n", ft_find_next_prime(7));
	printf("%d\n", ft_find_next_prime(8));
	printf("%d\n", ft_find_next_prime(9));
	printf("%d\n", ft_find_next_prime(10));
	printf("%d\n", ft_find_next_prime(11));
	printf("%d\n", ft_find_next_prime(12));
	printf("%d\n", ft_find_next_prime(2147483646));
	printf("%d\n", ft_find_next_prime(2147483647));

	printf("\n");
	
	printf("ft_ten_queens_puzzle\n");
//	printf("%d\n", ft_ten_queens_puzzle());

	return (0);
}
