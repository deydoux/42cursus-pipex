/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:13:10 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/09 15:00:26 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_cmd(void *ptr)
{
	t_cmd	*cmd;

	cmd = ptr;
	if (cmd->argv)
		free(cmd->path);
	free_nptr(2, cmd->argv);
	free(cmd);
}
