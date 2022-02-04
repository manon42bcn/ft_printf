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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

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

}	t_token;

/* MAIN */
int				ft_printf(const char *src, ...);
int				ft_input_to_tokens(const char *input, va_list args, int *i);
int				ft_process_tokens(t_token *token, va_list args);
t_token			*ft_start_token(void);
void			ft_free_token(t_token *token);
int				ft_fill_left(t_token *token);
size_t			ft_strlen(const char *s);
int				ft_is_token(int c);
int				ft_is_flag(int c);
int				ft_is_int(int c);
int				ft_flag_with_values(int c);
int				ft_process_hexa(va_list arg, t_token *token);
int				ft_hexa_left(t_token *token);
int				ft_print_format_hexa(t_token *token, char *base, char num);
int				ft_print_hexa(unsigned long nbr, char *base, t_token *token);
int				ft_process_strings(va_list args, t_token *token);
int				ft_print_strings(char *str, t_token *token);
int				ft_print_chars(int c, t_token *token);
int				ft_process_numbers(va_list args, t_token *token);
int				ft_print_int(long int nbr, t_token *token);
int				ft_print_format_number(t_token *token, char num);
int				ft_print_double(double nbr, t_token *token);
unsigned int	ft_power_ten(int n);
#endif
