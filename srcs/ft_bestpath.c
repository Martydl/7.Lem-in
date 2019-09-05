/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bestpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:26:24 by mde-laga          #+#    #+#             */
/*   Updated: 2019/09/05 14:22:44 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	ft_sortways(t_way *way)
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

static void	ft_fillway(t_way *way, int ants)
{
	t_way	*beg;

	ft_sortways(way);
	beg = way;
	while (ants)
	{
		while (way && way->next && way->ants + way->length
			> way->next->ants + way->next->length)
			way = way->next;
		way->ants++;
		ants--;
		way = beg;
	}
}

static void	ft_delpath(t_path *path)
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

t_path		*ft_bestpath(t_path *paths, int ants)
{
	t_path	*tmp;

	ft_fillway(paths->way, ants);
	while (paths->next)
	{
		ft_fillway(paths->next->way, ants);
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
