/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:19:22 by rapetros          #+#    #+#             */
/*   Updated: 2022/07/17 16:19:23 by rapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned(unsigned int nb)
{
	if (nb < 10)
		ft_putchar(nb + 48);
	else
	{
		ft_unsigned(nb / 10);
		ft_unsigned(nb % 10);
	}
}
