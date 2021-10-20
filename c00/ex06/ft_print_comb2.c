/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:00:23 by fnicolas          #+#    #+#             */
/*   Updated: 2021/09/24 14:22:31 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_numbers(int a, int b)
{
	char	c;

	if (a != 0 || b != 1)
	{
		write(1, ", ", 2);
	}
	c = a / 10 + '0';
	ft_putchar(c);
	c = a % 10 + '0';
	ft_putchar(c);
	ft_putchar(' ');
	c = b / 10 + '0';
	ft_putchar(c);
	c = b % 10 + '0';
	ft_putchar(c);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a <= 99)
	{
		while (b <= 99)
		{
			if (a < b)
			{
				print_numbers (a, b);
			}
			++b;
		}
		b = 0;
		++a;
	}
}
