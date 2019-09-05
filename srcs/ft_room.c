/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 14:00:28 by mde-laga          #+#    #+#             */
/*   Updated: 2019/09/05 14:16:55 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int		ft_checkpos(t_rd **rd, int start, int end)
{
	int ret;

	ret = 0;
	if (rd_isstart((*rd)->data))
		ret = 1;
	else if (rd_isend((*rd)->data))
		ret = -1;
	if (ret == 0 || (ret == 1 && start == 0) || (ret == -1 && end == 0))
		ft_next(rd);
	return (ret);
}

t_rm			*ft_getroom(t_rd **rd, int start, int end)
{
	t_rm	*rm;
	int		pos;

	rm = NULL;
	pos = 0;
	if (*rd)
	{
		while (rd_iscom((*rd)->data))
		{
			pos = ft_checkpos(rd, start, end);
			if (pos == 1 && start == 0 && (start = 1))
				break ;
			else if (pos == -1 && end == 0 && (end = 1))
				break ;
			else if (pos != 0)
				return (NULL);
		}
		if (rd_isroom((*rd)->data) && (*rd)->data[0] != 'L')
		{
			if (!(rm = (t_rm*)malloc(sizeof(t_rm))))
				return (NULL);
			if (!(rm->data = ft_strsplit((*rd)->data, ' ')))
			{
				free(rm);
				return (NULL);
			}
			rm->pos = pos;
			ft_next(rd);
			rm->next = ft_getroom(rd, start, end);
		}
		else
			return (NULL);
	}
	return (rm);
}

int				rm_check(t_rm *rm, t_rd *rd)
{
	t_rm *beg;

	if (!rm)
		return (0);
	while (rd && rd_iscom(rd->data))
	{
		if (rd_isstart(rd->data) || rd_isend(rd->data))
			return (0);
		rd = rd->next;
	}
	if (!rd || !rd_ispipe(rd->data))
		return (0);
	beg = rm;
	while (beg)
	{
		rm = beg->next;
		while (rm)
		{
			if (!ft_strcmp(beg->data[0], rm->data[0]))
				return (0);
			rm = rm->next;
		}
		beg = beg->next;
	}
	return (1);
}

t_rm			*ft_push_front(t_rm *rm, int pos, t_rd *rd)
{
	t_rm *beg;
	t_rm *tmp;

	(void)rd;
	beg = rm;
	if (rm && rm->pos != pos)
	{
		while (rm && rm->pos != pos)
		{
			tmp = rm;
			rm = rm->next;
		}
		if (!rm)
			ft_error(rd, beg, NULL);
		tmp->next = rm->next;
		rm->next = beg;
	}
	return (rm);
}
