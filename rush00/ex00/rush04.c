/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:30:30 by almferna          #+#    #+#             */
/*   Updated: 2021/09/26 14:55:15 by fnicolas         ###   ########.fr       */
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
			else if ((c1 > 0 && c1 < y - 1) || (r1 > 0 && r1 < x - 1))
				ft_putchar('B');
			else if ((c1 == 0 && r1 == 0))
				ft_putchar('A');
			else if (c1 == y - 1 && r1 == x - 1 && (x > 1 && y > 1))
				ft_putchar('A');
			else
				ft_putchar('C');
			r1++;
		}
		ft_putchar('\n');
		c1++;
	}
}
