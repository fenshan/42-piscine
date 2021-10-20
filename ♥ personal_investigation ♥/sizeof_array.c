/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:39:47 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/13 17:08:55 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int a[10];
	int *b;

	printf("B\tMemory address before malloc: %p\n\n", b);
	b = malloc(sizeof(int) * 10);

	printf("A\tMemory address (stack): %p\tSize: %d (number of ints * size of int)\n", a, sizeof(a));
	printf("B\tMemory address (heap): %p\tSize: %d (size of a pointer to int)\n", b, sizeof(b));

	return (0);
}
