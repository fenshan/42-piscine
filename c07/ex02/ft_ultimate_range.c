/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:03:27 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/11 21:26:56 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range_for_ultimate(int min, int len)
{
	int	*a;
	int	i;

	a = malloc(sizeof(*a) * len);
	if (!a)
		return (NULL);
	i = 0;
	while (i < len)
	{
		a[i] = min;
		++min;
		++i;
	}
	return (a);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	len = max - min;
	*range = ft_range_for_ultimate(min, len);
	if (!(*range))
		return (-1);
	return (len);
}
