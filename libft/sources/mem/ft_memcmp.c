/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:57:17 by deydoux           #+#    #+#             */
/*   Updated: 2023/11/13 13:31:24 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_ptr;
	const unsigned char	*s2_ptr;
	size_t				i;

	s1_ptr = s1;
	s2_ptr = s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && s1_ptr[i] == s2_ptr[i])
		i++;
	return (s1_ptr[i] - s2_ptr[i]);
}
