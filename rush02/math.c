/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 23:25:19 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/10 23:36:12 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_number_of_digits(unsigned int n)
{
	int					cont;
	unsigned long int	aux;

	if (!n)
		return (1);
	cont = 1;
	aux = 1000000000;
	while (!(unsigned long int)(n / aux))
		aux /= 10;
	while (aux > 1)
	{
		++cont;
		aux /= 10;
	}
	return (cont);
}

unsigned int	ft_power(unsigned int nb, int power)
{
	if (power < 0)
		return (0);
	if (!power)
		return (1);
	return (nb * ft_power(nb, power - 1));
}
