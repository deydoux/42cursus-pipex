/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:57:12 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/16 17:05:15 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fds(int *fds, bool parent)
{
	size_t	i;

	if (!fds)
		return ;
	i = 0;
	while (fds[i] != -1)
	{
		if (*fds)
			close(fds[i]);
		i++;
	}
	if (parent)
		free(fds);
}
