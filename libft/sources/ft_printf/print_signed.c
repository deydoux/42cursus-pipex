/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:16:21 by deydoux           #+#    #+#             */
/*   Updated: 2023/11/21 10:02:42 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	get_arg(va_list *ap, size_t size)
{
	if (!size)
		return (va_arg(*ap, int));
	if (size == sizeof(signed char))
		return ((signed char)va_arg(*ap, int));
	if (size == sizeof(short))
		return ((short)va_arg(*ap, int));
	if (size == sizeof(long long))
		return (va_arg(*ap, long long));
	if (size == sizeof(long))
		return (va_arg(*ap, long));
	else
		return (va_arg(*ap, int));
}

static int	update_flags(t_flags *flags, long long n)
{
	int			len;
	long long	tmp_n;

	if (flags->precision != -1)
		flags->padding = ' ';
	len = !n && flags->precision == -1;
	tmp_n = n;
	while (tmp_n)
	{
		tmp_n /= 10;
		len++;
	}
	if (n)
		flags->precision -= len;
	len += (flags->precision * (flags->precision > 0))
		+ (n < 0 || flags->positive_sign);
	flags->width -= len;
	len += flags->width * (flags->width > 0);
	return (len);
}

static void	put_sign(long long n, t_flags flags)
{
	if (n < 0)
		ft_stdout_char('-', flags.error);
	else if (flags.positive_sign)
		ft_stdout_char(flags.positive_sign, flags.error);
}

static void	print_ll(long long n, t_flags flags)
{
	if (n == LLONG_MIN)
	{
		print_ll(n / 10, flags);
		flags.precision = 0;
		return (print_ll(n % 10 * -1, flags));
	}
	if (n < 0)
		n *= -1;
	while (flags.precision-- > 0)
		ft_stdout_char('0', flags.error);
	if (n >= 10)
		print_ll(n / 10, flags);
	ft_stdout_char(n % 10 + '0', flags.error);
}

int	print_signed(va_list *ap, t_flags flags)
{
	long long	n;
	int			len;

	n = get_arg(ap, flags.size);
	len = update_flags(&flags, n);
	if (flags.padding == '0')
		put_sign(n, flags);
	if (!flags.left_adjust)
		while (flags.width-- > 0)
			ft_stdout_char(flags.padding, flags.error);
	if (flags.padding != '0')
		put_sign(n, flags);
	if (flags.precision != -1 && !n)
		while (flags.precision-- > 0)
			ft_stdout_char('0', flags.error);
	else
		print_ll(n, flags);
	while (flags.width-- > 0)
		ft_stdout_char(' ', flags.error);
	return (len);
}
