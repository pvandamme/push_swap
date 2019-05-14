/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:41:33 by pvandamm          #+#    #+#             */
/*   Updated: 2018/12/01 15:41:44 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	split(int n, int tmp, int length, t_flags flags)
{
	while (tmp > 0 && !flags.minus)
	{
		if (flags.zero && !flags.precision)
			ft_putchar('0');
		else
			ft_putchar(' ');
		tmp--;
		length++;
	}
	if (flags.sharp && flags.field_width && n && ((!flags.zero) || \
				(flags.zero && flags.precision == -1)))
	{
		length += 2;
		write(1, "0x", 2);
	}
	return (length);
}

static int	split2(int n, int *tmp, int length, t_flags flags)
{
	if (n)
		*tmp -= 2;
	if (((!flags.field_width && n) || (flags.zero && n)) && \
			flags.precision > -1)
	{
		write(1, "0x", 2);
		length += 2;
	}
	return (length);
}

static int	split3(int length, int i, t_flags flags)
{
	while (flags.precision > i)
	{
		ft_putchar('0');
		flags.precision--;
		length++;
	}
	return (length);
}

int			print_x_option(unsigned long long n, t_flags flags)
{
	int	length;
	int	tmp;
	int	i;

	length = 1;
	i = 1;
	if (flags.precision == -1 && n < 1)
		length = 0;
	tmp = flags.field_width;
	while (n > 15)
	{
		n /= 16;
		length++;
		i++;
	}
	if (flags.precision > length)
		tmp -= flags.precision;
	else
		tmp -= length;
	if (flags.sharp)
		length = split2(n, &tmp, length, flags);
	length = split(n, tmp, length, flags);
	length = split3(length, i, flags);
	return (length);
}
