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

#include <unistd.h>

int ft_process_hexa(va_list arg, t_flags flags, char c)
{
	int	rst;

	if((!flags || flags->format == 0) && c != 'p')
	{
		if (c == 'x')
			rst = ft_print_hexa((unsigned long)input, "0123456789abcdef");
		else
			rst = ft_print_hexa(input, "0123456789ABCDEF");
	}
	else
	{
		rst = write(1, "0x", 2);
		if (c == 'x')
			rst += ft_print_hexa((unsigned long)input, "0123456789abcdef");
		else if (c == 'p')
			rst += ft_print_hexa(input, "0123456789abcdef");
		else
			rst += ft_print_hexa((unsigned long)input, "0123456789ABCDEF");
	}
	return (rst);
}

int ft_print_hexa(unsigned long nbr, char *base, int spc, char c)
{
    int     base_num;
    int     fill;

    base_num = 16;
    fill = 0;
    if (nbr > base_num)
        return (ft_print_hexa(nbr / base_num, base, (spc - 1), c) + write(1, &base[nbr % base_num], 1));
    else
    {
        if (spc > 0)
        {
            while (--spc > 0)
                fill += write(1, &c, 1);
        }
        return (write(1, &base[nbr], 1));
    }
}
