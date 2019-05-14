/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:49:32 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/27 12:50:59 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int		print_c(va_list ap, t_flags flags)
{
	char	c;
	int		length;

	length = 1;
	c = (char)va_arg(ap, int);
	while (flags.field_width > 1 && !flags.minus)
	{
		ft_putchar(' ');
		flags.field_width--;
		length++;
	}
	write(1, &c, 1);
	while (flags.field_width > 1 && flags.minus)
	{
		ft_putchar(' ');
		flags.field_width--;
		length++;
	}
	return (length);
}
