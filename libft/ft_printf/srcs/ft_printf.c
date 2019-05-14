/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:36:56 by pvandamm          #+#    #+#             */
/*   Updated: 2018/12/01 16:37:36 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"

int		ft_count_arg(const char *format)
{
	int		i;
	int		nb_arg;

	i = 0;
	nb_arg = 0;
	while (format[i])
	{
		if (format[i] == '%')
			nb_arg++;
		i++;
	}
	return (nb_arg);
}

int		ft_printf(const char *format, ...)
{
	int		nb_print;
	int		i;
	va_list	ap;
	t_flags	*flags;

	i = ft_count_arg(format);
	va_start(ap, format);
	if (!(flags = (t_flags *)malloc(sizeof(t_flags) * ft_count_arg(format))))
		return (0);
	if (!(fill_struct(format, flags)))
		return (0);
	nb_print = print_arg(format, flags, ap);
	va_end(ap);
	free(flags);
	return (nb_print);
}
