/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:01:41 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/11 20:51:02 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i + 1);
}

char	*ft_strdup(char *src)
{
	char	*strcpy;
	int		len;
	int		i;

	len = ft_strlen(src);
	strcpy = malloc (sizeof(strcpy) * len);
	if (!strcpy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		strcpy[i] = src[i];
		++i;
	}
	return (strcpy);
}
