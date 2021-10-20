/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:02:56 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/12 14:59:16 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *ft_strdup(char *src);
int *ft_range(int min, int max);
int ft_ultimate_range(int **range, int min, int max);
char *ft_strjoin(int size, char **strs, char *sep);
char *ft_convert_base(char *nbr, char *base_from, char *base_to);
char **ft_split(char *str, char *charset);

int	main(void)
{
	char *str;
	int	*array;
	int	a2;
	int *a1;
	int	**a;
	char *strs2[] = {"aa","bb","cc", "dd", "ee"};
	char *base_str;
	char **strs05;

	str = ft_strdup("abc");
	printf("%s\n", str);
	free(str);

	array = ft_range(-5, 7);
	for(int loop = 0; array && loop < 20; loop++)
      printf("%d ", array[loop]);
	printf("\n");

	a1 = &a2;
	a = &a1;
	printf("%d\n", ft_ultimate_range(a, 1, 9));
	for(int loop = 0; *a && loop < 20; loop++)
	   printf("%d ", a[0][loop]);
	printf("\n");

	printf("%s\n", ft_strjoin(0, strs2, "uwu"));
	printf("%s\n", ft_strjoin(1, strs2, "uwu"));
	printf("%s\n", ft_strjoin(2, strs2, "uwu"));
	printf("%s\n", ft_strjoin(3, strs2, "uwu"));
	printf("%s\n", ft_strjoin(4, strs2, "uwu"));
	printf("%s\n", ft_strjoin(5, strs2, "uwu"));

	printf("\n");
	base_str = ft_convert_base("+2147483647", "0123456789", "0123456789");
	printf("%s\n", base_str); 
	base_str = ft_convert_base("+21474", "01234567890", "0123456789");
	printf("%s\n", base_str); 
	base_str = ft_convert_base("+2147483", "0123456789", "+0123456789");
	printf("%s\n", base_str); 
	base_str = ft_convert_base("--[]]]]]", "][", "0123456789");
	printf("%s\n", base_str); 
	base_str = ft_convert_base("---asdf", "asdf", "012345678");
	printf("%s\n", base_str); 
	base_str = ft_convert_base("---a", "asdfghjk", "0123456789");
	printf("%s\n", base_str); 
	base_str = ft_convert_base("---a", "0123456789ABCDEF", "0123456789");
	printf("%s\n", base_str); 
	base_str = ft_convert_base("---1000", "0123456789ABCDEF", "0123456789");
	printf("%s\n", base_str); 
	printf("\n");

	strs05 = ft_split("awasdfuvvuwutteu", "uwu");
	while (*strs05)
	{
	   printf("%s\n", *strs05);
	   ++strs05;
	}
	printf("\n");

	strs05 = ft_split("wuwuwuw", "uwu");
	while (*strs05)
	{
	   printf("%s\n", *strs05);
	   ++strs05;
	}
	printf("\n");

	strs05 = ft_split("wuwyyyutwuw", "uwu");
	while (*strs05)
	{
	   printf("%s\n", *strs05);
	   ++strs05;
	}
	printf("\n");

	strs05 = ft_split("wuwuwuwttt", "uwu");
	while (*strs05)
	{
	   printf("%s\n", *strs05);
	   ++strs05;
	}
	printf("\n");

	return (0);
}
