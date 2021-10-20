/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 00:14:05 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/05 15:49:44 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	recursion(long int n)
{
	char	c;

	if (!n)
	{
		return ;
	}
	recursion(n / 10);
	c = (n % 10) + '0';
	ft_putchar(c);
}

void	ft_putnbr(int nb)
{
	long int	n;

	if (!nb)
	{
		ft_putchar('0');
		return ;
	}
	n = nb;
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	recursion(n);
}
