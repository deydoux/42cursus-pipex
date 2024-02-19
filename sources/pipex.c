/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:04:26 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/19 15:09:19 by deydoux          ###   ########.fr       */
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
		ft_putstr_fd("pipex: Too few arguments\n", 2);
		return (1);
	}
	cmds = NULL;
	error = parse_files(argv[1], argv[argc - 1], &files)
		|| parse_cmds(argc - 3, argv + 2, envp, &cmds)
		|| exec_cmds(cmds, envp, files);
	ft_lstclear(&cmds, free_cmd);
	if (error && errno)
		perror("pipex");
	return (error);
}
