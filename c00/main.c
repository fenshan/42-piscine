//by rpena-ji

#include <unistd.h>

void	ft_putchar(char c);
void	ft_print_alphabet(void);
void	ft_print_reverse_alphabet(void);
void	ft_print_numbers(void);
void	ft_is_negative(int n);
void	ft_print_comb(void);
void	ft_print_comb2(void);
void	ft_putnbr(int nb);
void	ft_print_combn(int n);

int	main(void)
{
	ft_putchar('c');				// ex00
	write (1, "\n", 1);

	ft_print_alphabet();			// ex01
	write (1, "\n", 1);

	ft_print_reverse_alphabet();	// ex02
	write (1, "\n", 1);

	ft_print_numbers();				// ex03
	write (1, "\n", 1);

	ft_is_negative(5); 				// ex04 (caso P)
	write (1, "\n", 1);

	ft_is_negative(-5);				// ex04 (caso N)
	write (1, "\n", 1);

	ft_print_comb();				// ex05
	write (1, "\n", 1);

	ft_print_comb2();				// ex06
	write (1, "\n", 1);
	
	ft_putnbr(2147483647); 			// ex07 - MAX positivo
	write (1, "\n", 1);
	
	ft_putnbr(-2147483648); 		// ex07 - MIN negativo
	write (1, "\n", 1);
	
	ft_print_combn(4); 				// ex08
	write (1, "\n", 1);

	return (0);
}

//clear && find . -name "ft*.c" -exec norminette -R CheckForbiddenSourceHeader {} ";" && gcc -Wall -Werror -Wextra ./main.c ./ex0*/*.c && ./a.out