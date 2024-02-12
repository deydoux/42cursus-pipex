/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:04:26 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/12 14:57:39 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static bool	pipex_test(t_list *cmds, char **envp)
{
	int		fd[2];
	pid_t	pid[2];
	int		outfile;

	ft_putnbr_fd(outfile_mode, 1);
	outfile = open("outfile", outfile_flags, outfile_mode);
	if (pipe(fd) == -1)
		return (true);
	pid[0] = fork();
	if (pid[0] == -1)
		return (true);
	if (!pid[0])
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(((t_cmd *)cmds->content)->path, ((t_cmd *)cmds->content)->argv, envp);
		exit(1);
	}
	cmds = cmds->next;
	pid[1] = fork();
	if (pid[1] == -1)
		return (true);
	if (!pid[1])
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(((t_cmd *)cmds->content)->path, ((t_cmd *)cmds->content)->argv, envp);
		exit(0);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	return (false);
}

int	main(int argc, char **argv, char **envp)
{
	t_list	*cmds;
	bool	error;

	if (argc < 3)
	{
		ft_putstr_fd("pipex: Too few arguments\n", 2);
		return (1);
	}
	cmds = NULL;
	error = parse_cmds(argc - 1, argv + 1, envp, &cmds);
	if (!error)
		error = pipex_test(cmds, envp);
	ft_lstclear(&cmds, free_cmd);
	if (error)
		perror("pipex");
	return (error);
}
