/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 00:30:23 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/07 22:16:06 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	reverse_print(char **argv)
{
	if (!*argv)
		return ;
	reverse_print(argv + 1);
	while (**argv)
	{
		write(1, *argv, 1);
		++*argv;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	(void)argc;
	reverse_print(++argv);
	return (0);
}
