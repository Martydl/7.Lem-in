/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:08:04 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/29 14:23:43 by mde-laga         ###   ########.fr       */
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

void	ft_display_path(t_paths *paths)
{
	int i;

	while (paths)
	{
		while (paths->way)
		{
			//ft_printf("%2k%d%0k", paths->way->length);
			ft_printf("%1k%5d%0k", paths->way->ants);
			i = -1;
			while (paths->way->lane[++i] != -1)
				ft_printf("%3d", paths->way->lane[i]);
			ft_putchar('\n');
			paths->way = paths->way->next;
		}
		paths = paths->next;
	}
}

void	ft_free_paths(t_paths *paths)
{
	t_paths	*tmp;
	t_way	*tmp2;

	while (paths)
	{
		while (paths->way)
		{
			free(paths->way->lane);
			tmp2 = paths->way;
			paths->way = paths->way->next;
			free(tmp2);
		}
		tmp = paths;
		paths = paths->next;
		free(tmp);
	}
}

int		main(int ac, char **av)
{
	int		ants;
	t_rd	*rd;
	t_rm	*rm;
	int		**matrix;
	t_paths	*paths;

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
	//ft_display_path(paths);
	ft_delpath(paths);
	//ft_free_paths(paths);

	ft_free_lemin(rd, rm, matrix);
}
