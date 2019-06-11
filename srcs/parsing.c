/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:08:22 by mde-laga          #+#    #+#             */
/*   Updated: 2019/06/11 16:51:33 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		ft_check_line(char *str)
{
	if (ft_strlen(str) && ft_str_is_alpha(str))
		return (1);
	return (0);
}

t_rd	*ft_read(void)
{
	char	*str;
	t_rd	*rd;

	rd = NULL;
	if (get_next_line(0, &str))
	{
		if (ft_check_line(str))
		{
			if (!(rd = (t_rd*)malloc(sizeof(t_rd))))
				return (NULL);
			rd->line = str;
			rd->next = ft_read();
		}
		else
			free(str);
	}
	else
		free(str);
	return (rd);
}

void	ft_next(t_rd **rd)
{
	t_rd	*tmp;

	tmp = (*rd);
	(*rd) = ((*rd)->next);
	free(tmp);
}

int		ft_getants(t_rd **rd)
{
	int		ants;
	t_rd	*tmp;

	while ((*rd))
	{
		if (rd_isstart() || rd_isend())
			ft_error();
		else if (rd_iscom() || rd_iscmd())
			ft_next(rd);
		else if (ft_isint((*rd)->line))
		{
			ants = ft_atoi((*rd)->line);
			ft_next(rd);
			return (ants);
		}
		else
			ft_error();
	}
	return (NULL);
}

t_rm	*ft_getroom(t_rd **rd)
{
	t_rd	*tmp;
	t_rm	*room;
	t_rm	*ret;

	ret = room;
	while ((*rd))
	{
		if (rd_isstart() || rd_isend())
		{}
		else if (rd_iscom() || rd_iscmd())
			ft_next(rd);
		else if (rd_isroom())
		{
			if (!(room = (t_rm*)malloc(sizeof(t_rm))))
				return (NULL);
			room->data = ft_strsplit((*rd)->line, ' ');
			room = room->next;
			ft_next(rd);
		}
		else
			ft_error();
	}
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

int		**ft_initmatrix(t_rm *room)
{
	int	**matrix;
	int	nbroom;
	int	i;
	int	j;

	nbroom = ft_nbroom(room);
	if (!(matrix = (int**)malloc(sizeof(int) * nbroom)))
		return (0);
	i = -1;
	while (++i < nbroom)
	{
		if (!(matrix[i] = (int*)malloc(sizeof(int) * nbroom)))
			return (NULL);
		j = -1;
		while (++j < nbroom)
			matrix[i][j] = 0;
	}
	return (matrix);
}

void	ft_fill(int ***matrix, t_rd **rd, t_rm *room)
{
	char	**name;
	int		a;
	int		b;

	name = ft_strsplit((*rd)->line, '-');
	a = ft_getpos(room, name[0]);
	free(name[0]);
	b = ft_getpos(room, name[1]);
	free(name[1]);
	free(name);
	if (*matrix[a][b] == 0)
	{
		*matrix[a][a]++;
		*matrix[b][b]++;
	}
	*matrix[a][b] = -1;
	*matrix[b][a] = -1;
}

int		**ft_pipe(t_rd **rd, t_rm *room)
{
	int		**matrix;
	int		i;

	matrix = ft_initmatrix(room);
	while (*rd)
	{
		if (rd_ispipe())
			ft_fill(&matrix, rd, room);
		else if (rd_iscom() || rd_iscmd())
			ft_next(rd);
		else
			break ;
	}
	ft_isenough();
	return (matrix);
}
