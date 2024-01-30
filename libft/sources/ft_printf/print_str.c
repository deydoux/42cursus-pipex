/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:56:36 by deydoux           #+#    #+#             */
/*   Updated: 2023/11/21 10:03:23 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	update_flags(t_flags *flags, const char *s)
{
	int	len;

	len = 0;
	while (s[len] && (flags->precision < 0 || len < flags->precision))
		len++;
	flags->precision = len;
	flags->width -= len;
	len += flags->width * (flags->width > 0);
	return (len);
}

static int	put_null(t_flags flags)
{
	int	len;

	len = 6 * (flags.precision == -1 || flags.precision >= 6);
	flags.width -= len;
	if (!flags.left_adjust)
	{
		while (flags.width-- > 0)
		{
			ft_stdout_char(' ', flags.error);
			len++;
		}
	}
	if (flags.precision == -1 || flags.precision >= 6)
		write(1, "(null)", 6);
	while (flags.width-- > 0)
	{
		ft_stdout_char(' ', flags.error);
		len++;
	}
	return (len);
}

int	print_str(va_list *ap, t_flags flags)
{
	const char	*s;
	int			len;

	s = va_arg(*ap, const char *);
	if (!s)
		return (put_null(flags));
	len = update_flags(&flags, s);
	if (!flags.left_adjust)
		while (flags.width-- > 0)
			ft_stdout_char(' ', flags.error);
	write(1, s, flags.precision);
	while (flags.width-- > 0)
		ft_stdout_char(' ', flags.error);
	return (len);
}
