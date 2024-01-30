/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:10:20 by deydoux           #+#    #+#             */
/*   Updated: 2023/12/07 17:38:46 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <limits.h>

typedef struct s_flags
{
	int		alternate_form;
	char	padding;
	int		left_adjust;
	char	positive_sign;
	int		width;
	int		precision;
	size_t	size;
	int		ptr;
	int		*error;
}			t_flags;

void	ft_stdout(const void *buf, size_t nbyte, int *error);
void	ft_stdout_char(char c, int *error);
t_flags	get_flags(const char **format, va_list *ap, int *error);
int		print_char(va_list *ap, t_flags flags);
int		print_signed(va_list *ap, t_flags flags);
int		print_str(va_list *ap, t_flags flags);
int		print_ptr(va_list *ap, t_flags flags);
int		print_unsigned(va_list *ap, t_flags flags, char *base, char *prefix);
int		put_nil(t_flags flags);

#endif
