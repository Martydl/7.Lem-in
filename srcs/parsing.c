/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:08:22 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/12 18:19:55 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		ft_check_line(char *str)
{
	(void)str;
	return (1);
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
			rd->data = str;
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
	free(tmp->data);
	free(tmp);
}

int		ft_getants(t_rd **rd)
{
	int		ants;

	while ((*rd))
	{
		if (rd_isstart((*rd)->data) || rd_isend((*rd)->data))
			ft_error_lemin(*rd, NULL, NULL);
		else if (rd_iscom((*rd)->data))
			ft_next(rd);
		else if (ft_isint((*rd)->data))
		{
			ants = ft_atoi((*rd)->data);
			ft_next(rd);
			return (ants);
		}
		else
			ft_error_lemin(*rd, NULL, NULL);
	}
	return (0);
}

t_rm	*ft_getroom(t_rd **rd)
{
	t_rm	*rm;
	int		pos;

	rm = NULL;
	pos = 0;
	if (*rd)
	{
		while (rd_iscom((*rd)->data) && !rd_isstart((*rd)->data) && !rd_isend((*rd)->data))
			ft_next(rd);
		if (rd_isstart((*rd)->data))
			pos = 1;
		else if (rd_isend((*rd)->data))
			pos = -1;
		while (rd_iscom((*rd)->data))
			ft_next(rd);
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
	if (!(matrix = (int**)malloc(sizeof(int*) * nbroom)))
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

void	ft_fill(int **matrix, t_rd *rd, t_rm *room)
{
	char	**name;
	int		a;
	int		b;

	name = ft_strsplit(rd->data, '-');
	a = ft_getpos(room, name[0]);
	b = ft_getpos(room, name[1]);
	free(name[0]);
	free(name[1]);
	free(name);
	if (matrix[a][b] == 0)
	{
		matrix[a][a] += 1;
		matrix[b][b] += 1;
		matrix[a][b] = -1;
		matrix[b][a] = -1;
	}
}

int		**ft_pipe(t_rd **rd, t_rm *room)
{
	int		**matrix;

	matrix = ft_initmatrix(room);
	while (*rd)
	{
		if (rd_ispipe((*rd)->data))
		{
			ft_fill(matrix, *rd, room);
			ft_next(rd);
		}
		else if (rd_iscom((*rd)->data))
			ft_next(rd);
		else
			break ;
	}
	/*if (!ft_isenough())
		ft_error_lemin(*rd, room, matrix);*/
	return (matrix);
}
