/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:04:26 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/30 18:59:09 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	**path;
	char	*bin;

	(void)argc;
	(void)argv;
	path = get_path(envp);
	if (!path)
		return (69);
	bin = get_bin(argv[1], path);
	free_split(path);
	if (!bin)
		return (69);
	ft_putendl_fd(bin, 1);
	free(bin);
}
