/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:03:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/16 18:04:01 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static bool	create_child(t_cmd *cmd, int *fds, char **envp)
{
	cmd->pid = fork();
	if (cmd->pid == -1)
		return (true);
	if (cmd->pid > 0)
		return (false);
	dup2(fds[0], STDIN_FILENO);
	dup2(fds[1], STDOUT_FILENO);
	close_fds(fds);
	if (execve(cmd->path, cmd->argv, envp) == -1)
	{
		perror("pipex");
		exit(1);
	}
	exit(0);
}

bool	exec_cmds(t_list *cmds, int *fds, char **envp)
{
	while (cmds)
	{
		if (create_child(cmds->content, fds, envp))
			return (true);
		close(fds[0]);
		fds[0] = 0;
		close(fds[1]);
		fds[1] = 0;
		*fds += 2;
		cmds = cmds->next;
	}
	return (false);
}
