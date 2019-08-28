/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:08:04 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/28 17:02:38 by mde-laga         ###   ########.fr       */
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
	ft_display_path(paths);
	//ft_free_paths(paths);

	ft_free_lemin(rd, rm, matrix);
}
