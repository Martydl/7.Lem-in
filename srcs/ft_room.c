/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 14:00:28 by mde-laga          #+#    #+#             */
/*   Updated: 2019/09/09 17:23:41 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

static t_rm		*ft_makeroom(t_rd **rd, int pos, int start, int end)
{
	t_rm	*rm;

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
	return (rm);
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
			rm = ft_makeroom(rd, pos, start, end);
		else
			return (NULL);
	}
	return (rm);
}

static t_rm		*ft_push_front(t_rm *rm, int pos, t_rd *rd, t_dsp *dsp)
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
			ft_error(rd, beg, NULL, dsp);
		tmp->next = rm->next;
		rm->next = beg;
	}
	if (pos == 1)
		rm = ft_push_front(rm, -1, rd, dsp);
	return (rm);
}

t_rm			*rm_check(t_rm *rm, t_rd *rd, t_dsp *dsp)
{
	t_rm *ret;

	rm = ft_push_front(rm, 1, rd, dsp);
	ret = rm;
	while (rd && rd_iscom(rd->data))
	{
		if (rd_isstart(rd->data) || rd_isend(rd->data))
			ft_error(rd, rm, NULL, dsp);
		rd = rd->next;
	}
	(!rd || !rd_ispipe(rd->data)) ? ft_error(rd, rm, NULL, dsp) : 0;
	if (!ft_check_dup(rm))
		ft_error(rd, rm, NULL, dsp);
	return (ret);
}
