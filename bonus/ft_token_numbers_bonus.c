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

#include "ft_printf_bonus.h"

/**
 * @brief Formats and prints a number with appropriate flags.
 *
 * This function takes into account various flags set in the token,
 * such as width, precision, and the sign, and prints the number accordingly.
 *
 * @param token Pointer to a structure holding token and its associated flags.
 * @param num The number character to be printed.
 * @return Returns the number of characters printed.
 */
static int	ft_print_format_number(t_token *token, char num)
{
	int	rst;

	rst = 0;
	if (token->point == 1 && token->precision > 0)
		token->width = token->width - token->precision;
	if (token->sign == -1 && token->fill_c != ' ')
		rst += write(1, "-", 1);
	if (token->sign == 1 && token->fill_c != ' ')
		rst += write(1, "+", 1);
	rst += ft_width_fill(token, 0);
	if (token->sign == -1 && token->fill_c == ' ')
		rst += write(1, "-", 1);
	if (token->sign == 1 && token->fill_c == ' ')
		rst += write(1, "+", 1);
	rst += ft_width_fill(token, 1);
	if (token->space == 1)
		rst += write(1, " ", 1);
	if (num != 0)
		rst += write(1, &num, 1);
	return (rst);
}

/**
 * @brief Recursive function to print a number in decimal format.
 *
 * This function breaks down the number into its individual decimal characters
 * and prints them, taking the token's flags into consideration.
 *
 * @param nbr The number to be printed in decimal format.
 * @param token Pointer to a structure holding token and its associated flags.
 * @return Returns the number of characters printed.
 */
static int	ft_print_int(long int nbr, t_token *token)
{
	char	c;

	c = (nbr % 10) + '0';
	token->precision--;
	token->width--;
	if (nbr >= 10)
		return (ft_print_int(nbr / 10, token)
			+ write(1, &c, 1));
	else
		return (ft_print_format_number(token, c));
}

/**
 * @brief Determines how to print the number based on the token and value.
 *
 * Depending on the token's flags and the value to be printed, this function
 * decides the appropriate format and calls the necessary functions.
 *
 * @param nbr The number to be printed.
 * @param token Pointer to a structure holding token and its associated flags.
 * @return Returns the number of characters printed.
 */
static int	ft_print_number_cases(long int nbr, t_token *token)
{
	if (nbr == 0 && token->point == 1)
	{
		token->fill_c = ' ';
		return (ft_print_format_number(token, 0));
	}
	else
	{
		if (nbr > 0 && token->sign == 1)
			token->width--;
		if (nbr < 0)
		{
			token->sign = -1;
			token->space = 0;
			token->width--;
			nbr = nbr * -1;
		}
		return (ft_print_int(nbr, token));
	}
}

/**
 * @brief Processes and prints a number in its appropriate format.
 *
 * This function identifies the type of number format (i, d, u) and calls
 * the appropriate printing functions.
 *
 * @param args The variable argument list containing the data.
 * @param token Pointer to a structure holding token and its associated flags.
 * @return Returns the number of characters printed.
 */
int	ft_process_numbers(va_list args, t_token *token)
{
	int	rst;

	rst = 0;
	if (token->token == 'i' || token->token == 'd')
		rst += ft_print_number_cases((long int)(va_arg(args, int)), token);
	if (token->token == 'u')
		rst += ft_print_number_cases((long int)
				(va_arg(args, unsigned int)), token);
	return (rst + ft_fill_left(token));
}
