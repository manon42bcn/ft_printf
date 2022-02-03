
#include <stdio.h>
#include "includes/ft_printf.h"
#include "srcs/ft_printf.c"
#include "srcs/ft_printf_input.c"
#include "srcs/ft_token_hexa.c"
#include "srcs/ft_token_numbers.c"
#include "srcs/ft_token_strings.c"
#include "srcs/ft_printf_utils.c"

/*
int	ft_print_int_test(float nbr)
{
	char	c;

	if (nbr < 0)
		nbr = nbr * -1;
	c = (nbr % 10) + '0';
	if (nbr > 10)
	{
	return (ft_print_int_test(nbr / 10)
			+ write(1, &c, 1));
	}
	else
		return (write(1, &c, 1));
}
*/
int main(void)
{
	char *ptr;
	int test;

	test = ft_printf(" %% :");
	printf("\n%i rst\n", test);
	printf("\n=====\n");
	test = printf(" %% :");
	printf("\n%i\n", test);
	
}