/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 10:56:04 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/03 13:12:40 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *src, ...)
{
	va_list	args;
	int		i;
	int		rst;

	i = 0;
	rst = 0;
	va_start(args, src);
	while (src[i])
	{
		if (src[i] == '%' && src[i + 1])
		{
			i++;
			rst += ft_input_to_tokens(&src[i], args, &i);
			continue ;
		}
		if (!src[i])
			break ;
		rst += write(1, &src[i], 1);
		i++;
	}
	va_end(args);
	return (rst);
}

int	ft_get_token_sizes(const char *input, t_token *token)
{
	int	i;

	i = 0;
	if (input[0] == '.' && input[1] && ft_is_int(input[1]) != -1)
	{
		while (input[++i] && ft_is_int(input[i]) != -1)
			token->precision = (token->precision * 10) + (input[i] - 48);
	}
	else if ((input[0] == '-' || input[0] == ' ' || input[0] == '0')
		&& (input[1] && ft_is_int(input[1]) != -1))
	{
		while (input[++i] && ft_is_int(input[i]) != -1)
			token->width = (token->width * 10) + (input[i] - 48);
	}
	else if (ft_is_int(input[0]) != -1)
	{
		while (input[i] && ft_is_int(input[i]) != -1)
		{
			token->width = (token->width * 10) + (input[i] - 48);
			i++;
		}
	}
	if (i > 0)
		i--;
	return (i);
}

int	ft_get_tokens(const char *input, t_token *token)
{
	int		k;

	k = 0;
	while (input[k] && ft_is_flag(input[k]) == 1)
	{
		if (input[k] == '-')
			token->left = 1;
		if (input[k] == '.')
			token->point = 1;
		if (input[k] == ' ' || input[k] == '0')
			token->fill_c = input[k];
		if (ft_flag_with_values(input[k]) == 1)
			k += ft_get_token_sizes(&input[k], token);
		if (input[k] == '#')
			token->hash = 1;
		if (input[k] == '+')
			token->sign = 1;
		k++;
	}
	if (ft_is_token(input[k]) == 1)
	{
		token->token = input[k];
		k++;
	}
	return (k);
}

int	ft_input_to_tokens(const char *input, va_list args, int *i)
{
	t_token	*token;
	int		k;
	int		rst;

	if (input[0] == '%')
	{
		*(i) = *(i) + 1;
		return (write(1, "%", 1));
	}
	token = ft_start_token();
	k = ft_get_tokens(input, token);
	*(i) = *(i) + k;
	if (token->width != 0 && token->fill_c == 0)
		token->fill_c = ' ';
	if (token->token == 'p')
		token->hash = 1;
	rst = ft_process_tokens(token, args);
	free(token);
	return (rst);
}

int	ft_process_tokens(t_token *token, va_list args)
{
	int	rst;

	rst = 0;
	if (token->token == 'p' || token->token == 'x' || token->token == 'X')
		rst = ft_process_hexa(args, token);
	if (token->token == 'c' || token->token == 's' || token->token == '%')
		rst = ft_process_strings(args, token);
	if (token->token == 'd' || token->token == 'i' || token->token == 'u')
		rst = ft_process_numbers(args, token);
	return (rst);
}
