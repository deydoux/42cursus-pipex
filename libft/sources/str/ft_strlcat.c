/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:03:23 by deydoux           #+#    #+#             */
/*   Updated: 2023/11/09 15:10:08 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (ft_strlen(src) + size);
	src_len = 0;
	while (dst_len + src_len < size - 1 && src[src_len])
	{
		dst[dst_len + src_len] = src[src_len];
		src_len++;
	}
	dst[dst_len + src_len] = 0;
	while (src[src_len])
		src_len++;
	return (dst_len + src_len);
}
