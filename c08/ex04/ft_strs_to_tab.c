/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:58:51 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/14 15:12:59 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

struct s_stock_str	ini_stock_element(char *str)
{
	struct s_stock_str	element;
	int					j;

	if (!str)
	{
		element.str = 0;
		return (element);
	}
	j = 0;
	while (str[j])
		++j;
	element.size = j;
	element.str = str;
	element.copy = malloc (sizeof(char) * (element.size + 1));
	if (element.copy)
	{
		j = -1;
		while (++j < element.size)
			element.copy[j] = str[j];
		element.copy[j] = '\0';
	}
	return (element);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*sol;
	int					i;

	sol = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!sol)
		return (NULL);
	i = -1;
	while (++i < ac)
	{
		if (!av[i])
			return (NULL);
		sol[i] = ini_stock_element(av[i]);
		if (!sol[i].copy)
			return (NULL);
	}
	sol[i] = ini_stock_element(NULL);
	return (sol);
}
