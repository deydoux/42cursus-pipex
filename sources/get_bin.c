/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:16:43 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/30 18:35:37 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static bool	contains_trailing_slash(char *path)
{
	char	*path_ptr;

	path_ptr = ft_strrchr(path, '/');
	if (path_ptr)
		return (!(path_ptr + 1));
	return (false);
}

static char	*join_path(char *path1, char *path2)
{
	bool	trailing_slash;
	size_t	size;
	char	*path;

	trailing_slash = contains_trailing_slash(path1);
	size = ft_strlen(path1) + ft_strlen(path2) + !trailing_slash + 1;
	path = malloc(sizeof(char) * size);
	if (!path)
		return (NULL);
	ft_strlcat(path, path1, size);
	if (!trailing_slash)
		ft_strlcat(path, "/", size);
	ft_strlcat(path, path2, size);
	return (path);
}

char	*get_bin(char *command, char **path)
{

}
