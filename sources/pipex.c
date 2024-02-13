/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:04:26 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/13 17:31:57 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	close_fds(int *fds)
{
	while (*fds != -1)
		close(*fds++);
}

static bool	init_fds(char *in_file, char *out_file, size_t pipes, int **fds)
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

int	main(int argc, char **argv, char **envp)
{
	t_list	*cmds;
	int		*fds;
	bool	error;

	if (argc < 5)
	{
		ft_putstr_fd("pipex: Too few arguments\n", 2);
		return (1);
	}
	cmds = NULL;
	fds = NULL;
	error = false;
	if (parse_cmds(argc - 3, argv + 2, envp, &cmds)
		|| init_fds(argv[1], argv[argc - 1], argc - 4, &fds))
		error = true;
	ft_lstclear(&cmds, free_cmd);
	close_fds(fds);
	free(fds);
	if (error)
		perror("pipex");
	return (error);
}
