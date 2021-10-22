/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:51:55 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/13 16:52:01 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/* To compare the memory addresses of stack vs heap allocated variables
/* - Stack: high addresses
/* - Heap: low addresses
*/
void foo(int valor) {
  unsigned char c;
  unsigned char *ptr = malloc(1);
  printf("Stack: %p | Heap: %p\n", &c, ptr);
  if(valor <= 0) return;
  foo(valor - 1);
}
int main(){
  foo(10);
  return 0;
}
