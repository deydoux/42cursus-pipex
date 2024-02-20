/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:04:26 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/20 15:52:23 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_list	*cmds;
	t_files	files;
	bool	error;

	if (argc < 5)
	{
		ft_putstr_fd("pipex: Too few arguments\n", STDERR_FILENO);
		return (1);
	}
	if (!BONUS && argc > 5)
	{
		ft_putstr_fd("pipex: Too much arguments\n", STDERR_FILENO);
		return (1);
	}
	cmds = NULL;
	error = parse_files(&argc, &argv, &files)
		|| parse_cmds(argc, argv, envp, &cmds)
		|| exec_cmds(cmds, envp, files);
	ft_lstclear(&cmds, free_cmd);
	if (error && errno)
		perror("pipex");
	return (error);
}
