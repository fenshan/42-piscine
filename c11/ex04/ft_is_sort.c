/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:22:04 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/14 21:47:57 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	ascending;

	i = 0;
	ascending = 0;
	while (i < length)
	{
		if (i && (*f)(tab[i - 1], tab[i]) < 0)
		{
			if (ascending > 0)
				return (0);
			ascending = -1;
		}
		else if (i && (*f)(tab[i - 1], tab[i]) > 0)
		{
			if (ascending < 0)
				return (0);
			ascending = 1;
		}
		++i;
	}
	return (1);
}
