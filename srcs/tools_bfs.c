/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:25:48 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/28 15:34:34 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_bfs	*ft_setbfs(t_rm *rm, int start)
{
	t_bfs	*bfs;
	int		i;

	i = -1;
	if (!(bfs = (t_bfs*)malloc(sizeof(t_bfs))))
		return (NULL);
	bfs->room = start;
	bfs->nbroom = ft_nbroom(rm);
	if (!(bfs->prev = (int*)malloc(sizeof(int) * bfs->nbroom)))
		return (NULL);
	while (++i < bfs->nbroom)
		bfs->prev[i] = -1;
	bfs->prev[1] = 1;
	bfs->q = NULL;
	return (bfs);
}

void	ft_freebfs(t_bfs *bfs)
{
	t_queue		*tmp;

	free(bfs->prev);
	while (bfs->q)
	{
		tmp = bfs->q;
		bfs->q = bfs->q->next;
		free(tmp);
	}
	free(bfs);
}

void	ft_deloneq(t_bfs *bfs)
{
	t_queue		*tmp;

	tmp = bfs->q;
	bfs->q = bfs->q->next;
	free(tmp);
}
