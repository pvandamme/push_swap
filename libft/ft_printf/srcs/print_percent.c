/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:57:21 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/28 17:57:35 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_percent(va_list ap, t_flags flags)
{
	int	length;

	length = 1;
	if (ap)
	{
		while (flags.field_width > 1 && !flags.minus)
		{
			if (flags.zero)
				ft_putchar('0');
			else
				ft_putchar(' ');
			flags.field_width--;
			length++;
		}
	}
	ft_putchar('%');
	while (flags.field_width > 1 && flags.minus)
	{
		ft_putchar(' ');
		flags.field_width--;
		length++;
	}
	return (length);
}
