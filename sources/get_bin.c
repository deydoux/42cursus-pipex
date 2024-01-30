/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:16:43 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/30 19:06:51 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*join_path(char *path1, char *path2)
{
	size_t	size;
	char	*path;

	ft_printf("Joining \"%s\" and \"%s\"\n", path1, path2);
	size = ft_strlen(path1) + ft_strlen(path2) + 2;
	path = malloc(sizeof(char) * size);
	if (!path)
		return (NULL);
	ft_strlcpy(path, path1, size);
	ft_strlcat(path, "/", size);
	ft_strlcat(path, path2, size);
	return (path);
}

char	*get_bin(char *command, char **path)
{
	char	*bin;

	while (*path)
	{
		bin = join_path(*path++, command);
		if (!bin)
			return (NULL);
		if (!access(bin, F_OK))
			return (bin);
		free(bin);
	}
	return (NULL);
}
