/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:10:56 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/31 16:45:14 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **envp)
{
	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	if (!*envp)
		return (NULL);
	return (ft_split(*envp + 5, ':'));
}
