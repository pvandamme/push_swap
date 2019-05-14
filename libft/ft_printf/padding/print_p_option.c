/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <pvandamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:13:29 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/29 18:25:02 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	print_p_option(size_t n, t_flags flags)
{
	int	length;
	int	tmp;

	tmp = 0;
	length = 3;
	if (!flags.field_width)
		write(1, "0x", 2);
	while (n > 15)
	{
		n /= 16;
		length++;
	}
	while (flags.field_width > length && !flags.minus)
	{
		ft_putchar(' ');
		length++;
		tmp--;
	}
	if (flags.field_width)
		write(1, "0x", 2);
	return (length);
}
