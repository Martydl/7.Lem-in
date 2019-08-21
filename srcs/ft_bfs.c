/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:32:27 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/21 17:34:03 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int		ft_addtoq(t_bfs *bfs, int b)
{
	t_q		*q;
	t_q		*tmp;

	bfs->prev[b] = bfs->room;
	if (!(q = (t_q*)malloc(sizeof(t_q))))
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

static void		ft_scan(t_bfs *bfs, int **matrix)
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
		else if (bfs->prev[b] < 0)
			b = ft_addtoq(bfs, b);
		else
			b++;
}

static int		*ft_fill_path(t_bfs *bfs)
{
	int		*path;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j != 1)
	{
		j = bfs->prev[j];
		i++;
	}
	if (!(path = (int*)malloc(sizeof(int) * (i + 1))))
		return (NULL);
	path[i] = -1;
	j = 0;
	while (j != 1)
	{
		path[--i] = j;
		j = bfs->prev[j];
	}
	ft_freebfs(bfs);
	return (path);
}

int				*ft_bfs(t_rm *rm, int **matrix)
{
	t_bfs	*bfs;

	bfs = ft_setbfs(rm);
	while (bfs->room != 0)
	{
		ft_scan(bfs, matrix);
		if (!bfs->q)
			ft_error_lemin(NULL, rm, matrix);
		bfs->room = bfs->q->room;
		ft_deloneq(bfs);
	}
	return (ft_fill_path(bfs));
}
