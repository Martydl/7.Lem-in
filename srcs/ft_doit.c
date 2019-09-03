/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:40:21 by mde-laga          #+#    #+#             */
/*   Updated: 2019/09/03 10:51:27 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

char	**ft_initroom(t_rm *rm)
{
	char	**room;
	int		i;

	if (!(room = (char**)malloc(sizeof(char) * ft_nbroom(rm))))
		return (NULL);
	i = 0;
	while (rm)
	{
		room[i] = ft_strdup(rm->data[0]);
		rm = rm->next;
		i++;
	}
	return (room);
}

void	ft_doit(t_path *path, int **matrix, int ants, t_rm *rm)
{
	char	**room;

	room = ft_initroom(rm);
}
