/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 13:56:19 by mde-laga          #+#    #+#             */
/*   Updated: 2019/09/09 15:35:46 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	**ft_initmatrix(t_rm *room)
{
	int		**matrix;
	int		nbroom;
	int		i;
	int		j;

	nbroom = ft_nbroom(room);
	if (!(matrix = (int**)malloc(sizeof(int*) * nbroom)))
		return (NULL);
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

static int	ft_fill(int **matrix, t_rd *rd, t_rm *rm, t_dsp *dsp)
{
	char	**name;
	int		a;
	int		b;

	if (!(name = ft_strsplit(rd->data, '-')))
		ft_error(rd, rm, matrix, dsp);
	a = ft_getpos(rm, name[0]);
	b = ft_getpos(rm, name[1]);
	free(name[0]);
	free(name[1]);
	free(name);
	if (a == ft_nbroom(rm) || b == ft_nbroom(rm))
		return (0);
	if (matrix[a][b] == -1 && a != b)
	{
		matrix[a][a] += 1;
		matrix[b][b] += 1;
		matrix[a][b] = 1;
		matrix[b][a] = 1;
	}
	return (1);
}

static void	ft_optimatrix(int **matrix, t_rm *rm)
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

int			**ft_matrix(t_rd **rd, t_rm *rm, t_dsp *dsp)
{
	int		**matrix;

	if (!(matrix = ft_initmatrix(rm)))
		ft_error(*rd, rm, matrix, dsp);
	while (*rd)
	{
		if (rd_ispipe((*rd)->data))
		{
			if (!ft_fill(matrix, *rd, rm, dsp))
				break ;
			ft_next(rd);
		}
		else if (rd_iscom((*rd)->data))
			ft_next(rd);
		else
			break ;
	}
	ft_optimatrix(matrix, rm);
	if (dsp->matrix)
		ft_display_matrix(matrix, rm);
	ft_free_rd(*rd);
	return (matrix);
}
