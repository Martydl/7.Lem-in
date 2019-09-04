/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:32:27 by mde-laga          #+#    #+#             */
/*   Updated: 2019/09/04 17:34:05 by mde-laga         ###   ########.fr       */
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
			b = ft_addtoq(bfs, b);
		else
			b++;
}

static int		**ft_filllane(t_bfs *bfs, int start, int *cflct)
{
	int		**lane;
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
	if (!(lane = (int**)malloc(sizeof(int*) * 2)))
		return (ft_freebfs(bfs));
	if (!(lane[0] = (int*)malloc(sizeof(int) * (i + 1))))
		return (ft_freebfs(bfs));
	if (!(lane[1] = (int*)malloc(sizeof(int) * (i + 1))))
		return (ft_freebfs(bfs));
	lane[0][i] = -1;
	lane[1][i] = -1;
	j = 0;
	while (j != start)
	{
		lane[0][--i] = j;
		lane[1][i] = 0;
		j != 0 ? cflct[j] = 1 : 1;
		j = bfs->link[j];
	}
	lane[0][--i] = start;
	lane[1][i] = 0;
	ft_freebfs(bfs);
	return (lane);
}

int				**ft_bfs(int start, int **matrix, int *cflct, t_rm *rm)
{
	t_bfs	*bfs;

	if (cflct[start] == 1)
		return (NULL);
	bfs = ft_setbfs(rm, start);
	cflct[start] = 1;
	while (bfs->room != 0)
	{
		ft_scan(bfs, matrix, cflct);
		if (!bfs->q)
			return (ft_freebfs(bfs));
		bfs->room = bfs->q->room;
		ft_deloneq(bfs);
	}
	return (ft_filllane(bfs, start, cflct));
}
