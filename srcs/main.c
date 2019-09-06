/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:08:04 by mde-laga          #+#    #+#             */
/*   Updated: 2019/09/06 16:53:44 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	ft_display_rd(t_rd *rd)
{
	while (rd)
	{
		ft_putendl(rd->data);
		rd = rd->next;
	}
	ft_putchar('\n');
}

void	ft_display_rm(t_rm *rm)
{
	while (rm)
	{
		ft_putendl(rm->data[0]);
		rm = rm->next;
	}
}

void	ft_display_path(t_path *path)
{
	int		i;
	t_way	*beg;

	while (path)
	{
		beg = path->way;
		while (path->way)
		{
			ft_printf("%1k%5d%0k", path->way->ants);
			i = -1;
			while (path->way->lane[0][++i] != -1)
				ft_printf("%10d", path->way->lane[0][i]);
			ft_putchar('\n');
			path->way = path->way->next;
		}
		ft_putchar('\n');
		path->way = beg;
		path = path->next;
	}
}

int		main(void)
{
	int		ants;
	t_rd	*rd;
	t_rm	*rm;
	int		**matrix;
	t_path	*paths;

	rd = ft_read();
	if (!rd)
		ft_error(NULL, NULL, NULL);
	ft_display_rd(rd);
	ants = ft_getants(&rd);
	rm = ft_getroom(&rd, 0, 0);
	rm = ft_push_front(rm, 1, rd);
	rm = ft_push_front(rm, -1, rd);
	if (!rm_check(rm, rd))
		ft_error(rd, rm, NULL);
	matrix = ft_matrix(&rd, rm);
	//ft_display_matrix(matrix, rm);
	paths = ft_getpaths(rm, matrix);
	if (!paths)
		ft_error(NULL, rm, matrix);
	paths = ft_bestpath(paths, ants);
	//ft_display_path(paths);
	ft_doit(paths->way, rm, ants);
	ft_free_lemin(NULL, rm, matrix, paths);
	return (0);
}
