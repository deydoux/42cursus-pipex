/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:16:43 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/09 14:07:57 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

char	*get_path(char *arg, char **paths)
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
		if (!access(path, F_OK))
			return (path);
		free(path);
	}
	return (NULL);
}
