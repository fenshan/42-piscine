/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:05:43 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/04 19:04:00 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_return_if_found(int condition, char *start)
{
	if (condition)
		return (start);
	else
		return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	char	*start;
	int		j;

	start = str;
	j = 0;
	while (*str && to_find[j])
	{
		if (*str == to_find[j])
		{
			if (!j)
				start = str;
			++j;
		}
		else if (*str == to_find[0])
		{
			start = str;
			j = 1;
		}
		else
			j = 0;
		++str;
	}
	return (ft_return_if_found(!to_find[j], start));
}
