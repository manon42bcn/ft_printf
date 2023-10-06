/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 10:59:56 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/01 11:00:04 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../../libft/inc/libft.h"

/**
 * @struct t_token
 * @brief Represents a format token and its properties for ft_printf.
 *
 * This struct encapsulates properties and flags of a format specifier
 * used in the custom printf function. It aids in output formatting.
 *
 * @var t_token::token
 * Character for the format specifier (e.g., 'd', 's', 'x', etc.).
 *
 * @var t_token::fill_c
 * Character for padding, either space (' ') or zero ('0').
 *
 * @var t_token::width
 * Minimum width of the field. Padded with fill_c if value is shorter.
 *
 * @var t_token::hash
 * Flag for '#' specifier for an alternative form.
 *
 * @var t_token::sign
 * Specifies the sign: positive (+1), negative (-1), or neutral (0).
 *
 * @var t_token::left
 * Flag for left-justification with '-' specifier.
 *
 * @var t_token::point
 * Indicates presence of '.' to specify precision.
 *
 * @var t_token::precision
 * Number of digits after the decimal for floats or limit for strings.
 *
 * @var t_token::space
 * Flag for space insertion before value when there's no sign.
 */
typedef struct s_token
{
	int	token;
	int	fill_c;
	int	width;
	int	hash;
	int	sign;
	int	left;
	int	point;
	int	precision;
	int	space;

}	t_token;

int		ft_printf(const char *s, ...);
int		ft_process_tokens(t_token *token, va_list args);
void	ft_fix_flags_conditions(t_token	*token);
int		ft_get_token_sizes(const char *input, t_token *token);
int		ft_get_tokens(const char *input, t_token *token);
int		ft_input_to_tokens(const char *input, va_list args, int *i);
t_token	*ft_start_token(void);
void	ft_free_token(t_token *token);
int		ft_fill_left(t_token *token);
int		ft_is_token(int c);
int		ft_is_flag(int c);
int		ft_width_fill(t_token *token, int l_r);
int		ft_flag_with_values(int c);
int		ft_is_width_flag(int c);
int		ft_process_hexa(va_list arg, t_token *token);
int		ft_process_strings(va_list args, t_token *token);
int		ft_process_numbers(va_list args, t_token *token);

#endif
