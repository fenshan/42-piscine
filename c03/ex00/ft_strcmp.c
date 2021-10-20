/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:28:07 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/04 17:28:40 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if ((unsigned char) s1[i] > (unsigned char) s2[i])
			return (1);
		else if (s1[i] != s2[i])
			return (-1);
		++i;
	}
	if (s1[i])
		return (1);
	else if (s2[i])
		return (-1);
	else
		return (0);
}
