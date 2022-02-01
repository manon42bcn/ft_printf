/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:01:48 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/01 12:01:54 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_process_hexa(va_list arg, t_token *token)
{
	int	rst;

	if ((!token || token->format == 0) && token->token != 'p')
	{
		if (token->token == 'x')
			rst = ft_print_hexa(va_arg(args, unsigned int),
					"0123456789abcdef", token);
		else
			rst = ft_print_hexa(va_arg(args, unsigned long),
					"0123456789ABCDEF", token);
	}
	else
	{
		rst = write(1, "0x", 2);
		if (token->token == 'x')
			rst += ft_print_hexa(va_arg(args, unsigned int),
					"0123456789abcdef", token);
		else if (token->token == 'p')
			rst += ft_print_hexa(va_arg(args, unsigned long),
					"0123456789abcdef", token);
		else
			rst += ft_print_hexa(va_arg(args, unsigned int),
					"0123456789ABCDEF", token);
	}
	return (rst);
}

int	ft_print_hexa(unsigned long nbr, char *base, t_token *token)
{
	int	base_num;
	int	fill;

	base_num = 16;
	fill = 0;
	if (nbr > base_num)
	{
		token->width = token->width - 1;
		return (ft_print_hexa(nbr / base_num, base, token)
			+ write(1, &base[nbr % base_num], 1));
	}
	else
	{
		if (token->width > 0)
		{
			while (--token->width > 0)
				fill += write(1, &token->fill_char, 1);
		}
		return (write(1, &base[nbr], 1) + fill);
	}
}
