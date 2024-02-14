/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:49:22 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/14 14:06:24 by deydoux          ###   ########.fr       */
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

static char	*join_path(char *path1, char *path2)
{
	size_t	size;
	char	*path;

	size = ft_strlen(path1) + ft_strlen(path2) + 2;
	path = malloc(sizeof(char) * size);
	if (!path)
		return (NULL);
	ft_strlcpy(path, path1, size);
	ft_strlcat(path, "/", size);
	ft_strlcat(path, path2, size);
	return (path);
}

static char	*get_path(char *arg, char **paths)
{
	char	*path;

	if (ft_strchr(arg, '/'))
		return (ft_strdup(arg));
	if (!paths)
		return (NULL);
	while (*paths)
	{
		path = join_path(*paths++, arg);
		if (!path)
			return (NULL);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
	}
	return (NULL);
}

static bool	parse_cmd(char *arg, char **paths, t_list **cmds)
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
	cmd->argv = ft_split(arg, ' ');
	if (!cmd->argv)
		return (true);
	cmd->path = get_path(cmd->argv[0], paths);
	if (!cmd->path || access(cmd->path, X_OK) == -1)
		return (true);
	cmd->pid = -1;
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
