/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:32:27 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/20 18:14:50 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		**ft_addtoq(int **prev, int **q, int room, int **matrix)
{
	int		b;

	b = 0;
	while (b)
	{
		while (matrix[room][b] <= 0)
			b -= matrix[room][b];
		if (!prev[b])
		{
			if (!(prev[b] = (int*)malloc(sizeof(int))))
				return (NULL);
			*prev[b] = room;
		}
	}
	return (prev);
}

int		*ft_fill_path(int **prev)
{}

int		*ft_bfs(t_rm *rm, int **matrix, int room)
{
	int		*q;
	int		**prev;

	if (!(q = (int*)malloc(sizeof(int) * ft_nbroom(rm))))
		return (NULL);
	if (!(prev = (int**)malloc(sizeof(int*) * ft_nbroom(rm))))
		return (NULL);
	while (room != 0)
	{
		ft_addtoq(prev, &q, room, matrix);
		room = ft_getq();
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
