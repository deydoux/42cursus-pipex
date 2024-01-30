/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:45:46 by deydoux           #+#    #+#             */
/*   Updated: 2023/11/16 19:16:42 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*ptr;

	size = sizeof(char) * (ft_strlen(s) + 1);
	ptr = malloc(size);
	if (ptr)
		ft_strlcpy(ptr, s, size);
	return (ptr);
}
