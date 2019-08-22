/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 13:56:19 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/22 12:38:28 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int	**ft_initmatrix(t_rm *room)
{
	int		**matrix;
	int		nbroom;
	int		i;
	int		j;

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
		{
			if (i == j)
				matrix[i][j] = 0;
			else
				matrix[i][j] = -1;
		}
	}
	return (matrix);
}

static void	ft_fill(int **matrix, t_rd *rd, t_rm *room)
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
	if (matrix[a][b] == -1)
	{
		matrix[a][a] += 1;
		matrix[b][b] += 1;
		matrix[a][b] = 1;
		matrix[b][a] = 1;
	}
}

int			**ft_matrix(t_rd **rd, t_rm *room)
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

void		ft_optimatrix(int **matrix, t_rm *rm)
{
	int		nb;
	int		i;
	int		j;

	nb = ft_nbroom(rm);
	i = nb;
	while (--i >= 0)
	{
		j = nb;
		while (--j >= 0)
			if (j + 1 != nb && matrix[i][j] < 0 && matrix[i][j + 1] < 0)
				matrix[i][j] = matrix[i][j + 1] - 1;
	}
}
