/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:25:48 by mde-laga          #+#    #+#             */
/*   Updated: 2019/09/05 14:35:24 by mde-laga         ###   ########.fr       */
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
	if (!(bfs->link = (int*)malloc(sizeof(int) * bfs->nbroom)))
		return (NULL);
	if (!(bfs->dont = (int*)malloc(sizeof(int) * bfs->nbroom)))
		return (NULL);
	while (++i < bfs->nbroom)
	{
		bfs->link[i] = -1;
		bfs->dont[i] = -1;
	}
	bfs->link[1] = 1;
	bfs->q = NULL;
	return (bfs);
}

int		**ft_initlane(int i)
{
	int **lane;

	if (!(lane = (int**)malloc(sizeof(int*) * 2)))
		return (NULL);
	if (!(lane[0] = (int*)malloc(sizeof(int) * (i + 1))))
		return (NULL);
	if (!(lane[1] = (int*)malloc(sizeof(int) * (i + 1))))
		return (NULL);
	lane[0][i] = -1;
	lane[1][i] = -1;
	return (lane);
}

void	*ft_freebfs(t_bfs *bfs)
{
	t_queue		*tmp;

	free(bfs->link);
	free(bfs->dont);
	while (bfs->q)
	{
		tmp = bfs->q;
		bfs->q = bfs->q->next;
		free(tmp);
	}
	free(bfs);
	return (NULL);
}

void	ft_deloneq(t_bfs *bfs)
{
	t_queue		*tmp;

	tmp = bfs->q;
	bfs->q = bfs->q->next;
	free(tmp);
}
