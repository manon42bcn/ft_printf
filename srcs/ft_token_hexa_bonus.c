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

#include "../includes/ft_printf_bonus.h"

/**
 * @brief Formats and prints a hexadecimal character.
 *
 * This function takes into account various flags set in the token, such as
 * width, precision, and the hash flag, and prints the hexadecimal character
 * accordingly.
 *
 * @param token Pointer to a structure holding token and its associated flags.
 * @param base String representing the characters used in hexa representation.
 * @param num The hexadecimal character to be printed.
 * @return Returns the number of characters printed.
 */
static int	ft_print_format_hexa(t_token *token, char *base, char num)
{
	int	rst;

	rst = 0;
	if (token->hash == 1)
		token->width = token->width - 2;
	if (token->point == 1 && token->precision > 0)
		token->width = token->width - token->precision;
	if (token->hash == 1 && token->width > 0 && token->fill_c == '0')
		rst += write(1, &base[16], 1) + write(1, &base[17], 1);
	rst += ft_width_fill(token, 0);
	if (token->hash == 1 && (token->left == 1 || token->width < 1))
		rst += write(1, &base[16], 1) + write(1, &base[17], 1);
	rst += ft_width_fill(token, 1);
	if (token->space == 1)
		rst += write(1, " ", 1);
	if (num != 0)
		rst += write(1, &num, 1);
	return (rst);
}

/**
 * @brief Recursive function to print a number in hexadecimal format.
 *
 * This function breaks down the number into its individual hexa characters
 * and prints them, taking the token's flags into consideration.
 *
 * @param nbr The number to be printed in hexadecimal format.
 * @param base String representing the characters used in hexa representation.
 * @param token Pointer to a structure holding token and its associated flags.
 * @return Returns the number of characters printed.
 */
static int	ft_print_hexa(unsigned long nbr, char *base, t_token *token)
{
	unsigned long	base_num;

	token->width--;
	token->precision--;
	base_num = 16;
	if (nbr >= base_num)
		return (ft_print_hexa(nbr / base_num, base, token)
			+ write(1, &base[nbr % base_num], 1));
	else
		return (ft_print_format_hexa(token, base, base[nbr]));
}

/**
 * @brief Determines how to print the hexadecimal based on the token and value.
 *
 * Depending on the token's flags and the value to be printed, this function
 * decides the appropriate format and calls the necessary functions.
 *
 * @param nbr The number to be printed.
 * @param base String representing the characters used in hexa representation.
 * @param token Pointer to a structure holding token and its associated flags.
 * @return Returns the number of characters printed.
 */
static int	ft_print_hexa_cases(unsigned long nbr, char *base, t_token *token)
{
	if (token->token != 'p' && nbr == 0 && token->hash == 1)
		token->hash = 0;
	if (nbr == 0 && token->token != 'p' && token->point == 1)
		return (ft_print_format_hexa(token, base, 0));
	else
		return (ft_print_hexa(nbr, base, token));
}

/**
 * @brief Processes and prints hexadecimal format based on the given token.
 *
 * This function identifies the type of hexadecimal format (p, x, X) and calls
 * the appropriate printing functions.
 *
 * @param args The variable argument list containing the data.
 * @param token Pointer to a structure holding token and its associated flags.
 * @return Returns the number of characters printed.
 */
int	ft_process_hexa(va_list args, t_token *token)
{
	int	rst;

	rst = 0;
	if (token->token == 'p')
		rst += ft_print_hexa_cases(va_arg(args, unsigned long),
				"0123456789abcdef0x", token);
	else if (token->token == 'x')
		rst = ft_print_hexa_cases(va_arg(args, unsigned int),
				"0123456789abcdef0x", token);
	else if (token->token == 'X')
		rst = ft_print_hexa_cases(va_arg(args, unsigned int),
				"0123456789ABCDEF0X", token);
	return (rst + ft_fill_left(token));
}
