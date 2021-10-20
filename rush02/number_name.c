/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:17:02 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/11 18:01:23 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "dict.h"

int	get_dict_index(unsigned int number);

void	write_str(char *str)
{
	int	i = 3;

	i = 0;
	while (str[i + 1])
	{
		write(1, str + i, 1);
		++i;
	}
	write(1, "\n", 1);
}

int	write_table(t_dict my_dict, int index, char *str)
{
	int	i;
	int	j;

	if (my_dict[index].name == 0)
		return (0);
	i = 0;
	while (str[i])
		++i;
	j = 0;
	while (my_dict[index].name[j])
	{
		str[i] = my_dict[index].name[j];
		++i;
		++j;
	}
	str[i] = ' ';
	str[++i] = '\0';
	return (1);
}

void	get_cdu(int cdu, int *c, int *d, int *u)
{
	*c = cdu / 100;
	*d = (cdu - *c * 100) / 10;
	*u = cdu - *c * 100 - *d * 10;
}

int	print_thousands(int cdu, int digits, t_dict my_dict, char *str)
{
	if (cdu && digits == 6
		&& !write_table(my_dict, get_dict_index(1000), str))
		return (0);
	if (cdu && digits == 9
		&& !write_table(my_dict, get_dict_index(1000000), str))
		return (0);
	if (cdu && digits == 12
		&& !write_table(my_dict, get_dict_index(1000000000), str))
		return (0);
	return (1);
}

int	print_three_digits(int cdu, int digits, t_dict my_dict, char *str)
{
	int	c;
	int	d;
	int	u;

	get_cdu(cdu, &c, &d, &u);
	if (c)
		if (!write_table(my_dict, c, str)
			|| !write_table(my_dict, get_dict_index(100), str))
			return (0);
	if (d != 1)
	{
		if (d)
			if (!write_table(my_dict, get_dict_index(d * 10), str))
				return (0);
		if (u)
			if (!write_table(my_dict, u, str))
				return (0);
	}
	else if (!write_table(my_dict, get_dict_index(d * 10 + u), str))
		return (0);
	if (!print_thousands(cdu, digits, my_dict, str))
		return (0);
	return (1);
}
