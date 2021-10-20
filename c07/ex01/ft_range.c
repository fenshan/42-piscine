/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:02:24 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/11 21:33:52 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*a;
	int	len;
	int	i;

	if (min >= max)
		return (NULL);
	len = max - min;
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
