/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:08:04 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/29 16:26:38 by mde-laga         ###   ########.fr       */
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
			//ft_printf("%2k%d%0k", path->way->length);
			ft_printf("%1k%5d%0k", path->way->ants);
			i = -1;
			while (path->way->lane[++i] != -1)
				ft_printf("%10d", path->way->lane[i]);
			ft_putchar('\n');
			path->way = path->way->next;
		}
		ft_putchar('\n');
		path->way = beg;
		path = path->next;
	}
}

int		main(int ac, char **av)
{
	int		ants;
	t_rd	*rd;
	t_rm	*rm;
	int		**matrix;
	t_path	*paths;

	(void)ac;
	(void)av;

	rd = ft_read();
	//ft_display_rd(rd);
	//ft_putchar('\n');

	ants = ft_getants(&rd);
	//ft_printf("%d\n\n", ants);

	rm = ft_getroom(&rd);
	rm_check(rm, rd);
	rm = ft_push_front(rm, 1);
	rm = ft_push_front(rm, -1);
	//ft_display_rm(rm);

	matrix = ft_matrix(&rd, rm);
	ft_optimatrix(matrix, rm);
	//ft_display_matrix(matrix, rm);

	//(void)paths;
	paths = ft_getpaths(rm, matrix);
	//dprintf(1, "there\n");
	//ft_sortways(paths->way);
	//ft_sortways(paths->next->way);
	//ft_fillway(paths->next->way, ants);
	paths = ft_bestpath(paths, ants);
	ft_display_path(paths);
	//ft_delpath(paths);
	//ft_free_paths(paths);

	ft_free_lemin(rd, rm, matrix, paths);
}
