/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:04:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/16 16:58:22 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>

typedef struct s_cmd
{
	char	*path;
	char	**argv;
	pid_t	pid;
}			t_cmd;

enum
{
	infile_flags = O_RDONLY,
	outfile_flags = O_CREAT | O_WRONLY | O_TRUNC,
	outfile_mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
};

void	close_fds(int *fds, bool parent);
bool	exec_cmds(t_list *cmds, int *fds, char **envp);
void	free_cmd(void *ptr);
char	*get_path(char *arg, char **paths);
bool	init_fds(int argc, char **argv, int **fds);
bool	parse_cmds(int argc, char **argv, char **envp, t_list **cmds);

#endif
