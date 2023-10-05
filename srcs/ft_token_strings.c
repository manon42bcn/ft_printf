/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:50:12 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/08 22:51:14 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 * @brief Prints a string to the standard output.
 *
 * This function handles printing of strings. If the provided string is NULL,
 * it prints "(null)" instead.
 *
 * @param str The string to be printed. If NULL, "(null)" will be printed.
 * @return Returns the number of characters printed.
 */
static int	ft_print_strings(char *str)
{
	int		len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	return (write(1, str, len));
}

/**
 * @brief Prints a single character to the standard output.
 *
 * This function handles the printing of a single character.
 *
 * @param c The character to be printed.
 * @return Returns the number of characters printed.
 */
static int	ft_print_chars(int c)
{
	return (write(1, &c, 1));
}

/**
 * @brief Processes and prints string and character types for printf.
 *
 * This function handles the printing of string and character type
 * tokens (c, s, %)
 * based on the passed token and the data from the variable argument list.
 *
 * @param args The variable argument list containing the data.
 * @param token The token character representing the data type.
 * @return Returns the number of characters printed.
 */
int	ft_process_strings(va_list args, char token)
{
	int	rst;

	if (token == 'c')
		rst = ft_print_chars((unsigned char)(va_arg(args, int)));
	if (token == '%')
		rst = ft_print_chars('%');
	if (token == 's')
		rst = ft_print_strings(va_arg(args, char *));
	return (rst);
}
