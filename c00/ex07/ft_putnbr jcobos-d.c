/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcobos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 23:13:47 by jcobos-d          #+#    #+#             */
/*   Updated: 2021/09/29 23:13:50 by jcobos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void ft_putnbr(int nb);
void ft_writeabs(int nb);

void ft_putnbr(int nb)
{
	if (nb == 0)
		write(1, "0",1);
	else if (nb / 10 != 0)
	{
		ft_putnbr(nb / 10);
		ft_writeabs(nb % 10);
	}
	else
	{
		if (nb < 0)
			write(1, "-",1);
		ft_writeabs(nb);
	}
}

void ft_writeabs(int nb)
{
	char c;

	c = 'X';
	if (nb < 0)
		c = -nb + '0';
	else
		c = nb + '0';
	write(1, &c, 1);
}