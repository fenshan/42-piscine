/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 00:30:48 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/07 22:17:01 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

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

void	print_string(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		++str;
	}
	write(1, "\n", 1);
}	

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*aux;

	(void)argc;
	i = 0;
	while (argv[++i])
	{
		j = i;
		while (argv[++j])
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				aux = argv[i];
				argv[i] = argv[j];
				argv[j] = aux;
			}
		}
		print_string(argv[i]);
	}
	return (0);
}
