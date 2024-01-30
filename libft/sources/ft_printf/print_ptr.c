/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:55:40 by deydoux           #+#    #+#             */
/*   Updated: 2023/11/21 09:57:45 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(va_list *ap, t_flags flags)
{
	flags.alternate_form = 1;
	flags.size = sizeof(long);
	flags.ptr = 1;
	return (print_unsigned(ap, flags, "0123456789abcdef", "0x"));
}

int	put_nil(t_flags flags)
{
	int	len;

	len = 5;
	flags.width -= len;
	if (!flags.left_adjust)
	{
		while (flags.width-- > 0)
		{
			ft_stdout_char(' ', flags.error);
			len++;
		}
	}
	write(1, "(nil)", 5);
	while (flags.width-- > 0)
	{
		ft_stdout_char(' ', flags.error);
		len++;
	}
	return (len);
}
