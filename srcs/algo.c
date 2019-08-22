/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 11:59:56 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/22 12:34:56 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_paths	*ft_newpath(t_paths *paths, int *way)
{
	t_paths *ret;
	t_paths *new;

	if  (!(new = (t_paths*)malloc(sizeof(t_paths))))
		return (NULL);
	new->way = way;
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

	paths =  NULL;

	if (way = ft_bfs(paths, rm, matrix))
		paths = ft_newpath(paths, way);
}
