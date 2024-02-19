/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:03:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/19 15:51:16 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static bool	open_outfile(t_files files, int *fd)
{
	*fd = open(files.out_path, outfile_flags, outfile_mode);
	return (*fd == -1);
}

static bool	create_child(t_cmd *cmd, int fd[3], char **envp)
{
	cmd->pid = fork();
	if (cmd->pid == -1)
		return (true);
	if (cmd->pid > 0)
		return (false);
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[2], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	if (execve(cmd->path, cmd->argv, envp) == -1)
	{
		perror("pipex");
		exit(1);
	}
	exit(0);
}

static void	safe_close(int *fd)
{
	if (*fd == -1)
		return ;
	close(*fd);
	*fd = -1;
}

bool	exec_cmds(t_list *cmds, char **envp, t_files files)
{
	bool	error;
	int		fd[3];

	error = false;
	fd[0] = files.in_fd;
	ft_memset(fd + 1, -1, sizeof(int) * 2);
	while (cmds && !error)
	{
		if (cmds->next)
			error = pipe(&fd[1]) == -1;
		else
			error = open_outfile(files, &fd[2]);
		if (!error)
			error = create_child(cmds->content, fd, envp);
		safe_close(&fd[0]);
		safe_close(&fd[2]);
		fd[0] = fd[1];
		cmds = cmds->next;
	}
	safe_close(&fd[0]);
	return (error);
}
