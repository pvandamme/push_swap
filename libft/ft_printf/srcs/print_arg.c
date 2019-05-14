/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:21:06 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/29 14:20:45 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_jump(const char *format, t_flags *flags, int i, int nb)
{
	char	*str;
	int		conv;

	conv = flags[nb].conv;
	str = "cspdiouxXf";
	if (flags[nb].conv == 9)
	{
		while (format[i])
		{
			if (format[i] == '%')
			{
				if (format[i + 1])
					return (i + 1);
				else
					return (0);
			}
			i++;
		}
	}
	while (format[i] != str[conv])
		i++;
	return ((format[i + 1]) ? i + 1 : 0);
}

int		print_arg(const char *format, t_flags *flags, va_list ap)
{
	int	i;
	int nb;
	int	nb_print;

	i = 0;
	nb = 0;
	nb_print = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			nb_print += get_arg(ap, flags, nb);
			if (!(i = ft_jump(format, flags, i + 1, nb)))
				return (nb_print);
			nb++;
		}
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			i++;
			nb_print++;
		}
	}
	return (nb_print);
}
