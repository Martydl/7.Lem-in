/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:08:04 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/05 16:50:53 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	ft_free_list(t_rd *beg)
{
	if (beg)
	{
		if (beg->next)
			ft_free_list(beg->next);
		free(beg->line);
		free(beg);
	}
}

void	ft_display_list(t_rd *rd)
{
	while (rd)
	{
		ft_putendl(rd->line);
		rd = rd->next;
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
	ft_display_list(rd);
	room = ft_getroom(&rd);
	matrix = ft_pipe(&rd, room);
	ft_free_list(rd);
}
