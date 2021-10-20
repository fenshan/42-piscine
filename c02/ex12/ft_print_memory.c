/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:53:19 by fnicolas          #+#    #+#             */
/*   Updated: 2021/09/30 19:11:02 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	convert_hex_digit(int a)
{
	if (a >= 0 && a <= 9)
		return (a + '0');
	else
		return (a - 10 + 'a');
}

void	print_int_as_hex(unsigned long long int n, int digits)
{
	char	c;

	if (digits > 0)
	{
		print_int_as_hex(n >> 4, digits - 1);
		c = convert_hex_digit(n & 15);
		write(1, &c, 1);
	}
}

void	print_hex_values(char *addr, int n)
{
	int	j;

	j = 0;
	while (j < 16)
	{
		if (j >= n)
			write(1, "  ", 2);
		else
			print_int_as_hex(*(addr + j), 2);
		if (j % 2 == 1)
			write(1, " ", 1);
		++j;
	}
}

void	print_ascii_values(char *addr, int n)
{
	int	j;

	j = 0;
	while (j < 16)
	{
		if (j < n)
		{
			if (*(addr + j) < ' ' || *(addr + j) == 127)
				write(1, ".", 1);
			else
				write(1, addr + j, 1);
		}
		++j;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		print_int_as_hex((unsigned long long int) addr + i, 16);
		write(1, ": ", 2);
		print_hex_values(addr + i, size - i);
		print_ascii_values(addr + i, size - i);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}
