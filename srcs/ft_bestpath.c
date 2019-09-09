/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bestpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:26:24 by mde-laga          #+#    #+#             */
/*   Updated: 2019/09/09 15:30:44 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_path	*ft_startisend(t_path *paths, int ants)
{
	t_path *ret;

	if (ft_lanelen(paths->way->lane[0]) == 1)
	{
		ret = paths;
		paths = paths->next;
	}
	else
	{
		ret = paths->next;
		paths->next = paths->next->next;
	}
	ft_free_paths(paths);
	ret->way->ants = ants;
	ret->next = NULL;
	return (ret);
}

static void		ft_sortway(t_way *way)
{
	t_way	*beg;
	int		**tmp;

	beg = way;
	way->length = ft_lanelen(way->lane[0]);
	while (way->next)
	{
		way->length = ft_lanelen(way->lane[0]);
		way->next->length = ft_lanelen(way->next->lane[0]);
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

static void		ft_fillway(t_way *way, int ants)
{
	t_way	*beg;
	int		last;
	int		i;

	ft_sortway(way);
	beg = way;
	while (ants)
	{
		last = 1;
		i = 0;
		while (way->next && way->ants + way->length
			>= way->next->ants + way->next->length)
		{
			way = way->next;
			last++;
		}
		way = beg;
		while (ants && i++ < last)
		{
			way->ants++;
			way = way->next;
			ants--;
		}
		way = beg;
	}
}

static void		ft_delpath(t_path *path)
{
	t_way	*tmp;

	while (path->way)
	{
		free(path->way->lane[0]);
		free(path->way->lane[1]);
		free(path->way->lane);
		tmp = path->way;
		path->way = path->way->next;
		free(tmp);
	}
	free(path);
}

t_path			*ft_bestpath(t_path *paths, int ants)
{
	t_path	*tmp;

	ft_fillway(paths->way, ants);
	if (ft_lanelen(paths->way->lane[0]) == 1)
		return (ft_startisend(paths, ants));
	while (paths->next)
	{
		ft_fillway(paths->next->way, ants);
		if (ft_lanelen(paths->next->way->lane[0]) == 1)
			return (ft_startisend(paths, ants));
		if ((long)paths->way->ants + (long)paths->way->length
			> (long)paths->next->way->ants + (long)paths->next->way->length)
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
	ft_delway(paths);
	return (paths);
}
