/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:13:32 by fnicolas          #+#    #+#             */
/*   Updated: 2021/09/29 17:35:16 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && *(src + i))
	{
		*(dest + i) = *(src + i);
		++i;
	}
	while (i < n)
	{
		*(dest + i) = '\0';
		++i;
	}
	return (dest);
}
