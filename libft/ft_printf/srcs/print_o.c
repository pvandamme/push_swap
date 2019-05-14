/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:45:44 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/29 16:43:58 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_o(va_list ap, t_flags flags)
{
	unsigned int	n;
	int				length;

	n = va_arg(ap, unsigned int);
	length = print_o_option((unsigned long long)n, flags);
	if (flags.precision != -1 || (flags.precision == -1 && n > 0))
		print_oct((unsigned long long)n);
	if (flags.minus)
		length = print_minus(length, flags);
	return (length);
}

int		print_ho(va_list ap, t_flags flags)
{
	unsigned short	n;
	int				length;

	n = (short)va_arg(ap, int);
	length = print_o_option((unsigned long long)n, flags);
	if ((flags.precision != -1) || (flags.precision == -1 && n > 0))
		print_oct((unsigned long long)n);
	if (flags.minus)
		length = print_minus(length, flags);
	return (length);
}

int		print_hho(va_list ap, t_flags flags)
{
	unsigned char	n;
	int				length;

	n = (char)va_arg(ap, int);
	length = print_o_option((unsigned long long)n, flags);
	if ((flags.precision != -1) || (flags.precision == -1 && n > 0))
		print_oct((unsigned long long)n);
	if (flags.minus)
		length = print_minus(length, flags);
	return (length);
}

int		print_lo(va_list ap, t_flags flags)
{
	unsigned long	n;
	int				length;

	n = va_arg(ap, unsigned long);
	length = print_o_option((unsigned long long)n, flags);
	if ((flags.precision != -1) || (flags.precision == -1 && n > 0))
		print_oct((unsigned long long)n);
	if (flags.minus)
		length = print_minus(length, flags);
	return (length);
}

int		print_llo(va_list ap, t_flags flags)
{
	unsigned long long	n;
	int					length;

	n = va_arg(ap, unsigned long long);
	length = print_o_option((unsigned long long)n, flags);
	if ((flags.precision != -1) || (flags.precision == -1 && n > 0))
		print_oct((unsigned long long)n);
	if (flags.minus)
		length = print_minus(length, flags);
	return (length);
}
