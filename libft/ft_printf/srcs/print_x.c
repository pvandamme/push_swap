/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:15:54 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/29 16:41:18 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_x(va_list ap, t_flags flags)
{
	int				length;
	unsigned int	n;

	length = 0;
	n = va_arg(ap, unsigned int);
	length = print_x_option((unsigned long long)n, flags);
	if (flags.precision != -1 || (flags.precision == -1 && n > 0))
		print_hex((unsigned long long)n);
	if (flags.minus)
		length = print_minus(length, flags);
	return (length);
}

int		print_hx(va_list ap, t_flags flags)
{
	int				length;
	unsigned short	n;

	length = 0;
	n = (short)va_arg(ap, unsigned int);
	length = print_x_option((unsigned long long)n, flags);
	if (flags.precision != -1 || (flags.precision == -1 && n > 0))
		print_hex((unsigned long long)n);
	if (flags.minus)
		length = print_minus(length, flags);
	return (length);
}

int		print_hhx(va_list ap, t_flags flags)
{
	int				length;
	unsigned char	n;

	length = 0;
	n = (char)va_arg(ap, unsigned int);
	length = print_x_option((unsigned long long)n, flags);
	if (flags.precision != -1 || (flags.precision == -1 && n > 0))
		print_hex((unsigned long long)n);
	if (flags.minus)
		length = print_minus(length, flags);
	return (length);
}

int		print_lx(va_list ap, t_flags flags)
{
	int				length;
	unsigned long	n;

	length = 0;
	n = va_arg(ap, unsigned long);
	length = print_x_option((unsigned long long)n, flags);
	if (flags.precision != -1 || (flags.precision == -1 && n > 0))
		print_hex((unsigned long long)n);
	if (flags.minus)
		length = print_minus(length, flags);
	return (length);
}

int		print_llx(va_list ap, t_flags flags)
{
	int					length;
	unsigned long long	n;

	length = 0;
	n = va_arg(ap, unsigned long long);
	length = print_x_option((unsigned long long)n, flags);
	if (flags.precision != -1 || (flags.precision == -1 && n > 0))
		print_hex((unsigned long long)n);
	if (flags.minus)
		length = print_minus(length, flags);
	return (length);
}
