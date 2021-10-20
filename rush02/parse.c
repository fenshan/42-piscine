/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:02:23 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/11 17:12:33 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const static unsigned int	g_max_ui = 4294967295;

int	char_is_space(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	else
		return (0);
}

void	next_digit(unsigned int *n, char c)
{
	*n *= 10;
	*n += (c - '0');
}

int	ft_atoi(char *str, unsigned int *n)
{
	int	too_long;

	while (char_is_space(*str))
		++str;
	if (*str == '-')
		return (0);
	else if (*str == '+')
		++str;
	if (*str < '0' || *str > '9')
		return (0);
	*n = 0;
	too_long = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (too_long || (unsigned long int) *n * 10 + (*str - '0') > g_max_ui)
			too_long = 1;
		else
			next_digit(n, *str);
		++str;
	}
	if (*str != '\0')
		return (0);
	if (too_long)
		return (-1);
	return (1);
}

int	get_dict_index(unsigned int number)
{
	if (number >= 0 && number <= 20)
		return (number);
	else if (number % 10 == 0 && (number / 10) <= 10)
		return ((number / 10) + 18);
	else if (number == 1000)
		return (29);
	else if (number == 1000000)
		return (30);
	else if (number == 1000000000)
		return (31);
	else
		return (-1);
}
