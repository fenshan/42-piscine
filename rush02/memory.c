/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:19:06 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/11 16:49:10 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "dict.h"

int	free_and_return(char *a, int return_value)
{
	if (a)
		free(a);
	return (return_value);
}

void	free_dict(t_dict my_dict)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (my_dict[i].name)
			free(my_dict[i].name);
		++i;
	}
}
