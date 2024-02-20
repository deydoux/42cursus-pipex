/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:53:58 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/20 15:15:53 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static bool	read_doc_line(char **line)
{
	if (*line)
		free(*line);
	ft_putstr_fd("> ", STDOUT_FILENO);
	*line = get_next_line(STDIN_FILENO);
	return (*line != NULL);
}

static void	read_doc(char *limiter, int *in_fd)
{
	int		fd[2];
	char	*line;

	*in_fd = -1;
	if (!limiter || pipe(fd) == -1)
		return ;
	*in_fd = fd[0];
	errno = 0;
	line = NULL;
	while (read_doc_line(&line))
	{
		if (ft_strcmp(line, limiter) == 0)
			break ;
		ft_putstr_fd(line, fd[1]);
	}
	free(line);
	close(fd[1]);
	if (!line && errno)
		safe_close(in_fd);
}

bool	parse_files(int *argc, char ***argv, t_files *files)
{
	bool	here_doc;
	char	*limiter;

	here_doc = ft_strcmp((*argv)[1], "here_doc") == 0;
	files->out_path = (*argv)[(*argc) - 1];
	if (here_doc)
	{
		if (*argc < 6)
		{
			ft_putstr_fd("pipex: Too few arguments\n", STDERR_FILENO);
			return (true);
		}
		limiter = ft_strjoin((*argv)[2], "\n");
		read_doc(limiter, &files->in_fd);
		free(limiter);
		files->out_flags = outfile_flags | O_APPEND;
	}
	else
	{
		files->in_fd = open((*argv)[1], infile_flags);
		files->out_flags = outfile_flags | O_TRUNC;
	}
	*argc -= 3 + here_doc;
	*argv += 2 + here_doc;
	return (files->in_fd == -1);
}
