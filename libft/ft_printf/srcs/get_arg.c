/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:16:52 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/27 19:17:26 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		(*g_array_print[52])(va_list ap, t_flags flags) = {
	print_c,
	0,
	0,
	0,
	0,
	print_s,
	0,
	0,
	0,
	0,
	print_p,
	0,
	0,
	0,
	0,
	print_d,
	print_hd,
	print_hhd,
	print_ld,
	print_lld,
	print_d,
	print_hd,
	print_hhd,
	print_ld,
	print_lld,
	print_o,
	print_ho,
	print_hho,
	print_lo,
	print_llo,
	print_u,
	print_hu,
	print_hhu,
	print_lu,
	print_llu,
	print_x,
	print_hx,
	print_hhx,
	print_lx,
	print_llx,
	print_bx,
	print_hbx,
	print_hhbx,
	print_lbx,
	print_llbx,
	print_percent
};

int		get_arg(va_list ap, t_flags *flags, int nb)
{
	int		j;

	j = 0;
	while (j < 10)
	{
		if (j == flags[nb].conv && j != 0 && j != 1 && j != 2)
		{
			if (flags[nb].width == 0)
				return ((g_array_print[j * 5 + 1])(ap, flags[nb]));
			if (flags[nb].width == 1)
				return ((g_array_print[j * 5 + 2])(ap, flags[nb]));
			if (flags[nb].width == 2)
				return ((g_array_print[j * 5 + 3])(ap, flags[nb]));
			if (flags[nb].width == 3)
				return ((g_array_print[j * 5 + 4])(ap, flags[nb]));
			if (flags[nb].width == 4)
				return ((g_array_print[j * 5 + 5])(ap, flags[nb]));
			return ((g_array_print[j * 5])(ap, flags[nb]));
		}
		else if (j == flags[nb].conv)
			return ((g_array_print[j * 5])(ap, flags[nb]));
		j++;
	}
	return (0);
}
