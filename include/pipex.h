/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:04:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/09 14:27:18 by deydoux          ###   ########.fr       */
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

void	free_cmd(void *ptr);
char	*get_path(char *arg, char **paths);
char	**get_paths(char **envp);
bool	parse_cmds(int argc, char **argv, char **paths, t_list **cmds);

#endif
