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

#include "inc/ft_printf_bonus.h"

/**
 * @brief Initializes a new t_token structure with default values.
 *
 * This function allocates memory for a new t_token structure and sets
 * all its attributes to default values, ensuring it's ready to be used
 * in the parsing process.
 *
 * @return Returns a pointer to the initialized t_token structure.
 *         Returns NULL if memory allocation fails.
 */
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

/**
 * @brief Prints spaces to the left based on the token's width.
 *
 * If the left flag is set in the token, this function will print
 * spaces to fill the width specified.
 *
 * @param token Pointer to a structure holding token and its associated flags.
 * @return Returns the number of characters printed.
 */
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

/**
 * @brief Prints padding characters based on the token's flags.
 *
 * Depending on the token's flags and attributes, this function prints
 * padding characters either for width or precision.
 * The `l_r` parameter determines whether it's filling for width (0)
 * or precision (1).
 *
 * @param token Pointer to a structure holding token and its associated flags.
 * @param l_r Integer determining whether to fill for width (0) or precision (1).
 * @return Returns the number of characters printed.
 */
int	ft_width_fill(t_token *token, int l_r)
{
	int	rst;

	rst = 0;
	if (l_r == 0)
	{
		while (token->left == 0 && token->width > 0)
		{
			rst += write(1, &token->fill_c, 1);
			token->width--;
		}
	}
	else
	{
		while (token->precision > 0)
		{
			rst += write(1, "0", 1);
			token->precision--;
		}
	}
	return (rst);
}
