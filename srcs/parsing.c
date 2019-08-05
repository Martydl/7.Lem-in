/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:08:22 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/05 18:16:51 by mde-laga         ###   ########.fr       */
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
	free(tmp);
}

int		ft_getants(t_rd **rd)
{
	int		ants;

	while ((*rd))
	{
		if (rd_isstart((*rd)->data) || rd_isend((*rd)->data))
			ft_err();
		else if (rd_iscom((*rd)->data))
			ft_next(rd);
		else if (ft_isint((*rd)->data))
		{
			ants = ft_atoi((*rd)->data);
			ft_next(rd);
			return (ants);
		}
		else
			ft_err();
	}
	return (0);
}

t_rm	*ft_getroom(t_rd **rd)
{
	t_rm	*room;
	t_rm	*ret;

	ret = NULL;
	while ((*rd))
	{
		/*if (rd_isstart((*rd)->data) || rd_isend((*rd)->data))
		{}
		else */if (rd_iscom((*rd)->data))
		{
			ft_next(rd);
			ft_putendl("next");
		}
		else if (rd_isroom((*rd)->data))
		{
			if (!(room = (t_rm*)malloc(sizeof(t_rm))))
				return (NULL);
			room->data = ft_strsplit((*rd)->data, ' '); // potentiellement broken ici
			if (!ret)
			{
				ft_putendl("ret init");
				ret = room;
			}
			/*if (!rm_check(ret, room))
			{
				ft_putendl("x");
				ft_err();
			}*/
			//dprintf(1, "%s\n%s\n%s\n", room->data[0], room->data[1], room->data[2]);
			//ft_putendl(room->data[0]);
			room = room->next;
			ft_next(rd);
		}
		else if (rd_ispipe((*rd)->data))
		{
			ft_putendl("break");
			break ;
		}
		else
			ft_err();
	}
	dprintf(1, "A\n");
	while (ret && ret->data)
	{
		dprintf(1, "B\n");
		ft_putendl(ret->data[0]);
		ret = ret->next;
	}
	//ft_display_rm(ret);
	return (ret);
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

void	ft_fill(int ***matrix, t_rd **rd, t_rm *room)
{
	char	**name;
	int		a;
	int		b;

	name = ft_strsplit((*rd)->data, '-');
	a = ft_getpos(room, name[0]);
	free(name[0]);
	b = ft_getpos(room, name[1]);
	free(name[1]);
	free(name);
	if (*matrix[a][b] == 0)
	{
		*matrix[a][a] += 1;
		*matrix[b][b] += 1;
	}
	*matrix[a][b] = -1;
	*matrix[b][a] = -1;
}

int		**ft_pipe(t_rd **rd, t_rm *room)
{
	int		**matrix;

	matrix = ft_initmatrix(room);
	while (*rd)
	{
		if (rd_ispipe((*rd)->data))
		{
			ft_fill(&matrix, rd, room);
			ft_next(rd);
		}
		else if (rd_iscom((*rd)->data))
			ft_next(rd);
		else
			break ;
	}
	/*if (!ft_isenough())
		ft_error();*/
	return (matrix);
}

void	ft_displaymatrix(int **matrix, t_rm *room)
{
	t_rm	*cp;
	int		i;
	int		j;

	ft_printf("%5s", "");
	while (room->data)
	{
		ft_printf("%5s", room->data);
		room = room->next;
	}
	i = -1;
	while (matrix[++i])
	{
		ft_printf("\n%5s", cp->data);
		cp = cp->next;
		j = -1;
		while (matrix[i][++j])
			ft_printf("%5d", matrix[i][j]);
	}
}
