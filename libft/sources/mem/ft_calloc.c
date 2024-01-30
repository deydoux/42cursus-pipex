/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:30:49 by deydoux           #+#    #+#             */
/*   Updated: 2023/12/04 07:28:45 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	bytes;
	void	*ptr;

	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	bytes = nmemb * size;
	ptr = malloc(bytes);
	if (ptr)
		ft_bzero(ptr, bytes);
	return (ptr);
}
