/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:58:55 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/04 18:05:16 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i])
		++i;
	j = 0;
	while (src[j] && j < nb)
	{
		dest[i] = src[j];
		++j;
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
