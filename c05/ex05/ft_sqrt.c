/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:29:06 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/06 18:51:46 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sqrt_recursive(int n, int i)
{
	long long int	square;

	square = (long long int) i * (long long int) i;
	if (square == n)
		return (i);
	if (square < n)
		return (sqrt_recursive(n, i + 1));
	return (0);
}

int	ft_sqrt(int nb)
{
	if (nb <= 0)
		return (0);
	return (sqrt_recursive(nb, 1));
}
