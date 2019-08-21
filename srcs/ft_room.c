/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 14:00:28 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/21 14:14:06 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int		ft_checkpos(t_rd **rd)
{
	int ret;

	ret = 0;
	if (rd_isstart((*rd)->data))
		ret = 1;
	else if (rd_isend((*rd)->data))
		ret = -1;
	ft_next(rd);
	return (ret);
}

t_rm		*ft_getroom(t_rd **rd)
{
	t_rm	*rm;
	int		pos;

	rm = NULL;
	pos = 0;
	if (*rd)
	{
		while (rd_iscom((*rd)->data))
		{
			pos = ft_checkpos(rd);
			if ((pos != 0))
				break ;
		}
		if (rd_isroom((*rd)->data))
		{
			if (!(rm = (t_rm*)malloc(sizeof(t_rm))))
				return (NULL);
			rm->data = ft_strsplit((*rd)->data, ' ');
			rm->pos = pos;
			ft_next(rd);
			rm->next = ft_getroom(rd);
		}
		else
			return (NULL);
	}
	return (rm);
}

t_rm		*ft_push_front(t_rm *rm, int pos)
{
	t_rm *beg;
	t_rm *tmp;

	if (!rm)
		return (NULL);
	beg = rm;
	if (rm && rm->pos != pos)
	{
		while (rm && rm->pos != pos)
		{
			tmp = rm;
			rm = rm->next;
		}
		tmp->next = rm->next;
		rm->next = beg;
	}
	return (rm);
}

int			rm_check(t_rm *room, t_rd *rd)
{
	t_rm *beg;

	while (rd_iscom(rd->data))
		rd = rd->next;
	if (!rd_ispipe(rd->data))
		ft_error_lemin(rd, room);
	if (!room)
		return (0);
	beg = room;
	while (beg)
	{
		room = beg->next;
		while (room)
		{
			if (!ft_strcmp(beg->data[0], room->data[0]))
				return (0);
			room = room->next;
		}
		beg = beg->next;
	}
	return (1);
}
