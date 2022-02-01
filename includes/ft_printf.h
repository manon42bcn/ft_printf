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
	char	token;
	int		width;
	char	fill_char;
	int		format;

}	t_token;

/* MAIN */
int	ft_get_token(char *input, int *i);
/* INPUTS */
int	ft_is_token(int c);
int	ft_is_flag(int c);
int	ft_is_int(int c);
/* HEXA */
int ft_process_hexa(va_list arg, t_token *token);
int ft_print_hexa(unsigned long nbr, char *base, t_token *token);

#endif
