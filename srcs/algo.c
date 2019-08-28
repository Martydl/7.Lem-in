/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 11:59:56 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/27 12:10:12 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_paths	*ft_newpath(t_paths *paths, int *way)
{
	t_paths *ret;
	t_paths *new;

	if  (!(new = (t_paths*)malloc(sizeof(t_paths))))
		return (NULL);
	new->lane = way;
	new->next = NULL;
	if (!paths)
		return (new);
	else
	{
		ret = paths;
		while (paths->next)
			paths = paths->next;
		paths->next = new;
	}
	return (ret);
}

int		**ft_getpaths(t_rm *rm, int **matrix)
{
	t_paths *paths;
	int 	*way;
	int		*conflicts;

	paths =  NULL;

	if (!(conflicts = (int*)malloc(sizeof(int) * ft_nbroom(rm))))
		return (NULL);
	if (way = ft_bfs(paths, rm, matrix, conflicts))
		paths = ft_newpath(paths, way);
}
