/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:29:37 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/04 17:36:05 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if ((unsigned char) s1[i] > (unsigned char) s2[i])
			return (1);
		else if (s1[i] != s2[i])
			return (-1);
		++i;
	}
	if (i == n)
		return (0);
	else if (s1[i])
		return (1);
	else if (s2[i])
		return (-1);
	else
		return (0);
}
