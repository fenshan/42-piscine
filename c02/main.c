/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:45:38 by fnicolas          #+#    #+#             */
/*   Updated: 2021/10/01 22:36:34 by fnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int	ft_str_is_alpha(char *str);
int	ft_str_is_numeric(char *str);
int	ft_str_is_lowercase(char *str);
int	ft_str_is_uppercase(char *str);
int	ft_str_is_printable(char *str);
char	*ft_strupcase(char *str);
char	*ft_strlowcase(char *str);
char	*ft_strcapitalize(char *str);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
void	ft_putstr_non_printable(char *str);
void	*ft_print_memory(void *addr, unsigned int size);

int	main (void)
{
	char s1[20];
	char s2[20] = "hola jiji\n";

	printf("\n");

	printf("%s", ft_strcpy(s1, s2)); //ex00
	ft_strcpy(s1, "segunda string\n");
	printf("%s", s1);
	
	printf("\n");

	printf("%s", ft_strncpy(s1, s2, 3)); //ex01
	ft_strncpy(s1, "segunda string\n", 30);
	printf("%s", s1);

	printf("\n");

	printf("%d", ft_str_is_alpha("aklsjdfhALKSJDHAKJalksdjf")); //ex02
	printf("%d", ft_str_is_alpha("aklsjdfhALK0SJDHAKJalksdjf")); //ex02
	printf("%d", ft_str_is_alpha("")); //ex02

	printf("\n");

	printf("%d", ft_str_is_numeric("83678247957823094710293184675")); //ex03
	printf("%d", ft_str_is_numeric("8367824795782309471029318]4675")); //ex03
	printf("%d", ft_str_is_numeric("")); //ex03

	printf("\n");


	printf("%d", ft_str_is_lowercase("aklsjdfhalksdjf")); //ex04
	printf("%d", ft_str_is_lowercase("aklsjdfsdgsdÑjf")); //ex04
	printf("%d", ft_str_is_lowercase("aklsjdfsdgsdAjf")); //ex04
	printf("%d", ft_str_is_lowercase("")); //ex04

	printf("\n");

	printf("%d", ft_str_is_uppercase("ALKSJDFHASLJDHAL")); //ex05
	printf("%d", ft_str_is_uppercase("ALKSJDKLAJSDn")); //ex05
	printf("%d", ft_str_is_uppercase("AJKSDGHA ASDJGH")); //ex05
	printf("%d", ft_str_is_uppercase("")); //ex05

	printf("\n");

	printf("%d", ft_str_is_printable("kajjhfa }{{\"|lld")); //ex06
	char str[] = "hello";
	str[4] = 123;
	printf("%d", ft_str_is_printable(str)); //ex06
	str[4] = 127;
	printf("%d", ft_str_is_printable(str)); //ex06
	printf("%d", ft_str_is_printable("")); //ex06

	printf("\n");

	char p[] = "123 }*) abc xyz ABC XYZ";
	printf("%s\n", ft_strupcase(p)); //ex07
	printf("%s\n", ft_strlowcase(p)); //ex08

	printf("\n");

	char p90[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf("%s\n", ft_strcapitalize(p90)); //ex09
	char p91[] = "dG5!vnPyiJ)b>7CXQTHUp90bYcOHTHfZ'@j:l";
	printf("%s\n", ft_strcapitalize(p91)); //ex09
	char p92[] = "R]OzD";
	printf("%s\n", ft_strcapitalize(p92)); //ex09
	char p93[] = "U:?NBu<CiYitY";
	printf("%s\n", ft_strcapitalize(p93)); //ex09
	char p94[] = "SY|PoAPp4[Y@Df@.S=+Mm";
	printf("%s\n", ft_strcapitalize(p94)); //ex09
	char p95[] = "ErG$5.!06VkLs1{F#N]";
	printf("%s\n", ft_strcapitalize(p95)); //ex09
	char p96[] = "nULL";
	printf("%s\n", ft_strcapitalize(p96)); //ex09
	char p97[] = "reKt17+lOl mdR mdr 4242l42";
	printf("%s\n", ft_strcapitalize(p97)); //ex09

	printf("\n");

	char str10[20];
//	printf("%d\n", ft_strlcpy(str10, "hola", 0)); //ex10
//	printf("%s\n", str10); //ex10
	printf("%d\n", ft_strlcpy(str10, "hola", 2)); //ex10
	printf("%s\n", str10); //ex10
	printf("%d\n", ft_strlcpy(str10, "hola", 4)); //ex10
	printf("%s\n", str10); //ex10
	printf("%d\n", ft_strlcpy(str10, "hola", 7)); //ex10
	printf("%s\n", str10); //ex10
	printf("%d\n", ft_strlcpy(str10, "hYlLhhVHOIxlOP", 2)); //ex10
	printf("%s\n", str10); //ex10

	printf("\n");

	ft_putstr_non_printable("Coucou\ntu vas bien ?"); //ex11
	printf("\n");
	ft_putstr_non_printable("[\\]^_`abc"); //ex11
	printf("\n");
	ft_putstr_non_printable(" !\"#"); //ex11
	printf("\n");
	char str11[] = {127, 208, 0};
	ft_putstr_non_printable(str11); //ex11

	printf("\n");

//	char str12[] = "Bonjour\tles aminches...c'est fou\ntout\ace qu on peut faire avec...print_memory....lol.lol\t .";
//	ft_print_memory(str12, 100);


	return (0);
}
