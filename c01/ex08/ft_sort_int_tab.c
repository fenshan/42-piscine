/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:33:35 by fnicolas          #+#    #+#             */
/*   Updated: 2021/09/27 19:59:41 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	aux;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (*(tab + i) > *(tab + j))
			{
				aux = *(tab + i);
				*(tab + i) = *(tab + j);
				*(tab + j) = aux;
			}
			++j;
		}
		++i;
	}
}
