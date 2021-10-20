/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:58:44 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/01 21:42:18 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (*(src + i) && i + 1 < size)
	{
		*(dest + i) = *(src + i);
		++i;
	}
	if (i < size)
		*(dest + i) = '\0';
	while (*(src + i))
		++i;
	return (i);
}
