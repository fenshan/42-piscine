/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:55:55 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/13 12:04:05 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b);
int		ft_strcmp(char *s1, char *s2);

int	main(void)
{
	int	a;
	int	b;
	
	a = 0;
	b = 42;

	printf("%d %d\n", a, b);
	ft_swap(&a, &b);
	printf("%d %d\n", a, b);

	printf("%d\n", ft_strcmp("aaa", "a"));
	printf("%d\n", ft_strcmp("z", "zzz"));
	printf("%d\n", ft_strcmp("az", "aa"));
	printf("%d\n", ft_strcmp("az", "az"));
}
