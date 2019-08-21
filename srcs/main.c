/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:08:04 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/21 17:01:10 by mde-laga         ###   ########.fr       */
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

void	ft_display_path(int *path)
{
	int i;

	i = -1;
	while (path[++i] != -1)
		ft_printf("%d\n", path[i]);
}

int		main(int ac, char **av)
{
	int		ants;
	t_rd	*rd;
	t_rm	*rm;
	int		**matrix;
	int		*path;

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
	//ft_display_matrix(matrix, rm);

	//(void)path;
	path = ft_bfs(rm, matrix);
	ft_display_path(path);
	free(path);

	ft_free_lemin(rd, rm, matrix);
}
