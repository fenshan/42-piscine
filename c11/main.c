/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:20:44 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/14 19:52:12 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_foreach(int *tab, int length, void(*f)(int));
int *ft_map(int *tab, int length, int(*f)(int));
int ft_any(char **tab, int(*f)(char*));
int ft_count_if(char **tab, int length, int(*f)(char*));
int ft_is_sort(int *tab, int length, int(*f)(int, int));

void ft_sort_string_tab(char **tab);
void ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *));

#include <stdio.h>

void	ft_putnbr(int n)
{
	printf("%d\n", n);
}

int	ft_multiply(int n)
{
	return (n * 2);
}

int	main(void)
{
	int tab[10] = {8, 5, 2, 3, 4, 5};
	ft_foreach(tab, 7, &ft_putnbr);
	printf("\n");

	ft_foreach(ft_map(tab, 7, &ft_multiply), 7, &ft_putnbr);
	printf("\n");


	printf("\n");


	return (0);
}
