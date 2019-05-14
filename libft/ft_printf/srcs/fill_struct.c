/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:07:32 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/29 14:08:23 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fill_option(const char *format, t_flags *flags, int i, int nb)
{
	flags[nb].sharp = 0;
	flags[nb].zero = 0;
	flags[nb].plus = 0;
	flags[nb].minus = 0;
	flags[nb].space = 0;
	while (format[i] == '#' || format[i] == '0' || format[i] == '+' ||\
			format[i] == '-' || format[i] == ' ')
	{
		if (format[i] == '#')
			flags[nb].sharp = 1;
		if (format[i] == '0')
			flags[nb].zero = 1;
		if (format[i] == '+')
			flags[nb].plus = 1;
		if (format[i] == '-')
			flags[nb].minus = 1;
		if (format[i] == ' ')
			flags[nb].space = 1;
		i++;
	}
	return (i);
}

int	fill_field_width(const char *format, t_flags *flags, int i, int nb)
{
	flags[nb].field_width = 0;
	if (format[i] > '0' && format[i] <= '9')
	{
		while (format[i] > 47 && format[i] < 58)
			flags[nb].field_width = (flags[nb].field_width * 10) \
									+ format[i++] - 48;
	}
	return (i);
}

int	fill_precision(const char *format, t_flags *flags, int i, int nb)
{
	flags[nb].precision = 0;
	if (format[i] == '.')
	{
		i++;
		while (format[i] > 47 && format[i] < 58)
			flags[nb].precision = (flags[nb].precision * 10) + format[i++] - 48;
		if (flags[nb].precision == 0)
			flags[nb].precision = -1;
	}
	return (i);
}

int	fill_width(const char *format, t_flags *flags, int i, int nb)
{
	if (format[i] == 'h')
	{
		if (format[i + 1] == 'h')
		{
			flags[nb].width = 1;
			i++;
		}
		else
			flags[nb].width = 0;
		i++;
	}
	if (format[i] == 'l')
	{
		if (format[i + 1] == 'l')
		{
			flags[nb].width = 3;
			i++;
		}
		else
			flags[nb].width = 2;
		i++;
	}
	if (format[i] == 'L')
		flags[nb].width = 4;
	return (i);
}

int	fill_conv(const char *format, t_flags *flags, int i, int nb)
{
	int		j;
	char	*str;

	j = 0;
	str = "cspdiouxX%f";
	while (str[j])
	{
		if (format[i] == str[j])
		{
			flags[nb].conv = j;
			return (i);
		}
		j++;
	}
	return (0);
}
