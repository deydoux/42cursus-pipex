/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:04:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/11 13:11:43 by deydoux          ###   ########.fr       */
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
	infile_flags = O_RDONLY,
	outfile_flags = O_CREAT | O_WRONLY | O_TRUNC,
	outfile_mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
};

void	free_cmd(void *ptr);
bool	parse_cmds(int argc, char **argv, char **envp, t_list **cmds);

#endif
