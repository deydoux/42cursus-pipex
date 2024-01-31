/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:10:56 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/31 13:59:01 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_default_path(void)
{
	int		fd;
	char	*line;
	char	**path;

	fd = open("/etc/environment", O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	while (line && ft_strncmp(line, "PATH=\"", 6))
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!line)
		return (NULL);
	line[ft_strlen(line) - 3] = 0;
	path = ft_split(line + 6, ':');
	free(line);
	return (path);
}

char	**get_path(char **envp)
{
	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	if (!*envp)
		return (get_default_path());
	return (ft_split(*envp + 5, ':'));
}
