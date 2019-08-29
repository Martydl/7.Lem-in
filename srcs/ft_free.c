/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:39:44 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/29 14:45:54 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	ft_free_rd(t_rd *beg)
{
	if (beg)
	{
		if (beg->next)
			ft_free_rd(beg->next);
		free(beg->data);
		free(beg);
	}
}

static void	ft_free_rm(t_rm *rm)
{
	int		i;

	if (rm)
	{
		if (rm->next)
			ft_free_rm(rm->next);
		i = -1;
		while (rm->data[++i])
			free(rm->data[i]);
		free(rm->data);
		free(rm);
	}
}

static void	ft_free_matrix(int **matrix, t_rm *rm)
{
	int i;

	i = ft_nbroom(rm);
	while (--i >= 0)
		free(matrix[i]);
	free(matrix);
}

static void	ft_free_paths(t_path *paths)
{
	t_path	*tmp;
	t_way	*tmp2;

	while (paths)
	{
		while (paths->way)
		{
			free(paths->way->lane);
			tmp2 = paths->way;
			paths->way = paths->way->next;
			free(tmp2);
		}
		tmp = paths;
		paths = paths->next;
		free(tmp);
	}
}

void		ft_free_lemin(t_rd *rd, t_rm *rm, int **matrix, t_path *paths)
{
	if (matrix)
		ft_free_matrix(matrix, rm);
	if (rm)
		ft_free_rm(rm);
	if (rd)
		ft_free_rd(rd);
	if (paths)
		ft_free_paths(paths);
}
