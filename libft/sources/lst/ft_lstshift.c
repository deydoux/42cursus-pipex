/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:32:22 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/19 13:22:08 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstshift(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (!lst || !*lst)
		return ;
	next = (*lst)->next;
	ft_lstdelone(*lst, del);
	*lst = next;
}
