/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 23:34:29 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/11 16:59:43 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "dict.h"
#include <fcntl.h>
#include <stdlib.h>

int	free_and_return(char *a, int return_value);
int	ft_atoi(char *str, unsigned int *n);
int	free_and_return(char *a, int return_value);
int	char_is_space(char c);
int	get_dict_index(unsigned int number);

int	parse_number_name(char *content, int i, int j, char *number_name)
{
	int	aux_index;

	if (i == j)
		return (0);
	aux_index = 0;
	while (i < j)
	{
		number_name[aux_index] = content[i];
		++i;
		++aux_index;
	}
	number_name[aux_index] = '\0';
	return (1);
}

void	ignore_spaces(char *content, int *i, int *j)
{
	while (*i < *j && char_is_space(content[*i]))
		(*i) += 1;
}

int	parse_dict_line_int(char *content, int *i, int *j, char *aux)
{
	int	aux_index;

	ignore_spaces(content, i, j);
	if (*i == *j)
		return (0);
	aux_index = 0;
	while (*i < *j && !char_is_space(content[*i]) && content[*i] != ':')
	{
		aux[aux_index] = content[*i];
		(*i) += 1;
		++aux_index;
	}
	aux[aux_index] = '\0';
	return (1);
}

int	parse_dict_line(char *content, int i, int j, t_dict my_dict)
{
	char			*aux;
	unsigned int	number;
	char			*number_name;

	aux = malloc(sizeof(char) * (j - i + 1));
	if (aux == NULL)
		return (0);
	if (!parse_dict_line_int(content, &i, &j, aux))
		return (free_and_return(aux, 1));
	if (ft_atoi(aux, &number) <= 0)
		return (free_and_return(aux, -ft_atoi(aux, &number)));
	number_name = "";
	ignore_spaces(content, &i, &j);
	if (content[i++] != ':')
		return (free_and_return(aux, 0));
	ignore_spaces(content, &i, &j);
	number_name = malloc(sizeof(char) * (j - i + 1));
	if (number_name == NULL || !parse_number_name(content, i, j, number_name))
		return (free_and_return(aux, 0));
	if (get_dict_index(number) < 0)
		return (free_and_return(aux, 1));
	my_dict[get_dict_index(number)].num = number;
	my_dict[get_dict_index(number)].name = number_name;
	return (free_and_return(aux, 1));
}
