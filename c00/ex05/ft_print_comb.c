/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 13:27:11 by fnicolas          #+#    #+#             */
/*   Updated: 2021/09/24 13:56:13 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	try_to_print(char a, char b, char c)
{
	if (a < b && b < c)
	{
		if (a != '0' || b != '1' || c != '2')
		{
			write(1, ", ", 2);
		}
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, &c, 1);
	}
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	b = '0';
	c = '0';
	while (a <= '9')
	{
		while (b <= '9')
		{
			while (c <= '9')
			{
				try_to_print (a, b, c);
				++c;
			}
			c = '0';
			++b;
		}
		b = '0';
		++a;
	}	
}
