/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:29:21 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/06 19:46:43 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	recursive_is_prime(int nb, int i)
{
	if ((long int) i * i > nb)
		return (1);
	if (!(nb % i))
		return (0);
	return (recursive_is_prime(nb, ++i));
}

int	ft_is_prime(int nb)
{
	if (nb < 2)
		return (0);
	return (recursive_is_prime(nb, 2));
}
