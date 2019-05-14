/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:02:35 by pvandamm          #+#    #+#             */
/*   Updated: 2018/12/01 16:02:36 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	split1(int s, long long n, t_flags flags, int *j)
{
	int		i;

	i = 0;
	if (n > -1)
	{
		if (flags.plus && flags.precision == 0 && n > -1 &&
			(flags.field_width < s || flags.zero))
		{
			ft_putchar('+');
			*j = 1;
			i++;
		}
		else if (flags.space && n > -1)
		{
			ft_putchar(' ');
			*j = 1;
			i++;
		}
	}
	else if (flags.precision == 0 && flags.zero && n < 0)
		ft_putchar('-');
	return (i);
}

static int	split3(long long n, int s, t_flags flags)
{
	int	i;

	i = 0;
	if (flags.precision != 0)
	{
		if (n < 0)
			ft_putchar('-');
		else if (flags.plus)
		{
			ft_putchar('+');
			i++;
		}
		while (flags.precision-- > s - (n < 0 ? 1 : 0))
		{
			ft_putchar('0');
			i++;
		}
	}
	return (i);
}

static int	split2(long long n, int s, int u, t_flags flags)
{
	int	i;

	i = split3(n, s, flags);
	if (!flags.zero && flags.precision == 0 && n < 0)
		ft_putchar('-');
	if (flags.plus && !flags.zero &&
		flags.field_width > s && flags.precision == 0)
	{
		ft_putchar('+');
		i++;
	}
	if (n || (!n && flags.precision != -1))
		print_dec((long long)n);
	if (flags.minus)
	{
		while (flags.field_width > s + (((flags.space ||
				flags.plus) && n > -1) ? 1 : 0) +
					(u != -1 && u > s ? u - s : 0))
		{
			ft_putchar(' ');
			flags.field_width--;
			i++;
		}
	}
	return (i);
}

int			print_d_option(long long n, int s, t_flags flags)
{
	int	i;
	int	u;
	int	j;

	i = split1(s, n, flags, &j);
	if (!flags.minus && flags.field_width)
	{
		while (flags.field_width > s + ((((flags.space || flags.plus) &&
							n > -1) || (n < 0 &&
							flags.precision > s - 1) ? 1 : 0) +
							(flags.precision > s ? flags.precision - s : 0)))
		{
			ft_putchar(flags.zero &&
						flags.precision == 0 ? '0' : ' ');
			flags.field_width--;
			i++;
		}
	}
	u = flags.precision;
	return (i + split2(n, s, u, flags));
}
