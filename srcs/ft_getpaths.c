/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpaths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:26:22 by mde-laga          #+#    #+#             */
/*   Updated: 2019/09/03 11:16:41 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	ft_puttab(int *tab)
{
	int i;

	i = -1;
	while (tab[++i] != -1)
		ft_printf("%5d", tab[i]);
	ft_putchar('\n');
}

static t_way	*ft_newway(t_way *way, int **lane)
{
	t_way	*ret;
	t_way	*new;

	//ft_puttab(lane);
	if (!(new = (t_way*)malloc(sizeof(t_way))))
		return (NULL);
	new->lane = lane;
	new->ants = 0;
	new->next = NULL;
	if (!way)
		return (new);
	else
	{
		ret = way;
		while (way->next)
			way = way->next;
		way->next = new;
	}
	return (ret);
}

static t_path	*ft_newpath(t_path *paths, t_way *way)
{
	t_path	*new;
	t_path	*ret;

	if (!(new = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	new->way = way;
	new->next = NULL;
	if (!paths)
		ret = new;
	else
	{
		ret = paths;
		while (paths->next)
			paths = paths->next;
		paths->next = new;
	}
	return (ret);
}

t_path			*ft_getpaths(t_rm *rm, int **matrix)
{
	t_algo	*al;
	t_path	*paths;

	paths = NULL;
	al = ft_initalgo(matrix, rm);
	al->i = -1;
	while (al->start[++al->i] >= 0)
	{
		al->way = NULL;
		al->cflct = ft_initcflct(rm);
		al->j = al->i;
		while (1)
		{
			if ((al->lane = ft_bfs(al->start[al->j++], matrix, al->cflct, rm)))
				al->way = ft_newway(al->way, al->lane);
			al->start[al->j] == -1 ? al->j = 0 : 1;
			if (al->j == al->i)
				break ;
		}
		free(al->cflct);
		paths = ft_newpath(paths, al->way);
	}
	free(al->start);
	free(al);
	return (paths);
}