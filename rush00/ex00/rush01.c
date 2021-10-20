/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 10:40:44 by josuna-t          #+#    #+#             */
/*   Updated: 2021/09/25 13:47:25 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	c1;
	int	r1;

	c1 = 0;
	while (c1 < y)
	{
		r1 = 0;
		while (r1 < x)
		{
			if (c1 > 0 && c1 < y - 1 && r1 > 0 && r1 < x - 1)
				ft_putchar(' ');
			else if (!c1 && !r1)
				ft_putchar('/');
			else if (c1 == y - 1 && r1 == x - 1 && y > 1 && x > 1)
				ft_putchar('/');
			else if ((c1 == y - 1 && r1 == 0) || (c1 == 0 && r1 == x - 1))
				ft_putchar('\\');
			else
				ft_putchar('*');
			r1++;
		}
		ft_putchar('\n');
		c1++;
	}
}
