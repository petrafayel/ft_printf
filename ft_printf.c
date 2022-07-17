/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:18:18 by rapetros          #+#    #+#             */
/*   Updated: 2022/07/17 16:23:13 by rapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	mondat(va_list ap, const char **str);

int	ft_printf(const char *str, ...)
{
	va_list		ap;

	g_global_count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str != '%')
			ft_putchar(*str);
		else if (*str == '%')
			mondat(ap, &str);
		str++;
	}
	va_end(ap);
	return (g_global_count);
}

void	mondat(va_list ap, const char **str)
{
	(*str)++;
	if (**str == '%')
		ft_putchar('%');
	else if (**str == 'c')
		ft_putchar(va_arg(ap, int));
	else if (**str == 's')
		ft_putstr(va_arg(ap, char *));
	else if (**str == 'i' || **str == 'd')
		ft_putnbr(va_arg(ap, int));
	else if (**str == 'x' || **str == 'X')
		ft_hex(va_arg(ap, int), **str);
	else if (**str == 'p')
	{
		write(1, "0x", 2);
		g_global_count += 2;
		ft_hex_uint(va_arg(ap, uintptr_t));
	}
	else if (**str == 'u')
		ft_unsigned(va_arg(ap, unsigned int));
}
