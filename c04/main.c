int ft_strlen(char *str);
void ft_putstr(char *str);
void ft_putnbr(int nb);
int ft_atoi(char *str);
void ft_putnbr_base(int nbr, char *base);
int ft_atoi_base(char *str, char *base);

#include<stdio.h>

int	main(void)
{
	printf("%d\n", ft_strlen("asdf\n\t"));

	ft_putstr("asdf\n\ta");

	printf("\n");

	ft_putnbr(0);
	printf("\n");
	ft_putnbr(42);
	printf("\n");
	ft_putnbr(-42);
	printf("\n");
	ft_putnbr(-2147483648);
	printf("\n");
	ft_putnbr(	+2147483647);
	printf("\n");
	printf("\n");

	printf("%d\n", ft_atoi(" ---+--+1234ab567"));
	printf("%d\n", ft_atoi(" 	---+1234\rab567"));
	printf("%d\n", ft_atoi(" \n\t\r\v\f---+--2147483648ab567"));

	printf("\n");
	
	ft_putnbr_base(-2147483648, "\\123-");
	printf("\n");

	printf("%d\n", ft_atoi_base(" \t\n2147483647", "0123456789"));
	printf("%d\n", ft_atoi_base(" \t\n2147483648", "0123456789"));
	printf("%d\n", ft_atoi_base(" \t\n-2147483648", "0123456789"));
	printf("%d\n", ft_atoi_base(" \t\n-2147483649", "0123456789"));

	return (0);
}
