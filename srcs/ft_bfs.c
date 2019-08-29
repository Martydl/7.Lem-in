/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:32:27 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/29 15:16:26 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int		ft_addtoq(t_bfs *bfs, int b)
{
	t_queue		*q;
	t_queue		*tmp;

	bfs->link[b] = bfs->room;
	if (!(q = (t_queue*)malloc(sizeof(t_queue))))
		return (0);
	q->room = b;
	q->next = NULL;
	if (!bfs->q)
		bfs->q = q;
	else
	{
		tmp = bfs->q;
		while (bfs->q->next)
			bfs->q = bfs->q->next;
		bfs->q->next = q;
		bfs->q = tmp;
	}
	b++;
	return (b);
}

static void		ft_scan(t_bfs *bfs, int **matrix, int *cflct)
{
	int		b;
	int		i;

	b = 0;
	i = -1;
	while (b < bfs->nbroom)
		if (matrix[bfs->room][b] < 0)
			b -= matrix[bfs->room][b];
		else if (b == bfs->room)
			b++;
		else if (bfs->link[b] < 0 && cflct[b] < 0)
		{
			if (b != 0)
				cflct[b] = 1;
			b = ft_addtoq(bfs, b);
		}
		else
			b++;
}

static int		*ft_filllane(t_bfs *bfs, int start)
{
	int		*lane;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j != start)
	{
		j = bfs->link[j];
		i++;
	}
	i++;
	if (!(lane = (int*)malloc(sizeof(int) * (i + 1))))
		return (NULL);
	lane[i] = -1;
	j = 0;
	while (j != start)
	{
		lane[--i] = j;
		j = bfs->link[j];
	}
	lane[--i] = start;
	ft_freebfs(bfs);
	return (lane);
}

int				*ft_bfs(int start, int **matrix, int *cflct, t_rm *rm)
{
	t_bfs	*bfs;

	bfs = ft_setbfs(rm, start);
	while (bfs->room != 0)
	{
		ft_scan(bfs, matrix, cflct);
		if (!bfs->q)
		{
			ft_freebfs(bfs);
			return (NULL);
		}
		bfs->room = bfs->q->room;
		ft_deloneq(bfs);
	}
	return (ft_filllane(bfs, start));
}
