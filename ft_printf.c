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

typedef struct s_arg
{
	
	s_arg *next;
}	t_arg;

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
		p = puntero a imprimir hexadecimal putnumberbase
		d = imprime numero decimal put number dec
		i = entero atoi
		u = numero decimal 
		x = hexadecimal en minusculas put hexa
		X = hexadecimal en mayusculas put hexa mayusculas
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
	
	printf("%s\n", ft_str_ins("Manuel * Porras Ojeda", "Rafael", '*'));
	return 0;
}