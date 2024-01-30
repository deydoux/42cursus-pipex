/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:43:36 by deydoux           #+#    #+#             */
/*   Updated: 2023/12/03 15:27:13 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	tmp_n;
	long	n;

	sign = 1;
	tmp_n = 0;
	n = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		sign -= 2 * (*nptr++ == '-');
	while (ft_isdigit(*nptr))
	{
		tmp_n = tmp_n * 10 + *nptr++ - '0';
		if (n != tmp_n / 10)
			return (-(sign == 1));
		n = tmp_n;
	}
	return (sign * n);
}
