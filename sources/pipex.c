/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:04:26 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/09 14:55:20 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	t_list	*cmds;
	bool	exit_status;

	if (argc < 4)
	{
		ft_putstr_fd("pipex: Too few arguments\n", 2);
		return (1);
	}
	paths = get_paths(envp);
	cmds = NULL;
	exit_status = parse_cmds(argc - 3, argv + 2, paths, &cmds);
	free_nptr(2, paths);
	ft_lstclear(&cmds, free_cmd);
	return (exit_status);
}
