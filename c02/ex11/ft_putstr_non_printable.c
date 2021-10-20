/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:48:27 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/01 22:47:57 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	convert_hex_digit(int a)
{
	if (a >= 0 && a <= 9)
		return (a + '0');
	else
		return (a - 10 + 'a');
}

void	convert_char_to_hex(char hex[], unsigned char  n)
{
	hex[0] = convert_hex_digit(n / 16);
	hex[1] = convert_hex_digit(n & 15);
}

void	ft_putstr_non_printable(char *str)
{
	char	hex[2];

	while (*str)
	{
		if (*str < ' ' || *str == 127)
		{
			write(1, "\\", 1);
			convert_char_to_hex(hex, *str);
			write(1, hex, 2);
		}
		else
			write(1, str, 1);
		++str;
	}
}
