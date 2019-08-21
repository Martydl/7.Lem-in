/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 14:03:15 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/21 14:10:29 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	ft_next(t_rd **rd)
{
	t_rd	*tmp;

	tmp = (*rd);
	(*rd) = ((*rd)->next);
	free(tmp->data);
	free(tmp);
}

int		ft_nbroom(t_rm *room)
{
	int	i;

	i = 0;
	while (room)
	{
		room = room->next;
		i++;
	}
	return (i);
}

int		ft_getpos(t_rm *room, char *name)
{
	int		i;

	i = 0;
	while (room && ft_strcmp(room->data[0], name))
	{
		room = room->next;
		i++;
	}
	return (i);
}

void	ft_deloneq(t_bfs *bfs)
{
	t_q		*tmp;

	tmp = bfs->q;
	bfs->q = bfs->q->next;
	free(tmp);
}
