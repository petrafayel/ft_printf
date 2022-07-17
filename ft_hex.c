/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:16:06 by rapetros          #+#    #+#             */
/*   Updated: 2022/07/17 16:16:08 by rapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex(unsigned int nb, char c)
{
	if (nb < 10)
		ft_putchar(nb + 48);
	else if (nb < 16)
	{
		if (c == 'X')
			ft_putchar(nb + 55);
		else if (c == 'x')
			ft_putchar(nb + 87);
	}
	else
	{
		ft_hex(nb / 16, c);
		ft_hex(nb % 16, c);
	}
}
