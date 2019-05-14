/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <pvandamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:16:32 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/29 18:00:15 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	split(int tmp, int length, t_flags flags)
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

int			print_u_option(unsigned long long n, t_flags flags)
{
	int	length;
	int	tmp;
	int	i;

	length = 1;
	i = 1;
	if (flags.precision == -1 && n < 1)
		length = 0;
	tmp = flags.field_width;
	while (n > 9)
	{
		n /= 10;
		length++;
		i++;
	}
	if (flags.precision > length)
		tmp -= flags.precision;
	else
		tmp -= length;
	length = split(tmp, length, flags);
	length = split2(i, length, flags);
	return (length);
}
