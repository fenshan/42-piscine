/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 00:16:53 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/05 19:56:48 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	char_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

int	base_atoi_is_correct(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			++j;
		}
		++i;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	n;
	long int	n_long;
	int	base_number;
	int	sign;

	base_number = base_atoi_is_correct(base);
	if (!base_number)
		return (0);
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		++str;
	n = 0;
	n_long = 0;
	sign = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= (-1);
		++str;
	}
	while (char_in_base(*str, base) >= 0)
	{
		n_long *= base_number;
		n_long += (char_in_base(*str, base) * sign);
		if (n_long >= 2147483648 || n_long < -2147483648)
			return (0);
		n = n_long;
		++str;
	}
	return (n);
}
