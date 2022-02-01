/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 10:56:04 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/01 10:56:13 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(char *src, ...)
{
	va_list	args;
	int		i;
	int		rst;

	i = 0;
	va_start(args, src);
	while (src[i])
	{
		if (src[i] == '%')
		{
			i++;
			if (src[i])
				ft_get_token(&src[i], args, &i);
		}
		else
			ft_putchar_fd(src[i], 1);
		i++;
	}
	va_end(args);
	return (rst);
}

int	ft_get_token(char *input, va_list arg, int *i)
{
	int			k;
	t_tokens	*token;

	token = (t_tokens *)malloc(sizeof(token));
	k = 0;
	while (ft_is_token(input[k]) == 0)
	{
		if (ft_is_int(input[k]) != -1)
		{
			if (token->width == -1)
				token->width = ft_is_int(input[k]);
			else
				token->width = (token->width * 10) + ft_is_int(input[k]);
		}
		k++;
	}
	token->token = input[k];
	if (k == 0)
		k = 1;
	*(i) = *(i) + (k - 1);
}
