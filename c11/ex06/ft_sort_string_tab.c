/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:23:00 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/14 21:48:10 by fnicolas         ###   ########.fr       */
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

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	char	*aux;

	i = -1;
	while (tab[++i])
	{
		j = i;
		while (tab[++j])
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				aux = tab[i];
				tab[i] = tab[j];
				tab[j] = aux;
			}
		}
	}
}
