/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:08:04 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/12 16:23:39 by mde-laga         ###   ########.fr       */
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

int		main(int ac, char **av)
{
	t_rd	*rd;
	t_rm	*room;
	int		**matrix;

	(void)ac;
	(void)av;
	rd = ft_read();
	//ft_display_rd(rd);
	//ft_putchar('\n');
	room = ft_getroom(&rd, 0);
	rm_check(room, rd);
	//ft_display_rm(room);
	matrix = ft_pipe(&rd, room);
	ft_display_matrix(matrix, room);
	ft_free_lemin(rd, room, matrix);
}
