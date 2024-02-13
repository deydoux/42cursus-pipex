/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:04:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/13 16:02:14 by deydoux          ###   ########.fr       */
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
}			t_cmd;

enum
{
	in_file_flags = O_RDONLY,
	out_file_flags = O_CREAT | O_WRONLY | O_TRUNC,
	out_file_mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
};

int		exec_cmd(t_cmd *cmd, char **envp);
void	free_cmd(void *ptr);
bool	parse_cmds(int argc, char **argv, char **envp, t_list **cmds);

#endif
