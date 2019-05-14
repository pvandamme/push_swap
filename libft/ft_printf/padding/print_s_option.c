/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <pvandamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:16:59 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/30 18:26:08 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s_option(char *s, t_flags flags)
{
	int	length;
	int	i;

	i = 0;
	length = 0;
	if (flags.precision != -1)
		i = ft_strlen(s);
	if (flags.precision && i)
		flags.field_width -= flags.precision;
	else
		flags.field_width -= i;
	while (flags.field_width > 0 && !flags.minus)
	{
		ft_putchar(' ');
		flags.field_width--;
		length++;
	}
	return (length);
}
