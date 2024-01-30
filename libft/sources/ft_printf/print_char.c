/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:38:06 by deydoux           #+#    #+#             */
/*   Updated: 2023/11/21 09:57:10 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list *ap, t_flags flags)
{
	int	len;

	flags.width--;
	len = (flags.width * (flags.width > 0)) + 1;
	if (!flags.left_adjust)
		while (flags.width-- > 0)
			ft_stdout(&flags.padding, 1, flags.error);
	ft_stdout_char((unsigned char)va_arg(*ap, int), flags.error);
	while (flags.width-- > 0)
		ft_stdout_char(' ', flags.error);
	return (len);
}
