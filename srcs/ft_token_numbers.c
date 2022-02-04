/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:15:45 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/01 14:15:47 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_process_numbers(va_list args, t_token *token)
{
	int	rst;

	rst = 0;

	if (token->token == 'i' || token->token == 'd')
		rst += ft_print_int((long int)(va_arg(args, int)), token);
	if (token->token == 'u')
		rst += ft_print_int((long int)(va_arg(args, unsigned int)), token);
	if (token->token == 'f')
		rst += ft_print_double(va_arg(args, double), token);
	return (rst + ft_fill_left(token));
}

int	ft_print_double(double nbr, t_token *token)
{
	long int	whole;
	long int	decimals;
	int			rst;
	t_token		*ratio;	

	whole = (long int)nbr;
	nbr = nbr - whole;
	decimals = nbr * ft_power_ten(token->precision + 1);
	if ((decimals % 10) >= 5)
		decimals = (decimals / 10) + 1;
	else
		decimals = decimals / 10;
	rst = 0;
	token->width = token->width - token->precision - 1;
	rst += ft_print_int(whole, token);
	rst += write(1, ".", 1);
	ratio = ft_start_token();
	ratio->width = token->precision;
	ratio->fill_c = '0';
	rst += ft_print_int(decimals, ratio);
	free(ratio);
	return (rst);
}

int	ft_print_int(long int nbr, t_token *token)
{
	char	c;

	if (nbr == 0 && token->point == 1 && token->precision == 0)
		return (0);
	if (nbr < 0)
	{
		token->sign = -1;
		nbr = nbr * -1;
	}
	c = (nbr % 10) + '0';
	if (nbr >= 10)
	{
		token->precision = token->precision - 1;
		token->width = token->width - 1;
		return (ft_print_int(nbr / 10, token)
			+ write(1, &c, 1));
	}
	else
		return (ft_print_format_number(token, c));
}

int	ft_print_format_number(t_token *token, char num)
{
	int	rst;

	rst = 0;
	if (token->fill_c == 0)
		token->fill_c = ' ';
	if ((token->sign == -1 || token->sign == 1) && token->point == 0)
		token->width = token->width - 1;
	if (token->point == 1 && token->precision > 0)
		token->width = token->width - token->precision;
	if (token->sign == -1 && token->fill_c != ' ')
		rst += write(1, "-", 1);
	if (token->sign == 1 && token->fill_c != ' ')
		rst += write(1, "+", 1);
	while (token->left == 0 && --token->width > 0 )
		rst += write(1, &token->fill_c, 1);
	if (token->sign == -1 && token->fill_c == ' ')
		rst += write(1, "-", 1);
	if (token->sign == 1 && token->fill_c == ' ')
		rst += write(1, "+", 1);
	while (--token->precision > 0)
		rst += write(1, "0", 1);
	rst += write(1, &num, 1);
	return (rst);
}
