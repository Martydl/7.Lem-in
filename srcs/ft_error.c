/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:58:53 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/12 18:00:29 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static	void	ft_free_rd(t_rd *beg)
{
	if (beg)
	{
		if (beg->next)
			ft_free_rd(beg->next);
		free(beg->data);
		free(beg);
	}
}

static	void	ft_free_rm(t_rm *rm)
{
	int		i;

	if (rm)
	{
		if (rm->next)
			ft_free_rm(rm->next);
		i = -1;
		while (rm->data[++i])
			free(rm->data[i]);
		free(rm->data);
		free(rm);
	}
}

static	void	ft_free_matrix(int **matrix, t_rm *rm)
{
	int i;

	i = ft_nbroom(rm);
	while (--i >= 0)
		free(matrix[i]);
	free(matrix);
}

void			ft_free_lemin(t_rd *rd, t_rm *rm, int **matrix)
{
	if (matrix)
		ft_free_matrix(matrix, rm);
	if (rm)
		ft_free_rm(rm);
	if (rd)
		ft_free_rd(rd);
}

void			ft_error_lemin(t_rd *rd, t_rm *rm, int **matrix)
{
	ft_free_lemin(rd, rm, matrix);
	ft_printf("%1kERROR%0k\n");
	exit(-1);
}
