/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 01:55:30 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/30 01:55:52 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_d(va_list ap, t_flags flags)
{
	int		i;
	int		n;
	int		cp;

	i = 1;
	n = va_arg(ap, int);
	cp = n;
	if (n == -2147483648)
		i = 11;
	else
	{
		if (cp < 0)
		{
			cp *= -1;
			i++;
		}
		while (cp > 9)
		{
			cp /= 10;
			i++;
		}
	}
	return (n == 0 && flags.precision == -1 ?
			print_d_option((long long)n, 0, flags) : i +
			print_d_option((long long)n, i, flags));
}

int		print_hd(va_list ap, t_flags flags)
{
	int		i;
	short	n;
	int		cp;

	i = 1;
	n = (short)va_arg(ap, int);
	cp = n;
	if (cp < 0)
	{
		cp *= -1;
		i++;
	}
	while (cp > 9)
	{
		cp /= 10;
		i++;
	}
	return (n == 0 && flags.precision == -1 ?
			print_d_option((long long)n, 0, flags) : i +
			print_d_option((long long)n, i, flags));
}

int		print_hhd(va_list ap, t_flags flags)
{
	int		i;
	char	n;
	int		cp;

	i = 1;
	n = (char)va_arg(ap, int);
	cp = n;
	if (cp < 0)
	{
		cp *= -1;
		i++;
	}
	while (cp > 9)
	{
		cp /= 10;
		i++;
	}
	return (n == 0 && flags.precision == -1 ?
			print_d_option((long long)n, 0, flags) : i +
			print_d_option((long long)n, i, flags));
}

int		print_ld(va_list ap, t_flags flags)
{
	int			i;
	long		n;
	long long	cp;

	i = 1;
	n = va_arg(ap, long);
	cp = (long long)n;
	if (cp < 0)
	{
		cp *= -1;
		i++;
	}
	while (cp > 9)
	{
		cp /= 10;
		i++;
	}
	return (n == 0 && flags.precision == -1 ?
			print_d_option((long long)n, 0, flags) : i +
			print_d_option((long long)n, i, flags));
}

int		print_lld(va_list ap, t_flags flags)
{
	int			i;
	long long	n;
	long long	cp;

	i = 1;
	n = va_arg(ap, long long);
	cp = n;
	if (n == -9223372036854775807 - 1)
		i = 20;
	else
	{
		if (cp < 0)
		{
			cp *= -1;
			i++;
		}
		while (cp > 9)
		{
			cp /= 10;
			i++;
		}
	}
	return (n == 0 && flags.precision == -1 ?
			print_d_option((long long)n, 0, flags) : i +
			print_d_option((long long)n, i, flags));
}
