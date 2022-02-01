/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:02:31 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/01 11:02:36 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
*/

int	ft_is_token(int c)
{
	return (c == 'c' || c == 's' || c == 'i' 
			|| c == 'p' || c == 'x' || c == 'X' 
			|| c == 'd' || c == 'u' || c == '%');
}

int	ft_is_flag(int c)
{
	return (c == '#' || c = '+' || c = ' ');
}

int	ft_is_int(int c)
{
	if (c >= 48 && c <= 57)
		return (c - 48);
	else
		return (-1);
}

int	ft_get_token(char *input, va_list arg, int *i)
{
	int	k;

	k = 0;
	
}