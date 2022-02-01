/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:02:45 by mporras-          #+#    #+#             */
/*   Updated: 2022/01/31 12:02:49 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

/*
	Conversiones -0 flag de min width
	flags de conversiones # ' ' + 
		0 : justifica con ceros un numero %03i imprime 12 como 012 (revisar hexa piscina)
		mw: expresado con un numero. se rellena la cadena con espacios a la izquierda.
		+ : imprime el signo de un numero.
		# : Formato alternativo. Para reales se dejan ceros al final y se imprime siempre la coma. 
			Para números que no están en base 10, se añade un prefijo denotando la base
			  -      Left justify.
			   0  	  Field is padded with 0's instead of blanks.
			   +	  Sign of number always O/P.
			   blank  Positive values begin with a blank.
			   # 	  Various uses:
				  %#o (Octal) 0 prefix inserted.
				  %#x (Hex)   0x prefix added to non-zero values.
				  %#X (Hex)   0X prefix added to non-zero values.
				  %#e         Always show the decimal point.
				  %#E         Always show the decimal point.
				  %#f         Always show the decimal point.
				  %#g         Always show the decimal point trailing 
				  	      zeros not removed.
				  %#G         Always show the decimal point trailing
					      zeros not removed.
	  ' ' : Use un espacio en blanco para antefir el valor de salida si está firmado y es positivo.
	  		El espacio en blanco se omite si aparecen las marcas blank y +. (añade un espacio antes...)
*/

void	ft_print_pointer(unsigned long nbr, char *base, int base_num)
{
	if (nbr >= base_num)
	{
		ft_print_pointer(nbr / base_num, base, base_num);
		write(1, &base[nbr % base_num], 1);
	}
	else
		write(1, &base[nbr], 1);
}

void	ft_print_base(unsigned int nbr, char *base, int base_num)
{
	if (nbr >= base_num)
	{
		ft_print_base(nbr / base_num, base, base_num);
		write(1, &base[nbr % base_num], 1);
	}
	else
		write(1, &base[nbr], 1);
}

void	ft_proccess_args(va_list args, char key)
{
	if (key == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	if (key == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	if (key == 'i')
		ft_putstr_fd(ft_itoa(va_arg(args, int)), 1);
	if (key == 'p')
		ft_print_pointer(va_arg(args, unsigned long), "0123456789abcdef", 16);
	if (key == 'x')
		ft_print_base(va_arg(args, unsigned int), "0123456789abcdef", 16);
	if (key == 'X')
		ft_print_base(va_arg(args, unsigned int), "0123456789ABCDEF", 16);
}
/*
int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
*/

int	ft_str_ins_test(char *src, ...)
{
	va_list args;
	int		i;

	i = 0;
	va_start(args, src);
	while (src[i])
	{
		if (src[i] == '%')
		{
			i++;
			if(src[i])
				ft_proccess_args(args, src[i]);
		}
		else
			ft_putchar_fd(src[i], 1);
		i++;
	}
	va_end(args);
}

char	*ft_str_ins(char *src, char *ins, char c)
{
	char	*rst;
	int		total;
	int		i; 
	int		k;

	i = 0;
	k = 0;
	total = ft_strlen(src) + ft_strlen(ins);
	rst = (char *)malloc(sizeof(char) * total);
	if (rst == NULL)
		return (NULL);
	rst[total] = '\0';
	while (src[i])
	{
		if (src[i] != c)
		{
			rst[i + k] = src[i];	
		}
		while (src[i] == c && ins[k])
		{
			rst[i + k] = ins[k];
			k++;
		}
		if (src[i] == c)
			k--;
		i++;
	}
	return (&rst[0]);
}
/*
void	types()
{
	/*
		c = char put char
		s = string put str
		i = entero itoa
		p = puntero a imprimir hexadecimal putnumberbase
		x = hexadecimal en minusculas put hexa
		X = hexadecimal en mayusculas put hexa mayusculas
		d = imprime numero decimal put number dec
		u = numero decimal 
		% = imprimir % literal impresion literal.
	
}
int test(char *input)
{
	int i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{

			i++;
		}
	}
}

int ft_printf(const char *str, ...)
{
	va_list	arguments;
	va_start(arguments, str);
}
*/
int main()
{
	int tst;
	void *pnt;

	tst = 55;
	pnt = &pnt;

	ft_str_ins_test("Esta es %c, aqua %i y un numero entero %p hexa %x y HEXA %X.", 'F', 5588, pnt, 241369, 2121365);
	printf("\n %p %x %X.", pnt, 241369, 2121365);
	//printf("%s\n", ft_str_ins("Manuel * Porras Ojeda", "Rafael", '*'));
	return 0;
}