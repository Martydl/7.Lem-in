/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:32:27 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/22 12:23:04 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*int		ft_conflicts(t_bfs *bfs, t_paths *paths)
{}*/

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

static int		*ft_fillway(t_bfs *bfs)
{
	int		*way;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j != 1)
	{
		j = bfs->prev[j];
		i++;
	}
	if (!(way = (int*)malloc(sizeof(int) * (i + 1))))
		return (NULL);
	way[i] = -1;
	j = 0;
	while (j != 1)
	{
		way[--i] = j;
		j = bfs->prev[j];
	}
	ft_freebfs(bfs);
	return (way);
}

int				*ft_bfs(t_paths *paths, t_rm *rm, int **matrix)
{
	t_bfs	*bfs;

	(void)paths;
	bfs = ft_setbfs(rm);
	while (bfs->room != 0)
	{
		ft_scan(bfs, matrix);
		if (!bfs->q)
			return (NULL);
		bfs->room = bfs->q->room;
		ft_deloneq(bfs);
	}
	return (ft_fillway(bfs));
}
