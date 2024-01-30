/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:10:12 by deydoux           #+#    #+#             */
/*   Updated: 2023/11/28 18:01:30 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert(const char **format, va_list *ap, int *error)
{
	const char	*percent_ptr;
	t_flags		flags;

	percent_ptr = (*format)++;
	flags = get_flags(format, ap, error);
	if (**format == 'd' || **format == 'i')
		return (print_signed(ap, flags));
	else if (**format == 'u')
		return (print_unsigned(ap, flags, "0123456789", ""));
	else if (**format == 'x')
		return (print_unsigned(ap, flags, "0123456789abcdef", "0x"));
	else if (**format == 'X')
		return (print_unsigned(ap, flags, "0123456789ABCDEF", "0X"));
	else if (**format == 'c')
		return (print_char(ap, flags));
	else if (**format == 's')
		return (print_str(ap, flags));
	else if (**format == 'p')
		return (print_ptr(ap, flags));
	else if (!**format)
		*error = 1;
	else if (**format != '%')
		*format = percent_ptr;
	ft_stdout_char('%', error);
	return (1);
}

void	ft_stdout(const void *buf, size_t nbyte, int *error)
{
	if (!*error)
		if (write(1, buf, nbyte) < 0)
			*error = 1;
}

void	ft_stdout_char(char c, int *error)
{
	ft_stdout(&c, 1, error);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		error;
	va_list	ap;

	if (!format)
		return (-1);
	len = 0;
	error = 0;
	va_start(ap, format);
	while (*format && !error)
	{
		if (*format == '%')
		{
			len += convert(&format, &ap, &error);
			format++;
		}
		else
		{
			ft_stdout(format++, 1, &error);
			len++;
		}
	}
	va_end(ap);
	return (len * (!error) - (error != 0));
}
