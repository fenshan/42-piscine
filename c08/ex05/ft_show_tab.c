/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:39:16 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/14 14:59:57 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		++str;
	}
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

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = -1;
	while (par[++i].str)
	{
		ft_putstr(par[i].str);
		ft_putstr("\n");
		ft_putnbr(par[i].size);
		ft_putstr("\n");
		ft_putstr(par[i].copy);
		ft_putstr("\n");
	}
}
