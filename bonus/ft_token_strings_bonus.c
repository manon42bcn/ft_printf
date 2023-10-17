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

#include "ft_printf_bonus.h"

/**
 * @brief Determines the length of the string to be printed.
 *
 * Depending on the token's flags and the string's length, this function
 * decides the length of the string that will be printed.
 *
 * @param str The string to be printed.
 * @param token Pointer to a structure holding token and its associated flags.
 * @return Returns the number of characters to be printed.
 */
static int	ft_len_to_print(char *str, t_token *token)
{
	int	len;

	len = ft_strlen(str);
	if (token->point == 0 || len < token->precision)
		return (len);
	if (len > token->precision)
		return (token->precision);
	else
		return (len);
}

/**
 * @brief Formats and prints a string.
 *
 * This function takes into account various flags set in the token,
 * such as width, and prints the string accordingly.
 *
 * @param str The string to be printed.
 * @param token Pointer to a structure holding token and its associated flags.
 * @return Returns the number of characters printed.
 */
static int	ft_print_strings(char *str, t_token *token)
{
	int		len;
	int		fill;
	int		rst;

	if (!str)
		str = "(null)";
	len = ft_len_to_print(str, token);
	rst = 0;
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

/**
 * @brief Formats and prints a character.
 *
 * Depending on the token's flags, such as width, this function formats and
 * prints the given character accordingly.
 *
 * @param c The character to be printed.
 * @param token Pointer to a structure holding token and its associated flags.
 * @return Returns the number of characters printed.
 */
static int	ft_print_chars(int c, t_token *token)
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

/**
 * @brief Processes and prints a string or character based on the token.
 *
 * This function identifies the type of string format (c, %, s) and calls
 * the appropriate printing functions.
 *
 * @param args The variable argument list containing the data.
 * @param token Pointer to a structure holding token and its associated flags.
 * @return Returns the number of characters printed.
 */
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
