/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:56:24 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/14 13:48:16 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static bool	init_pipes(size_t n, int *fds)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (pipe(fds + i) == -1)
			return (true);
		i += 2;
	}
	return (false);
}

static bool	open_infile(char *file, int *fd)
{
	*fd = open(file, infile_flags);
	return (*fd == -1);
}

static bool	open_outfile(char *file, int *fd)
{
	*fd = open(file, outfile_flags, outfile_mode);
	return (*fd == -1);
}

bool	init_fds(int argc, char **argv, int **fds)
{
	size_t	size;

	size = sizeof(int) * ((2 * (argc - 2)) + 1);
	*fds = malloc(size);
	if (!*fds)
		return (true);
	ft_memset(*fds, -1, size);
	return (open_infile(argv[0], *fds) || init_pipes(argc - 3, *fds + 1)
		|| open_outfile(argv[argc - 1], *fds + argc - 1));
}
