/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:32:27 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/21 14:13:05 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void		ft_addtoq(t_bfs *bfs, int **matrix)
{
	int		b;
	int		i;
	t_q		*q;
	t_q		*tmp;

	b = 0;
	i = -1;
	tmp = bfs->q;
	while (b < bfs->nbroom)
	{
		while (matrix[bfs->room][b] <= 0)
			b -= matrix[bfs->room][b];
		if (b < bfs->nbroom && bfs->prev[b] < 0)
		{
			bfs->prev[b] = bfs->room;
			if (!(q = (t_q*)malloc(sizeof(t_q))))
				return (NULL);
			q->room = b;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = q;
		}
	}
}

static int		*ft_fill_path(int **prev)
{
	return (NULL);
}

static t_bfs	*ft_setbfs(t_rm *rm)
{
	t_bfs	*bfs;
	int		i;

	i = -1;
	if (!(bfs = (t_bfs*)malloc(sizeof(t_bfs))))
		return (NULL);
	bfs->room = 1;
	bfs->nbroom = ft_nbroom(rm);
	if (!(bfs->prev = (int*)malloc(sizeof(int) * bfs->nbroom)))
		return (NULL);
	while (++i < bfs->nbroom)
		bfs->prev[i] = -1;
	bfs->q = NULL;
	return (bfs);
}

int				*ft_bfs(t_rm *rm, int **matrix)
{
	t_bfs	*bfs;

	bfs = ft_setbfs(rm);
	while (bfs->room != 0)
	{
		ft_addtoq(bfs, matrix);
		if (!bfs->q)
			error();
		bfs->room = bfs->q->room;
		ft_deloneq(bfs);
	}
	return (ft_fill_path(bfs));
}


/*

while
- scan next
	- fill prev if not filled
- get next q

while
- find next b
- if !prev[b]
	- malloc sizeof int prev[b] write room
- q[next] = b

*/
