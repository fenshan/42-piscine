/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 10:40:44 by josuna-t          #+#    #+#             */
/*   Updated: 2021/09/26 22:41:32 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	g_c1;
int	g_r1;

void	ft_putchar(char c);

void	rush(int x, int y)
{
	g_c1 = 0;
	if ((x > 0) || (y > 0))
	{
		while (g_c1 < y)
		{
			g_r1 = 0;
			while (g_r1 < x)
			{
				if ((g_c1 == 0) || (g_c1 == y - 1))
				{
					if ((g_r1 == 0) || (g_r1 == x - 1))
						ft_putchar('o');
					else
						ft_putchar('-');
				}
				else if ((g_r1 == 0) || (g_r1 == x - 1))
					ft_putchar('|');
				else
					ft_putchar(' ');
				g_r1++;
			}
			ft_putchar('\n');
			g_c1++;
		}
	}
}	
