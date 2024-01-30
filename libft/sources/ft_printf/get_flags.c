/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:49:54 by deydoux           #+#    #+#             */
/*   Updated: 2023/11/16 12:34:55 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	parse_flags(const char **format)
{
	t_flags	flags;

	flags.alternate_form = 0;
	flags.padding = ' ';
	flags.left_adjust = 0;
	flags.positive_sign = 0;
	while (**format)
	{
		if (**format == '#')
			flags.alternate_form = 1;
		else if (**format == '0')
			flags.padding = '0';
		else if (**format == '-')
			flags.left_adjust = 1;
		else if (**format == ' ' && flags.positive_sign != '+')
			flags.positive_sign = ' ';
		else if (**format == '+')
			flags.positive_sign = '+';
		else
			return (flags);
		(*format)++;
	}
	return (flags);
}

static int	parse_width(const char **format, va_list *ap)
{
	int	width;

	if (**format == '*')
	{
		(*format)++;
		return (va_arg(*ap, int));
	}
	width = 0;
	while (ft_isdigit(**format))
		width = width * 10 + *(*format)++ - '0';
	return (width);
}

static int	parse_precision(const char **format, va_list *ap)
{
	int	precision;

	precision = -1;
	if (**format == '.')
	{
		(*format)++;
		precision = parse_width(format, ap);
	}
	return (precision);
}

static size_t	parse_size(const char **format)
{
	size_t	size;

	size = 0;
	if (!ft_strncmp(*format, "hh", 2))
	{
		size = sizeof(signed char);
		(*format)++;
	}
	else if (**format == 'h')
		size = sizeof(short);
	else if (!ft_strncmp(*format, "ll", 2))
	{
		size = sizeof(long long);
		(*format)++;
	}
	else if (**format == 'l')
		size = sizeof(long);
	*format += size != 0;
	return (size);
}

t_flags	get_flags(const char **format, va_list *ap, int *error)
{
	t_flags	flags;

	flags = parse_flags(format);
	flags.width = parse_width(format, ap);
	flags.precision = parse_precision(format, ap);
	flags.size = parse_size(format);
	flags.ptr = 0;
	flags.error = error;
	return (flags);
}
