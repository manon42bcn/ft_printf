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

int	ft_print_int(int nbr, t_token *token)
{
	if (nbr > 10)
		return (ft_print_int(nbr / base_num, token)
			+ write(1, &base[nbr % base_num], 1));
	else
		return (write(1, &base[nbr], 1));
}
