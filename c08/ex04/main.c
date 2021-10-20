/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:35:43 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/14 17:21:58 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_show_tab(struct s_stock_str *par);
struct	s_stock_str *ft_strs_to_tab(int ac, char **av);

int	main(void)
{
	struct s_stock_str	*tab;
	char				str1[] = "asdf";
	char				str2[] = "uwu";
	char				str3[] = "ttt";
	char				str4[] = "pp";
	char				str5[] = "uwuwuwuw";
	char				**strs;

	strs = malloc(5 * 8);
	strs[0] = str1;
	strs[1] = str2;
	strs[2] = str3;
	strs[3] = str4;
	strs[4] = str5;

	if (!strs[4])
		printf("null\n");

	tab = ft_strs_to_tab(5, strs);

	tab[1].copy = "jejjej";

	if (!tab)
		printf("tab is null\n");
	else
		ft_show_tab(tab);

	return (0);
}
