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

int	ft_is_token(int c)
{
	return (c == 'c' || c == 's' || c == 'i'
		|| c == 'p' || c == 'x' || c == 'X'
		|| c == 'd' || c == 'u' || c == '%');
}

int	ft_is_flag(int c)
{
	return (c == '#' || c == '+' || c == ' '
		|| c == '-' || c == '.' || c == '*'
		|| (c >= '0' && c <= '9'));
}

int	ft_flag_with_values(int c)
{
	return (c == ' ' || c == '-' || c == '.' || (c >= '0' && c <= '9'));
}

int	ft_is_width_flag(int c)
{
	return (c == ' ' || c == '0' || c == '-');
}

int	ft_is_int(int c)
{
	if (c >= 48 && c <= 57)
		return (c - 48);
	else
		return (-1);
}
