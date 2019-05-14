/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:48:00 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/28 11:01:12 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_bhex(unsigned long long n)
{
	if (n > 15)
		print_bhex(n / 16);
	ft_putchar(n % 16 > 9 ? n % 16 + 'A' - 10 : n % 16 + 48);
}

void	print_hex(unsigned long long n)
{
	if (n > 15)
		print_hex(n / 16);
	ft_putchar(n % 16 > 9 ? n % 16 + 'a' - 10 : n % 16 + 48);
}

void	print_oct(unsigned long long n)
{
	if (n > 7)
		print_oct(n / 8);
	ft_putchar((n % 8) + 48);
}

void	print_uns_dec(unsigned long long n)
{
	if (n > 9)
		print_uns_dec(n / 10);
	ft_putchar((n % 10) + 48);
}

void	print_dec(long long n)
{
	unsigned long long nb;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	if (nb > 9)
		print_dec(nb / 10);
	ft_putchar((nb % 10) + 48);
}
