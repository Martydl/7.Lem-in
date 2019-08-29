/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 11:59:56 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/29 14:22:59 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*void	ft_puttab(int *tab)
{
	int i = -1;
	while (tab[++i] >= 0)
		dprintf(1, "%5d", tab[i]);
	dprintf(1, "%5d", tab[i]);
}*/

t_way	*ft_newway(t_way *way, int *lane)
{
	t_way *ret;
	t_way *new;

	if  (!(new = (t_way*)malloc(sizeof(t_way))))
		return (NULL);
	new->lane = lane;
	new->ants = 0;
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
	int		j;

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
		j = i;
		while (1)
		{
			if ((algo->lane = ft_bfs(algo->start[j], matrix, algo->conflicts, rm)))
				algo->way = ft_newway(algo->way, algo->lane);
			j++;
			if (algo->start[j] == -1)
				j = 0;
			if (j == i)
				break ;
			//dprintf(1, "là\n");
		}
		free(algo->conflicts);
		paths = ft_newpath(paths, algo->way);
	}
	free(algo->start);
	free(algo);
	return (paths);
}

int		ft_lanelen(int *lane)
{
	int i;

	i = 0;
	while (lane[i] != -1)
		i++;
	return (i);
}

void	ft_sortways(t_way *way)
{
	t_way	*beg;
	int		*tmp;

	beg = way;
	way->length = ft_lanelen(way->lane);
	while (way->next)
	{
		way->length = ft_lanelen(way->lane);
		way->next->length = ft_lanelen(way->next->lane);
		if (way->length > way->next->length)
		{
			tmp = way->lane;
			way->lane = way->next->lane;
			way->next->lane = tmp;
			way = beg;
		}
		else
			way = way->next;
	}
}

void	ft_fillway(t_way *way, int ants)
{
	t_way	*beg;

	ft_sortways(way);
	beg = way;
	while (ants)
	{
		while (way && way->next && way->ants + way->length > way->next->ants + way->next->length)
			way = way->next;
		way->ants++;
		ants--;
		way = beg;
	}
}

void	ft_delpath(t_paths *path)
{
	t_way	*tmp;

	while (path->way)
	{
		free(path->way->lane);
		tmp = path->way;
		path->way = path->way->next;
		free(tmp);
	}
	free(path);
}

t_paths	*ft_bestpath(t_paths *paths, int ants)
{
	t_paths	*tmp;

	ft_fillway(paths->way, ants);
	while (paths->next)
	{
		ft_fillway(paths->next->way, ants);
		if (paths->way->ants + paths->way->length > paths->next->way->ants + paths->next->way->length)
		{
			tmp = paths;
			paths = paths->next;
		}
		else
		{
			tmp = paths->next;
			paths->next = paths->next->next;
		}
		ft_delpath(tmp);
	}
	return (paths);
}
