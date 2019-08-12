/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:58:53 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/12 16:12:27 by mde-laga         ###   ########.fr       */
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

/*static	t_rm	*ft_getprev(t_rm *rm)
{
	while (rm->prev)
		rm = rm->prev;
	return (rm);
}*/

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

static	void	ft_free_matrix(int **matrix)
{
	int i;

	i = sizeof(matrix);
	while (--i >= 0)
		free(matrix[i]);
	free(matrix);
}

void			ft_free_lemin(t_rd *rd, t_rm *rm, int **matrix)
{
	if (rd)
		ft_free_rd(rd);
	if (rm)
		ft_free_rm(rm);
	if (matrix)
		ft_free_matrix(matrix);
}

void			ft_error_lemin(t_rd *rd, t_rm *rm, int **matrix)
{
	ft_free_lemin(rd, rm, matrix);
	ft_putendl("Error");
	exit(-1);
}
