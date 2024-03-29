/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 00:14:45 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/05 16:56:03 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_atoi(char *str)
{
	int	n;
	int	sign;

	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		++str;
	n = 0;
	sign = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= (-1);
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		n *= 10;
		n += ((*str - '0') * sign);
		++str;
	}
	return (n);
}
