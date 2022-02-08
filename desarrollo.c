
#include <stdio.h>
#include <limits.h>
#include "includes/ft_printf_bonus.h"

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
	char ptr;

	char *c;
	int test;
	test = ft_printf("[%#x %#x %#x %#x %#x %#x %#x]\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf("rst ft: %i\n", test);
	test = printf("[%#x %#x %#x %#x %#x %#x %#x]\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf("rst pf: %i\n", test);
	 //write(1, c, 5);
	//ft_printf("%c - %s - %p %d - %i - %u - %x %X %%", 'a', "test", (void *)0xdeadc0de, 20, -20, -1, -1, 200000000);
	
}