/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:29:34 by pvandamm          #+#    #+#             */
/*   Updated: 2018/12/01 16:29:36 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_flags
{
	char		sharp;
	char		zero;
	char		plus;
	char		minus;
	char		space;
	int			field_width;
	int			precision;
	int			width;
	char		conv;
}				t_flags;

void			ft_putchar(char c);
void			ft_putnbr(int nb);
void			ft_putstr(const char *str);
size_t			ft_strlen(const char *str);
void			print_dec(long long n);
void			print_oct(unsigned long long n);
void			print_uns_dec(unsigned long long n);
void			print_hex(unsigned long long n);
void			print_bhex(unsigned long long n);
int				ft_printf(const char *format, ...);
int				print_minus(int length, t_flags flags);
int				print_d_option(long long n, int s, t_flags flags);
int				print_x_option(unsigned long long n, t_flags flags);
int				print_p_option(size_t n, t_flags flags);
int				print_o_option(unsigned long long n, t_flags flags);
int				print_s_option(char *s, t_flags flags);
int				print_u_option(unsigned long long n, t_flags flags);
int				print_bx_option(unsigned long long n, t_flags flags);
int				print_percent(va_list ap, t_flags flags);
int				print_minus(int length, t_flags flags);
int				print_p(va_list ap, t_flags flags);
int				print_hd(va_list ap, t_flags flags);
int				print_hhd(va_list ap, t_flags flags);
int				print_ld(va_list ap, t_flags flags);
int				print_lld(va_list ap, t_flags flags);
int				print_x(va_list ap, t_flags flags);
int				print_hx(va_list ap, t_flags flags);
int				print_hhx(va_list ap, t_flags flags);
int				print_lx(va_list ap, t_flags flags);
int				print_llx(va_list ap, t_flags flags);
int				print_bx(va_list ap, t_flags flags);
int				print_hbx(va_list ap, t_flags flags);
int				print_hhbx(va_list ap, t_flags flags);
int				print_lbx(va_list ap, t_flags flags);
int				print_llbx(va_list ap, t_flags flags);
int				print_u(va_list ap, t_flags flags);
int				print_hu(va_list ap, t_flags flags);
int				print_hhu(va_list ap, t_flags flags);
int				print_lu(va_list ap, t_flags flags);
int				print_llu(va_list ap, t_flags flags);
int				print_s(va_list ap, t_flags flags);
int				print_d(va_list ap, t_flags flags);
int				print_c(va_list ap, t_flags flags);
int				print_o(va_list ap, t_flags flags);
int				print_ho(va_list ap, t_flags flags);
int				print_hho(va_list ap, t_flags flags);
int				print_lo(va_list ap, t_flags flags);
int				print_llo(va_list ap, t_flags flags);
int				get_arg(va_list ap, t_flags *flags, int nb);
int				print_arg(const char *format, t_flags *flags, va_list ap);
int				fill_struct(const char *format, t_flags *flags);
int				fill_conv(const char *format, t_flags *flags, int i, int nb);
int				fill_option(const char *format, t_flags *flags, int i, int nb);
int				fill_field_width(const char *format, t_flags *flags, int i,
				int nb);
int				fill_precision(const char *format, t_flags *flags, int i,
								int nb);
int				fill_width(const char *format, t_flags *flags, int i, int nb);

#endif
