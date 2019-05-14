/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:24:21 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/28 20:14:46 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_bx(va_list ap, t_flags flags)
{
	unsigned int	n;
	int				length;

	length = 0;
	n = va_arg(ap, unsigned int);
	length = print_bx_option(n, flags);
	if (flags.precision != -1 || (flags.precision == -1 && n > 0))
		print_bhex((unsigned long long)n);
	if (flags.minus)
		length = print_minus(length, flags);
	return (length);
}

int		print_hbx(va_list ap, t_flags flags)
{
	unsigned short	n;
	int				length;

	length = 0;
	n = (short)va_arg(ap, unsigned int);
	length = print_bx_option(n, flags);
	if (flags.precision != -1 || (flags.precision == -1 && n > 0))
		print_bhex((unsigned long long)n);
	if (flags.minus)
		length = print_minus(length, flags);
	return (length);
}

int		print_hhbx(va_list ap, t_flags flags)
{
	unsigned char	n;
	int				length;

	length = 0;
	n = (char)va_arg(ap, unsigned int);
	length = print_bx_option(n, flags);
	if (flags.precision != -1 || (flags.precision == -1 && n > 0))
		print_bhex(n);
	if (flags.minus)
		length = print_minus(length, flags);
	return (length);
}

int		print_lbx(va_list ap, t_flags flags)
{
	unsigned long	n;
	int				length;

	length = 0;
	n = va_arg(ap, unsigned long);
	length = print_bx_option(n, flags);
	if (flags.precision != -1 || (flags.precision == -1 && n > 0))
		print_bhex((unsigned long long)n);
	if (flags.minus)
		length = print_minus(length, flags);
	return (length);
}

int		print_llbx(va_list ap, t_flags flags)
{
	unsigned long long	n;
	int					length;

	length = 0;
	n = va_arg(ap, unsigned long long);
	length = print_bx_option(n, flags);
	if (flags.precision != -1 || (flags.precision == -1 && n > 0))
		print_bhex((unsigned long long)n);
	if (flags.minus)
		length = print_minus(length, flags);
	return (length);
}
