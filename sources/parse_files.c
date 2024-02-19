/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:53:58 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/19 17:26:43 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*read_doc_line(void)
{
	ft_putstr_fd("heredoc> ", STDOUT_FILENO);
	return (get_next_line(STDIN_FILENO));
}

static bool	read_doc(char *limiter, int *in_fd)
{
	char	*nl_limiter;
	int		fd[2];
	char	*line;

	nl_limiter = ft_strjoin(limiter, "\n");
	if (!nl_limiter || pipe(fd) == -1)
		return (true);
	*in_fd = fd[0];
	line = read_doc_line();
	while (line)
	{
		if (ft_strcmp(line, nl_limiter) == 0)
			break ;
		ft_putstr_fd(line, fd[1]);
		free(line);
		line = read_doc_line();
	}
	free(line);
	close(fd[1]);
	if (!line)
	{
		close(*in_fd);
		return (true);
	}
	return (false);
}

bool	parse_files(char **argv, char *out_path, t_files *files)
{
	files->out_path = out_path;
	files->out_flags = outfile_flags;
	files->here_doc = ft_strcmp(argv[0], "here_doc") == 0;
	if (files->here_doc)
	{
		if (read_doc(argv[1], &files->in_fd))
			return (true);
		files->out_flags |= O_APPEND;
	}
	else
	{
		files->in_fd = open(argv[0], infile_flags);
		if (files->in_fd == -1)
			return (true);
		files->out_flags |= O_TRUNC;
	}
	return (false);
}
