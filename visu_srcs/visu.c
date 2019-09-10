/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:14:27 by mde-laga          #+#    #+#             */
/*   Updated: 2019/09/10 15:49:55 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

t_rd	*ft_read(void)
{
	char	*str;
	t_rd	*rd;

	rd = NULL;
	if (get_next_line(0, &str))
	{
		if (str[0])
		{
			if (!(rd = (t_rd*)malloc(sizeof(t_rd))))
				return (NULL);
			rd->data = str;
			rd->next = ft_read();
		}
		else
		{
			free(str);
			return (NULL);
		}
	}
	else
		free(str);
	return (rd);
}

void		ft_display_rd(t_rd *rd)
{
	while (rd)
	{
		ft_putendl(rd->data);
		rd = rd->next;
	}
	ft_putchar('\n');
}

void		ft_free_rd(t_rd *beg)
{
	if (beg)
	{
		if (beg->next)
			ft_free_rd(beg->next);
		free(beg->data);
		free(beg);
	}
}

void	ft_next(t_rd **rd)
{
	t_rd	*tmp;

	tmp = (*rd);
	(*rd) = ((*rd)->next);
	free(tmp->data);
	free(tmp);
}

static t_rm		*ft_makeroom(t_rd **rd, int pos, int start, int end)
{
	t_rm	*rm;
	char	**split;

	if (!(rm = (t_rm*)malloc(sizeof(t_rm))))
		return (NULL);
	if (!(split = ft_strsplit((*rd)->data, ' ')))
	{
		free(rm);
		return (NULL);
	}
	rm->name = split[0];
	rm->x = ft_atoi(split[1]);
	rm->y = ft_atoi(split[2]);
	rm->pos = pos;
	free(split[1]);
	free(split[2]);
	free(split);
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

int		ft_getants(t_rd **rd)
{
	int		ants;

	while ((*rd))
	{
		if (rd_isstart((*rd)->data) || rd_isend((*rd)->data))
			ft_error(*rd, NULL, NULL, NULL);
		else if (rd_iscom((*rd)->data))
			ft_next(rd);
		else if (ft_isint((*rd)->data))
		{
			ants = ft_atoi((*rd)->data);
			if (ants <= 0)
				ft_error(*rd, NULL, NULL, NULL);
			ft_next(rd);
			return (ants);
		}
		else
			ft_error(*rd, NULL, NULL, NULL);
	}
	return (0);
}


int		main(void)
{
	t_rd	*info;
	t_rm	*rm;
	t_rd	*instruct;

	info = ft_read();
	rm = ft_getroom(info);
	instruct = ft_read();
	//ft_display_rd(info);
	//ft_display_rd(instruct);
	//ft_free_rd(map);
	//ft_free_rd(instruct);
	return (0);
}
