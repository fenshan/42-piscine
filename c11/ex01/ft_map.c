/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:21:01 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/14 19:51:09 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	i;
	int	*results;

	results = malloc(sizeof(*results) * length);
	if (!results)
		return (NULL);
	i = -1;
	while (++i < length)
		results[i] = (*f)(tab[i]);
	return (results);
}
