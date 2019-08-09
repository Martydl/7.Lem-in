/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:08:04 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/09 15:58:35 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	ft_err()
{
	ft_putendl("error");
	exit(-1);
}

void	ft_free_rd(t_rd *beg)
{
	if (beg)
	{
		if (beg->next)
			ft_free_rd(beg->next);
		free(beg->data);
		free(beg);
	}
}

void	ft_free_rm(t_rm *beg)
{
	int		i;

	if (beg)
	{
		if (beg->next)
			ft_free_rm(beg->next);
		i= -1;
		while (beg->data[++i])
			free(beg->data[i]);
		free(beg->data);
		free(beg);
	}
}

void	ft_free_matrix(int **matrix)
{
	int i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

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

void	ft_display_matrix(int **matrix, t_rm *room)
{
	t_rm	*cp;
	int		i;
	int		j;
	int		nb;

	cp = room;
	nb = ft_nbroom(room);
	ft_printf("     ");
	while (room && room->data)
	{
		ft_printf("%5s", room->data[0]);
		room = room->next;
	}
	i = -1;
	while (++i < nb)
	{
		ft_printf("\n\n%5s", cp->data[0]);
		cp = cp->next;
		j = -1;
		while (++j < nb)
			ft_printf("%5d", matrix[i][j]);
	}
	ft_putstr("\n\n");
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
	room = ft_getroom(&rd);
	//ft_display_rm(room);
	//ft_printf("\n%d\n", rm_check(room));
	matrix = ft_pipe(&rd, room);
	ft_display_matrix(matrix, room);
	ft_free_rm(room);
	ft_free_rd(rd);
	ft_free_matrix(matrix);
}
