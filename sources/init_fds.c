/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:56:24 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/13 18:56:41 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	init_fds(char *in_file, char *out_file, size_t pipes, int **fds)
{
	size_t	size;
	size_t	i;

	size = sizeof(int) * ((2 * pipes) + 3);
	*fds = malloc(size);
	if (!*fds)
		return (true);
	ft_memset(*fds, -1, size);
	*fds[0] = open(in_file, in_file_flags);
	if (*fds[0] == -1)
		return (true);
	i = 1;
	while (pipes--)
	{
		if (pipe(*fds + i) == -1)
			return (true);
		i += 2;
	}
	(*fds)[i] = open(out_file, out_file_flags, out_file_mode);
	if ((*fds)[i] == -1)
		return (true);
	return (false);
}
