/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:40:08 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/11 18:09:26 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <unistd.h>

int				ft_atoi(char *str, unsigned int *n);
int				char_is_space(char c);
int				get_file_size(char *dict_name);
int				get_file(char *dict_name, char *content, int file_size);
void			parse_dict_line(char *content, int i, int j, t_dict my_dict);
int				parse_dict(char *dict_name, t_dict my_dict);
int				free_and_return(char *a, int return_value);
int				get_dict_index(unsigned int number);
int				print_three_digits(int cdu, int dig, t_dict my_dict, char *str);
int				write_table(t_dict my_dict, int index, char *str);
void			write_str(char *str);
void			free_dict(t_dict my_dict);
int				get_number_of_digits(unsigned int n);
unsigned int	ft_power(unsigned int nb, int power);
void			initialize_dict(t_dict my_dict);

int	error(t_dict my_dict)
{
	free_dict(my_dict);
	write(2, "Error\n", 6);
	return (1);
}

int	dict_error(t_dict my_dict)
{
	free_dict(my_dict);
	write(2, "Dict Error\n", 11);
	return (1);
}

int	no_errors(t_dict my_dict)
{
	free_dict(my_dict);
	return (0);
}

int	print_number_name(t_dict my_dict, unsigned int n, char *str)
{
	int			cdu;
	int			digits;
	long int	aux;

	str[0] = '\0';
	if (!n)
		return (write_table(my_dict, 0, str));
	digits = get_number_of_digits(n);
	if (digits % 3 != 0)
		digits = (digits / 3 + 1) * 3;
	if (digits == 12)
	{
		if (!print_three_digits(n / ft_power(10, 9), 12, my_dict, str))
			return (0);
		digits -= 3;
	}
	while (digits > 0)
	{
		aux = ft_power(10, digits);
		cdu = (n - (n / aux) * aux) / (aux / 1000);
		if (!print_three_digits(cdu, digits, my_dict, str))
			return (0);
		digits -= 3;
	}
	return (1);
}	

int	main(int argc, char **argv)
{
	unsigned int	n;
	t_dict			my_dict;
	char			result_string[1000];

	initialize_dict(my_dict);
	if (argc == 2)
	{
		if (!parse_dict("numbers.dict", my_dict))
			return (dict_error(my_dict));
		else if (ft_atoi(argv[1], &n) <= 0)
			return (error(my_dict));
	}
	else if (argc == 3)
	{
		if (!parse_dict(argv[1], my_dict))
			return (dict_error(my_dict));
		else if (ft_atoi(argv[2], &n) <= 0)
			return (error(my_dict));
	}
	else
		return (error(my_dict));
	if (!print_number_name(my_dict, n, result_string))
		return (dict_error(my_dict));
	write_str(result_string);
	return (no_errors(my_dict));
}
