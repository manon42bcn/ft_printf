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
