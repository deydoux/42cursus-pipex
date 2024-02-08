/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_nptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:44:08 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/08 17:21:51 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_nptr(size_t n, void *ptr)
{
	size_t	i;

	i = 0;
	if (n-- > 1 && ptr)
		while (((void **)ptr)[i])
			free_nptr(n, ((void **)ptr)[i++]);
	free(ptr);
}
