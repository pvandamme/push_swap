/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:07:32 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/29 17:57:28 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_u(va_list ap, t_flags flags)
{
	unsigned int	n;
	int				length;

	n = va_arg(ap, unsigned int);
	length = print_u_option((unsigned long long)n, flags);
	if (flags.precision != -1 || (flags.precision == -1 && n > 0))
		print_uns_dec((unsigned long long)n);
	if (flags.minus)
		length = print_minus(length, flags);
	return (length);
}

int		print_hu(va_list ap, t_flags flags)
{
	unsigned short	n;
	int				length;

	n = (short)va_arg(ap, int);
	length = print_u_option((unsigned long long)n, flags);
	if (flags.precision != -1 || (flags.precision == -1 && n > 0))
		print_uns_dec((unsigned long long)n);
	if (flags.minus)
		length = print_minus(length, flags);
	return (length);
}

int		print_hhu(va_list ap, t_flags flags)
{
	unsigned char	n;
	int				length;

	n = (char)va_arg(ap, int);
	length = print_u_option((unsigned long long)n, flags);
	if (flags.precision != -1 || (flags.precision == -1 && n > 0))
		print_uns_dec((unsigned long long)n);
	if (flags.minus)
		length = print_minus(length, flags);
	return (length);
}

int		print_lu(va_list ap, t_flags flags)
{
	unsigned long	n;
	int				length;

	n = va_arg(ap, unsigned long);
	length = print_u_option((unsigned long long)n, flags);
	if (flags.precision != -1 || (flags.precision == -1 && n > 0))
		print_uns_dec((unsigned long long)n);
	if (flags.minus)
		length = print_minus(length, flags);
	return (length);
}

int		print_llu(va_list ap, t_flags flags)
{
	unsigned long long	n;
	int					length;

	n = va_arg(ap, unsigned long long);
	length = print_u_option((unsigned long long)n, flags);
	if (flags.precision != -1 || (flags.precision == -1 && n > 0))
		print_uns_dec((unsigned long long)n);
	if (flags.minus)
		length = print_minus(length, flags);
	return (length);
}
