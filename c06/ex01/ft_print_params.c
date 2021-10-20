/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 00:29:59 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/07 22:15:02 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char **argv)
{
	(void)argc;
	++argv;
	while (*argv)
	{
		while (**argv)
		{
			write(1, *argv, 1);
			++*argv;
		}
		write(1, "\n", 1);
		++argv;
	}
	return (0);
}
