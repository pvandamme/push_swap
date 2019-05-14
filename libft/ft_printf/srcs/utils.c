/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:46:31 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/29 19:46:45 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_minus(int length, t_flags flags)
{
	int tmp;

	tmp = length;
	while (flags.field_width > tmp)
	{
		ft_putchar(' ');
		flags.field_width--;
		length++;
	}
	return (length);
}

int	fill_struct(const char *format, t_flags *flags)
{
	int	i;
	int nb;

	i = 0;
	nb = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			i = fill_option(format, flags, i, nb);
			i = fill_field_width(format, flags, i, nb);
			flags[nb].width = -1;
			i = fill_precision(format, flags, i, nb);
			i = fill_width(format, flags, i, nb);
			if (!(i = fill_conv(format, flags, i, nb)))
			{
				free(flags);
				return (0);
			}
			nb++;
		}
		i++;
	}
	return (i);
}
