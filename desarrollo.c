
#include <stdio.h>
#include "includes/ft_printf.h"

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
	int test;

	char *c;
	ft_printf("strlen %d\n", ft_strlen("Hola Manuel"));
  	//ft_printf("[%000000.5d]", 0);
  	ft_printf("[%0000005d]", 0);
	 //write(1, c, 5);
	//ft_printf("%c - %s - %p %d - %i - %u - %x %X %%", 'a', "test", (void *)0xdeadc0de, 20, -20, -1, -1, 200000000);
	
}