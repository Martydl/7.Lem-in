/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 11:59:56 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/28 17:34:48 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	ft_puttab(int *tab)
{
	int i = -1;
	while (tab[++i] >= 0)
		dprintf(1, "%5d", tab[i]);
	dprintf(1, "%5d", tab[i]);
}

t_way	*ft_newway(t_way *way, int *lane)
{
	t_way *ret;
	t_way *new;

	if  (!(new = (t_way*)malloc(sizeof(t_way))))
		return (NULL);
	new->lane = lane;
	new->next = NULL;
	if (!way)
		return (new);
	else
	{
		ret = way;
		while (way->next)
			way = way->next;
		way->next = new;
	}
	return (ret);
}

t_paths	*ft_newpath(t_paths *paths, t_way *way)
{
	t_paths	*new;
	t_paths	*ret;

	if (!(new = (t_paths*)malloc(sizeof(t_paths))))
		return (NULL);
	new->way = way;
	new->next = NULL;
	if (!paths)
		ret = new;
	else
	{
		ret = paths;
		while (paths->next)
			paths = paths->next;
		paths->next = new;
	}
	//dprintf(1, "here\n");
	return (ret);
}

int		*ft_initconflicts(t_rm *rm)
{
	int		*conflicts;
	int		nbroom;
	int		i;

	nbroom = ft_nbroom(rm);
	if (!(conflicts = (int*)malloc(sizeof(int) * nbroom)))
		return (NULL);
	i = -1;
	while (++i < nbroom)
		conflicts[i] = -1;
	return (conflicts);
}

int		*ft_getstart(int **matrix, t_rm *rm)
{
	int		*ret;
	int		nbroom;
	int		i;
	int		j;
	int		k;

	if (matrix[1][1] <= matrix[0][0])
	{
		i = 1;
		j = matrix[1][1];
	}
	else
	{
		i = 0;
		j = matrix[0][0];
	}
	if (!(ret = (int*)malloc(sizeof(int) * (j + 1))))
		return (NULL);
	ret[j] = -1;
	nbroom = ft_nbroom(rm);
	j = 0;
	k = -1;
	while (j < nbroom)
		if (matrix[i][j] < 0)
			j -= matrix[i][j];
		else if (i == j)
			j++;
		else
			ret[++k] = j++;
	return (ret);
}

t_paths	*ft_getpaths(t_rm *rm, int **matrix)
{
	t_algo	*algo;
	t_paths *paths;
	int		i;

	if (!(algo = (t_algo*)malloc(sizeof(t_algo))))
		return (NULL);
		paths = NULL;
	algo->start = ft_getstart(matrix, rm);
	i = -1;
	while (algo->start[++i] >= 0)
	{
		//dprintf(1, "ici\n");
		algo->way = NULL;
		algo->conflicts = ft_initconflicts(rm);
		while ((algo->lane = ft_bfs(algo->start[i], matrix, algo->conflicts, rm)))
		{
			algo->way = ft_newway(algo->way, algo->lane);
			//dprintf(1, "là\n");
		}
		free(algo->conflicts);
		paths = ft_newpath(paths, algo->way);
	}
	free(algo->start);
	free(algo);
	return (paths);
}
