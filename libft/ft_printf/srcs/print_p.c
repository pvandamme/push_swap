/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:42:42 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/29 18:21:30 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_hex_p(size_t n)
{
	if (n > 15)
		print_hex_p(n / 16);
	ft_putchar(n % 16 > 9 ? n % 16 + 'a' - 10 : n % 16 + 48);
}

int			print_p(va_list ap, t_flags flags)
{
	size_t	n;
	int		length;

	n = va_arg(ap, size_t);
	length = print_p_option(n, flags);
	if (flags.precision != -1 || (flags.precision == -1 && n > 0))
		print_hex_p(n);
	if (flags.minus)
		length = print_minus(length, flags);
	return (length);
}
