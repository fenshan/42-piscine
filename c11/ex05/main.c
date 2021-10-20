/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:24:52 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/14 21:25:24 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void	ft_putnbr(int nb);
int		sum(int a, int b);
int		sub(int a, int b);
int		div(int a, int b);
int		mult(int a, int b);
int		mod(int a, int b);

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str += 1;
	}
}

int	operation_number(char *oper)
{
	if (oper[0] == '+' && oper[1] == '\0')
		return (0);
	if (oper[0] == '-' && oper[1] == '\0')
		return (1);
	if (oper[0] == '/' && oper[1] == '\0')
		return (2);
	if (oper[0] == '*' && oper[1] == '\0')
		return (3);
	if (oper[0] == '%' && oper[1] == '\0')
		return (4);
	return (-1);
}

int	ft_atoi(char *str)
{
	int	n;
	int	sign;

	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		++str;
	n = 0;
	sign = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= (-1);
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		n *= 10;
		n += ((*str - '0') * sign);
		++str;
	}
	return (n);
}

void	operate(int a, int b, int (*operations[5])(int, int), int op_n)
{
	if (op_n == 2 && !b)
		ft_putstr("Stop : division by zero");
	else if (op_n == 4 && !b)
		ft_putstr("Stop : modulo by zero");
	else
		ft_putnbr((*operations[op_n])(a, b));
	ft_putstr("\n");
}

int	main(int argc, char **argv)
{
	int	(*operations[5])(int a, int b);
	int	op_n;
	int	a;
	int	b;

	if (argc != 4)
		return (1);
	operations[0] = &sum;
	operations[1] = &sub;
	operations[2] = &div;
	operations[3] = &mult;
	operations[4] = &mod;
	op_n = operation_number(argv[2]);
	if (op_n != -1)
	{
		a = ft_atoi(argv[1]);
		b = ft_atoi(argv[3]);
		operate(a, b, operations, op_n);
	}
	else
		ft_putstr("0\n");
	return (0);
}
