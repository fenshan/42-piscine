/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:10:13 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/10 18:35:11 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

struct s_dict_element
{
	unsigned int	num;
	char			*name;
};

typedef struct s_dict_element	t_dict[32];

#endif
