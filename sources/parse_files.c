/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:53:58 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/19 14:10:39 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static bool	open_infile(char *in_path, t_files *files)
{
	files->in_fd = open(in_path, infile_flags);
	return (files->in_fd == -1);
}

bool	parse_files(char *in_path, char *out_path, t_files *files)
{
	if (open_infile(in_path, files))
		return (true);
	files->out_path = out_path;
	return (false);
}
