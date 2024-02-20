/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:49:22 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/20 15:27:10 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_paths(char **envp)
{
	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	if (!*envp)
		return (NULL);
	return (ft_split(*envp + 5, ':'));
}

static bool	parse_cmd(char *command, char **paths, t_list **cmds)
{
	t_cmd	*cmd;
	t_list	*new;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (true);
	new = ft_lstnew(cmd);
	if (!new)
	{
		free_cmd(cmd);
		return (true);
	}
	ft_lstadd_back(cmds, new);
	cmd->pid = -1;
	cmd->argv = ft_split(command, ' ');
	if (!cmd->argv || !cmd->argv[0])
		return (true);
	cmd->path = get_path(cmd->argv[0], paths);
	if (!cmd->path)
	{
		ft_putstr_fd("pipex: Command not found\n", STDERR_FILENO);
		errno = 0;
		return (true);
	}
	return (false);
}

bool	parse_cmds(int argc, char **argv, char **envp, t_list **cmds)
{
	char	**paths;
	int		i;
	bool	error;

	paths = get_paths(envp);
	i = 0;
	error = false;
	while (i < argc && !error)
		if (parse_cmd(argv[i++], paths, cmds))
			error = true;
	free_nptr(2, paths);
	return (error);
}
