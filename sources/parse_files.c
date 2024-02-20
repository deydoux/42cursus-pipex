/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:53:58 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/20 02:50:35 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static bool	read_doc_line(char **line)
{
	if (*line)
		free(*line);
	ft_putstr_fd("heredoc> ", STDOUT_FILENO);
	*line = get_next_line(STDIN_FILENO);
	return (*line != NULL);
}

static bool	read_doc(char *limiter, int *in_fd)
{
	int		fd[2];
	char	*line;

	if (!limiter || pipe(fd) == -1)
		return (true);
	*in_fd = fd[0];
	line = NULL;
	while (read_doc_line(&line))
	{
		if (ft_strcmp(line, limiter) == 0)
			break ;
		ft_putstr_fd(line, fd[1]);
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
	char	*limiter;

	files->here_doc = ft_strcmp(argv[0], "here_doc") == 0;
	files->out_path = out_path;
	files->out_flags = outfile_flags;
	if (files->here_doc)
	{
		limiter = ft_strjoin(argv[1], "\n");
		if (read_doc(limiter, &files->in_fd))
			files->in_fd = -1;
		free(limiter);
		files->out_flags |= O_APPEND;
	}
	else
	{
		files->in_fd = open(argv[0], infile_flags);
		files->out_flags |= O_TRUNC;
	}
	return (files->in_fd == -1);
}
