/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:22:23 by deydoux           #+#    #+#             */
/*   Updated: 2023/12/03 16:23:22 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_abs(int j)
{
	return (j * ((j > 0) - (j < 0)));
}
