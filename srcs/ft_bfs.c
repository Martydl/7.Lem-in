/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:32:27 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/28 16:57:05 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int		ft_addtoq(t_bfs *bfs, int b)
{
	t_queue		*q;
	t_queue		*tmp;

	bfs->prev[b] = bfs->room;
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

void	ft_putq(t_queue *q)
{
	if (q)
	{
		dprintf(1, "%5d", q->room);
		q = q->next;
	}
}

static void		ft_scan(t_bfs *bfs, int **matrix, int *conflicts)
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
		else if (bfs->prev[b] < 0 && conflicts[b] < 0)
		{
			conflicts[b] = 1;
			b = ft_addtoq(bfs, b);
		}
		else
			b++;
}

/*void	ft_puttab(int *tab)
{
	int i = -1;

	while (tab[++i] >= 0)
		dprintf(1, "%5d", tab[i]);
	dprintf(1, "%5d", tab[i]);
	ft_putchar('\n');
}*/

static int		*ft_filllane(t_bfs *bfs, int start)
{
	int		*lane;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j != start)
	{
		j = bfs->prev[j];
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
		j = bfs->prev[j];
	}
	lane[--i] = start;
	ft_freebfs(bfs);
	return (lane);
}

int				*ft_bfs(int start, int **matrix, int *conflicts, t_rm *rm)
{
	t_bfs	*bfs;

	bfs = ft_setbfs(rm, start);
	while (bfs->room != 0)
	{
		ft_scan(bfs, matrix, conflicts);
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
