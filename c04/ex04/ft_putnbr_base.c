/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 00:15:40 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/05 17:42:25 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar_base(char c)
{
	write(1, &c, 1);
}

void	recursion_putnbr_base(long int n, char *base, int base_number)
{
	char	c;

	if (!n)
	{
		return ;
	}
	recursion_putnbr_base(n / base_number, base, base_number);
	c = base[n % base_number];
	ft_putchar_base(c);
}

int	base_is_correct(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			++j;
		}
		++i;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	n;
	int			base_number;

	base_number = base_is_correct(base);
	if (!base_number)
		return ;
	if (!nbr)
	{
		ft_putchar_base(base[0]);
		return ;
	}
	n = nbr;
	if (n < 0)
	{
		n = -n;
		ft_putchar_base('-');
	}
	recursion_putnbr_base(n, base, base_number);
}
