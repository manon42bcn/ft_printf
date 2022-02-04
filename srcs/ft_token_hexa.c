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

int	ft_process_hexa(va_list args, t_token *token)
{
	int	rst;

	rst = 0;
	if ((!token || token->hash == 0) && token->token != 'p')
	{
		if (token->token == 'x')
			rst = ft_print_hexa(va_arg(args, unsigned int),
					"0123456789abcdef0x", token);
		else
			rst = ft_print_hexa(va_arg(args, unsigned int),
					"0123456789ABCDEF0X", token);
	}
	else
	{
		if (token->token == 'x')
			rst += ft_print_hexa(va_arg(args, unsigned int),
					"0123456789abcdef0x", token);
		else if (token->token == 'p')
			rst += ft_print_hexa(va_arg(args, unsigned long),
					"0123456789abcdef0x", token);
		else
			rst += ft_print_hexa(va_arg(args, unsigned int),
					"0123456789ABCDEF0X", token);
	}
	return (rst + ft_fill_left(token));
}

int	ft_print_format_hexa(t_token *token, char *base, char num)
{
	int	rst;

	rst = 0;
	if (token->hash == 1)
		token->width = token->width - 2;
	if (token->point == 1 && token->precision > 0)
		token->width = token->width - token->precision;
	if (token->hash == 1 && token->width > 0 && token->fill_c == '0')
		rst += write(1, &base[16], 1) + write(1, &base[17], 1);
	while (token->width-- > 1 && token->left == 0)
		rst += write(1, &token->fill_c, 1);
	if (token->hash == 1 && (token->left == 1 || token->width < 1))
		rst += write(1, &base[16], 1) + write(1, &base[17], 1);
	while (--token->precision > 0)
		rst += write(1, "0", 1);
	rst += write(1, &num, 1);
	return (rst);
}

int	ft_print_hexa(unsigned long nbr, char *base, t_token *token)
{
	unsigned long	base_num;

	if (nbr == 0 && token->point == 1 && token->precision == 0)
		return (0);
	base_num = 16;
	if (nbr == 0 && token->token != 'p' && token->point == 0)
		return (write(1, "0", 1));
	if (nbr >= base_num)
	{
		token->precision = token->precision - 1;
		token->width = token->width - 1;
		return (ft_print_hexa(nbr / base_num, base, token)
			+ write(1, &base[nbr % base_num], 1));
	}
	else
		return (ft_print_format_hexa(token, base, base[nbr]));
}
