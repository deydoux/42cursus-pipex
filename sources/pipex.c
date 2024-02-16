/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:04:26 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/16 16:58:15 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	error = parse_cmds(argc - 3, argv + 2, envp, &cmds)
		|| init_fds(argc - 1, argv + 1, &fds) || exec_cmds(cmds, fds, envp);
	close_fds(fds, true);
	ft_lstclear(&cmds, free_cmd);
	if (error && errno)
		perror("pipex");
	return (error);
}
