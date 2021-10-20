/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:52:42 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/01 22:26:00 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alphanumeric(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) >= 'a' && *(str + i) <= 'z')
		{
			if (!i || !is_alphanumeric(*(str + i - 1)))
				*(str + i) = *(str + i) - 'a' + 'A';
		}
		else if (*(str + i) >= 'A' && *(str + i) <= 'Z')
			if (i && is_alphanumeric(*(str + i - 1)))
				*(str + i) = *(str + i) - 'A' + 'a';
		++i;
	}
	return (str);
}
