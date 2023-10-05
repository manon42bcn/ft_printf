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

#include "../includes/ft_printf_bonus.h"

/**
 * @brief Process the given token and print the corresponding formatted output.
 *
 * Based on the provided token, the appropriate formatting function is called
 * to handle and print the data from the variable argument list.
 *
 * @param token Pointer to a structure holding token and its associated flags.
 * @param args The variable argument list containing the data.
 * @return Returns the number of characters printed.
 */
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

/**
 * @brief Adjusts the flags of a given token based on specific conditions.
 *
 * Sets or modifies the flags of a token to match specific conditions and
 * formatting requirements of the printf function.
 *
 * @param token Pointer to a structure holding token and its associated flags.
 */
void	ft_fix_flags_conditions(t_token	*token)
{
	if (token->fill_c == ' ' && token->width == 0)
		token->space = 1;
	if (token->fill_c == 0 || token->point == 1)
		token->fill_c = ' ';
	if (token->token == 'p')
		token->hash = 1;
	if ((token->token == 'x' || token->token == 'X') && token->fill_c == 0)
		token->fill_c = '0';
}

/**
 * @brief Determines the sizes associated with width and precision flags.
 *
 * Computes the sizes for width and precision based on the format string and
 * updates the token's attributes accordingly.
 *
 * @param input Pointer to the current position in the format string.
 * @param token Pointer to a structure holding token and its associated flags.
 * @return Returns the number of characters parsed in the input.
 */
int	ft_get_token_sizes(const char *input, t_token *token)
{
	int	i;

	i = 0;
	while (input[0] == '.' && input[++i] && ft_isdigit(input[i]) == 1)
		token->precision = (token->precision * 10) + (input[i] - 48);
	while (ft_is_width_flag(input[0]) == 1 && input[++i]
		&& ft_isdigit(input[i]) == 1)
		token->width = (token->width * 10) + (input[i] - 48);
	while (input[i] && ft_isdigit(input[i]) == 1)
	{
		token->width = (token->width * 10) + (input[i] - 48);
		i++;
	}
	if (i > 0)
		i--;
	return (i);
}

/**
 * @brief Extracts and sets flags and attributes for a given token.
 *
 * Processes the format string to set flags and attributes for a token,
 * based on recognized characters and sequences.
 *
 * @param input Pointer to the current position in the format string.
 * @param token Pointer to a structure holding token and its associated flags.
 * @return Returns the number of characters parsed in the input.
 */
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

/**
 * @brief Converts the input characters into valid tokens and processes them.
 *
 * This function first checks if the input character is a valid token or flag.
 * If valid, the character or sequence is processed and the data is printed.
 *
 * @param input Pointer to the current position in the format string.
 * @param args The variable argument list containing the data.
 * @param i Pointer to an integer that indicates the current position in
 *          the input string.
 * @return Returns the number of characters printed.
 */
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
	ft_fix_flags_conditions(token);
	*(i) = *(i) + k;
	rst = ft_process_tokens(token, args);
	free(token);
	return (rst);
}
