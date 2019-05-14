/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:47:39 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/29 16:39:13 by pvandamm         ###   ########.fr       */
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
	if (flags.sharp && flags.field_width && n && ((!flags.zero) ||
				(flags.zero && flags.precision == -1)))
	{
		length += 1;
		write(1, "0", 1);
	}
	return (length);
}

static int	split2(int i, int length, t_flags flags)
{
	while (flags.precision > i)
	{
		ft_putchar('0');
		flags.precision--;
		length++;
	}
	return (length);
}

static int	split3(int n, int *tmp, int length, t_flags flags)
{
	if (flags.sharp)
	{
		if (n)
			*tmp -= 1;
		if ((((!flags.field_width && n) || (flags.zero && n)) &&
				(flags.precision > -1)) ||\
				(!flags.zero && flags.precision == -1))
		{
			write(1, "0", 1);
			length += 1;
		}
	}
	return (length);
}

int			print_o_option(unsigned long long n, t_flags flags)
{
	int	length;
	int	tmp;
	int	i;

	length = 1;
	i = 1;
	if (flags.precision == -1 && n < 1)
		length = 0;
	tmp = flags.field_width;
	while (n > 7)
	{
		n /= 8;
		length++;
		i++;
	}
	if (flags.precision > length)
		tmp -= flags.precision;
	else
		tmp -= length;
	length = split3(n, &tmp, length, flags);
	length = split(n, tmp, length, flags);
	length = split2(i, length, flags);
	return (length);
}
