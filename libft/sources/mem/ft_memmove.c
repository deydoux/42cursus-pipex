/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:55:39 by deydoux           #+#    #+#             */
/*   Updated: 2023/11/30 17:02:27 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_ptr;
	const char	*src_ptr;

	if (!dest && !src)
		return (dest);
	dest_ptr = dest;
	src_ptr = src;
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	while (n--)
		dest_ptr[n] = src_ptr[n];
	return (dest);
}
