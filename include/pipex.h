/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:04:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/20 02:53:54 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/wait.h>

typedef struct s_cmd
{
	char	**argv;
	char	*path;
	pid_t	pid;
}			t_cmd;

typedef struct s_files
{
	bool	here_doc;
	int		in_fd;
	char	*out_path;
	int		out_flags;
}			t_files;

enum
{
	infile_flags = O_RDONLY,
	outfile_flags = O_CREAT | O_WRONLY,
	outfile_mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
};

bool	exec_cmds(t_list *cmds, char **envp, t_files files);
void	free_cmd(void *ptr);
char	*get_path(char *arg, char **paths);
bool	parse_cmds(int argc, char **argv, char **envp, t_list **cmds);
bool	parse_files(int *argc, char ***argv, t_files *files);

#endif
