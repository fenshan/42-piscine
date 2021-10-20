/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:08:24 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/05 13:29:46 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i])
		++i;
	j = 0;
	while (src[j] && i + 1 < size)
	{
		dest[i] = src[j];
		++j;
		++i;
	}
	if (i < size)
		dest[i] = '\0';
	else if (i > size)
		i = size;
	while (src[j])
	{
		++j;
		++i;
	}
	return (i);
}
