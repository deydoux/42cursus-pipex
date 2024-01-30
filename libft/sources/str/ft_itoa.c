/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:36:44 by deydoux           #+#    #+#             */
/*   Updated: 2023/12/03 16:23:32 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		tmp_n;
	size_t	len;
	char	*s;

	tmp_n = n;
	len = 1 + (n <= 0);
	while (tmp_n)
	{
		tmp_n /= 10;
		len++;
	}
	s = malloc(sizeof(char) * len);
	if (!s)
		return (NULL);
	s[--len] = 0;
	if (n < 0)
		s[0] = '-';
	else
		s[0] = '0';
	while (n)
	{
		s[--len] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (s);
}
