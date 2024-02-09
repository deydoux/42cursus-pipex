/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:49:22 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/09 15:00:44 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static bool	parse_cmd(char *arg, char **paths, t_list **cmds)
{
	t_cmd	*cmd;
	t_list	*new;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (true);
	cmd->argv = ft_split(arg, ' ');
	if (!cmd->argv)
	{
		free_cmd(cmd);
		return (true);
	}
	cmd->path = get_path(cmd->argv[0], paths);
	new = ft_lstnew(cmd);
	if (!new)
	{
		free_cmd(cmd);
		return (true);
	}
	ft_lstadd_back(cmds, new);
	return (false);
}

bool	parse_cmds(int argc, char **argv, char **paths, t_list **cmds)
{
	int		i;

	i = 0;
	while (i < argc)
		if (parse_cmd(argv[i++], paths, cmds))
			return (true);
	return (false);
}
