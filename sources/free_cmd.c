/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:13:10 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/20 14:01:44 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_cmd(void *ptr)
{
	t_cmd	*cmd;

	cmd = ptr;
	if (cmd->pid != -1)
		waitpid(cmd->pid, NULL, 0);
	if (cmd->argv && cmd->argv[0])
		free(cmd->path);
	free_nptr(2, cmd->argv);
	free(cmd);
}
