/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:28:19 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/02 23:11:25 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_token	*ft_start_token(void)
{
	t_token	*rst;

	rst = (t_token *)malloc(sizeof(t_token));
	if (rst == NULL)
		return (NULL);
	rst->token = 0;
	rst->fill_c = 0;
	rst->width = 0;
	rst->hash = 0;
	rst->sign = 0;
	rst->left = 0;
	rst->point = 0;
	rst->precision = 0;
	rst->space = 0;
	return (rst);
}

int	ft_fill_left(t_token *token)
{
	int	rst;

	rst = 0;
	if (token->left == 1 && token->width > 0)
	{
		while (token->width > 0)
		{
			rst += write(1, " ", 1);
			token->width--;
		}
	}
	return (rst);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}