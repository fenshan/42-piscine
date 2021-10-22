/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizeof_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:39:47 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/13 17:08:55 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

/* Program used to check the behaviour of the operator sizeof() in stack arrays vs heap arrays
/* - sizeof(stack_array) returns the space reserved in memory for the array (number of elements * size of elements)
/* - sizeof(heap_array) returns the space reserved for the pointer to the first element (always 8 bytes in 64-bit architecture)
*/
int	main(void)
{
	int a[10];
	int *b;

	printf("B\tMemory address before malloc: %p\n\n", b);
	b = malloc(sizeof(int) * 10);

	//A       Memory address (stack): 0xffffcc10      Size: 40 (number of ints * size of int)
	printf("A\tMemory address (stack): %p\tSize: %d (number of ints * size of int)\n", a, sizeof(a));
	//B       Memory address (heap): 0x800000440      Size: 8 (size of a pointer to int)
	printf("B\tMemory address (heap): %p\tSize: %d (size of a pointer to int)\n", b, sizeof(b));

	return (0);
}
