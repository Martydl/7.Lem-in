/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:28:01 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/31 07:11:03 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		*ft_getstart(int **matrix, t_rm *rm)
{
	int		*ret;
	int		nbroom;
	int		i;
	int		j;
	int		k;

//	if (matrix[1][1] <= matrix[0][0] && (i = 1))
	i = 1;
	j = matrix[1][1];
//	if (matrix[1][1] > matrix[0][0] && (i = 0))
//		j = matrix[0][0];
	if (!(ret = (int*)malloc(sizeof(int) * (j + 1))))
		return (NULL);
	ret[j] = -1;
	nbroom = ft_nbroom(rm);
	j = 0;
	k = -1;
	while (j < nbroom)
		if (matrix[i][j] < 0)
			j -= matrix[i][j];
		else if (i == j)
			j++;
		else
			ret[++k] = j++;
	return (ret);
}

int		*ft_initcflct(t_rm *rm)
{
	int		*cflct;
	int		nbroom;
	int		i;

	nbroom = ft_nbroom(rm);
	if (!(cflct = (int*)malloc(sizeof(int) * nbroom)))
		return (NULL);
	i = -1;
	while (++i < nbroom)
		cflct[i] = -1;
	return (cflct);
}

t_algo	*ft_initalgo(int **matrix, t_rm *rm)
{
	t_algo	*al;

	if (!(al = (t_algo*)malloc(sizeof(t_algo))))
		return (NULL);
	al->start = ft_getstart(matrix, rm);
	return (al);
}

void	ft_delway(t_path *path)
{
	t_way	*tmp;
	t_way	*beg;

	beg = path->way;
	while (path->way->next && path->way->next->ants != 0)
		path->way = path->way->next;
	while (path->way->next)
	{
		tmp = path->way->next;
		path->way->next = path->way->next->next;
		free(tmp->lane);
		free(tmp);
	}
	path->way->next = NULL;
	path->way = beg;
}
