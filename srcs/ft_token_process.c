/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 01:55:20 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/05 01:55:25 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 * @brief Determines if the given character is a valid token.
 *
 * This function checks if the character passed is a recognized token
 * that can be processed by the printf function.
 *
 * @param c The character to check.
 * @return Returns 1 if the character is a recognized token, otherwise returns 0.
 */
static int	ft_is_token(int c)
{
	return (c == 'c' || c == 's' || c == 'i'
		|| c == 'p' || c == 'x' || c == 'X'
		|| c == 'd' || c == 'u' || c == '%');
}

/**
 * @brief Process the given token and prints the corresponding formatted output.
 *
 * Based on the token given, the appropriate formatting function is called
 * to handle and print the data from the variable argument list.
 *
 * @param token The token character representing the data type.
 * @param args The variable argument list containing the data.
 * @return Returns the number of characters printed.
 */
static int	ft_process_tokens(char token, va_list args)
{
	int	rst;

	rst = 0;
	if (token == 'p' || token == 'x' || token == 'X')
		rst = ft_process_hexa(args, token);
	if (token == 'c' || token == 's' || token == '%')
		rst = ft_process_strings(args, token);
	if (token == 'd' || token == 'i' || token == 'u')
		rst = ft_process_numbers(args, token);
	return (rst);
}

/**
 * @brief Converts the input character into a valid token and processes it.
 *
 * This function first checks if the input character is a valid token.
 * If valid, the character is processed and the data is printed.
 *
 * @param input Pointer to the input character to be checked and processed.
 * @param args The variable argument list containing the data.
 * @param i Pointer to an integer that indicates the current position in
 *          the input string.
 * @return Returns the number of characters printed.
 */
int	ft_input_to_tokens(const char *input, va_list args, int *i)
{
	int		rst;

	if (ft_is_token(input[0]) == 1)
	{
		*(i) = *(i) + 1;
		rst = ft_process_tokens(input[0], args);
	}
	else
		rst = 0;
	return (rst);
}
