/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:50:12 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/01 23:50:14 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_process_strings(va_list args, t_token *token)
{
	int	rst;

	if (token->token == 'c')
		rst = ft_print_chars((unsigned char)(va_arg(args, int)), token);
	if (token->token == '%')
		rst = ft_print_chars('%', token);
	if (token->token == 's')
		rst = ft_print_strings(va_arg(args, char *), token);
	return (rst + ft_fill_left(token));
}

int	ft_print_strings(char *str, t_token *token)
{
	size_t	len;
	int		fill;
	int		rst;

	if (!str)
		str = "(null)";
	rst = 0;
	len = ft_strlen(str);
	fill = 0;
	if (token->width > 0 && token->left == 0)
		fill = token->width - len;
	if (fill > 0 && token->fill_c == 0)
		token->fill_c = ' ';
	while (fill-- > 0 && token->left == 0)
		rst += write(1, &token->fill_c, 1);
	rst += write(1, str, len);
	token->width = token->width - rst;
	return (rst);
}

int	ft_print_chars(int c, t_token *token)
{
	int		fill;
	int		rst;

	rst = 0;
	fill = 0;
	if (token->width > 0 && token->left == 0)
		fill = token->width - 1;
	if (fill > 0 && token->fill_c == 0)
		token->fill_c = ' ';
	while (fill-- > 0 && token->left == 0)
		rst += write(1, &token->fill_c, 1);
	rst += write(1, &c, 1);
	token->width = token->width - rst;
	return (rst);
}