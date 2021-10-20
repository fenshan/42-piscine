/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:46:22 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/11 16:41:20 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include "dict.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_atoi(char *str, unsigned int *n);
int	free_and_return(char *a, int return_value);
int	char_is_space(char c);
int	get_dict_index(unsigned int number);
int	parse_number_name(char *content, int i, int j, char *number_name);
int	parse_dict_line(char *content, int i, int j, t_dict my_dict);

int	get_file_size(char *dict_name)
{
	int		fd;
	int		size;
	char	c;

	fd = open(dict_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	size = 0;
	while (read(fd, &c, 1) != 0)
		++size;
	close(fd);
	return (size);
}

int	get_file(char *dict_name, char *content, int file_size)
{
	int		fd;

	fd = open(dict_name, O_RDONLY);
	if (fd < 0)
		return (0);
	read(fd, content, file_size);
	close(fd);
	return (1);
}

int	parse_lines(t_dict my_dict, char *content)
{
	int		i;
	int		j;

	j = 0;
	while (content[j] != '\0')
	{
		i = j;
		while (content[j] != '\n')
			++j;
		if (!parse_dict_line(content, i, j, my_dict))
			return (0);
		++j;
	}
	return (1);
}

void	initialize_dict(t_dict my_dict)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		my_dict[i].name = 0;
		++i;
	}
}

int	parse_dict(char *dict_name, t_dict my_dict)
{
	int		file_size;
	char	*content;

	file_size = get_file_size(dict_name);
	if (file_size < 0)
		return (0);
	content = malloc(sizeof(char) * file_size);
	if (content == NULL || !get_file(dict_name, content, file_size))
		return (0);
	if (!parse_lines(my_dict, content))
	{
		free(content);
		return (0);
	}
	free(content);
	return (1);
}
