/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:32:27 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/21 11:26:48 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	ft_addtoq(t_bfs *bfs, int **matrix)
{
	int		b;

	b = 0;
	while (b < bfs->nbroom)
	{
		while (matrix[bfs->room][b] <= 0)
			b -= matrix[bfs->room][b];
		if (b < bfs->nbroom && !bfs->prev[b])
		{
			if (!(bfs->prev[b] = (int*)malloc(sizeof(int))))
				return (NULL);
			*bfs->prev[b] = bfs->room;
		}
	}
}

int		*ft_fill_path(int **prev)
{}

int		*ft_bfs(t_rm *rm, int **matrix)
{
	t_bfs	*bfs;

	if (!(bfs = (t_bfs*)malloc(sizeof(t_bfs))))
		return (NULL);
	bfs->room = 1;
	bfs->nbroom = ft_nbroom(rm);
	if (!(bfs->prev = (int**)malloc(sizeof(int*) * ft_nbroom(rm))))
		return (NULL);
	if (!(bfs->q = (int*)malloc(sizeof(int) * ft_nbroom(rm))))
		return (NULL);
	while (bfs->room != 0)
	{
		ft_addtoq(bfs, matrix);
		bfs->room = ft_getq(bfs);
	}
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
