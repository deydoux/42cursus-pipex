/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:04:26 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/10 15:19:59 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static bool	pipex_test(t_list *cmds, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) == -1)
		return (true);
	pid1 = fork();
	if (pid1 == -1)
		return (true);
	if (!pid1)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(((t_cmd *)cmds->content)->path, ((t_cmd *)cmds->content)->argv, envp);
	}
	cmds = cmds->next;
	pid2 = fork();
	if (pid2 == -1)
		return (true);
	if (!pid2)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(((t_cmd *)cmds->content)->path, ((t_cmd *)cmds->content)->argv, envp);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
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
