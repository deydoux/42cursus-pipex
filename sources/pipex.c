/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:04:26 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/14 11:53:03 by deydoux          ###   ########.fr       */
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
		|| init_fds(argc - 1, argv + 1, &fds);
	ft_lstclear(&cmds, free_cmd);
	free_fds(fds);
	if (error)
		perror("pipex");
	return (error);
}
