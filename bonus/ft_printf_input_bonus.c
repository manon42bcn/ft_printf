/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:02:31 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/01 11:02:36 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Determines if the given character is a valid token.
 *
 * This function checks if the character passed is a recognized token
 * that can be processed by the printf function.
 *
 * @param c The character to check.
 * @return Returns 1 if the character is a recognized token, otherwise returns 0.
 */
int	ft_is_token(int c)
{
	return (c == 'c' || c == 's' || c == 'i'
		|| c == 'p' || c == 'x' || c == 'X'
		|| c == 'd' || c == 'u' || c == '%');
}

/**
 * @brief Determines if the given character is a valid flag.
 *
 * This function checks if the character passed is a recognized flag used
 * for formatting in the printf function. Flags are characters that precede
 * a token and modify its behavior or representation.
 *
 * @param c The character to check.
 * @return Returns 1 if the character is a recognized flag, otherwise returns 0.
 */
int	ft_is_flag(int c)
{
	return (c == '#' || c == '+' || c == ' '
		|| c == '-' || c == '.' || c == '*'
		|| (c >= '0' && c <= '9'));
}

/**
 * @brief Determines if the given flag can have an associated value.
 *
 * Certain flags can be followed by values to further specify their behavior.
 * This function identifies such flags.
 *
 * @param c The character to check.
 * @return Returns 1 if the character is a flag that can have an associated
 * value, otherwise returns 0.
 */
int	ft_flag_with_values(int c)
{
	return (c == ' ' || c == '-' || c == '.' || (c >= '0' && c <= '9'));
}

/**
 * @brief Determines if the given character is a width flag.
 *
 * Width flags are used to specify the minimum number of characters to be
 * printed. If the value to be printed is shorter than this number,
 * the result is padded.
 * This function identifies such flags.
 *
 * @param c The character to check.
 * @return Returns 1 if the character is a recognized width flag,
 * otherwise returns 0.
 */
int	ft_is_width_flag(int c)
{
	return (c == ' ' || c == '0' || c == '-');
}
