/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:29:51 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/06 20:14:48 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	rec_is_prime(int nb, int i)
{
	if ((long int) i * i > nb)
		return (1);
	if (!(nb % i))
		return (0);
	return (rec_is_prime(nb, ++i));
}

int	rec_find_next_prime(int nb)
{
	if (nb == 2147483647)
		return (nb);
	if (rec_is_prime(nb, 2))
		return (nb);
	return (rec_find_next_prime(++nb));
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	return (rec_find_next_prime(nb));
}
