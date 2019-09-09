/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:08:04 by mde-laga          #+#    #+#             */
/*   Updated: 2019/09/09 11:32:14 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	ft_error(t_rd *rd, t_rm *rm, int **matrix)
{
	ft_free_lemin(rd, rm, matrix, NULL);
	ft_printf("%1kERROR%0k\n");
	exit(-1);
}

int		main(void)
{
	int		ants;
	t_rd	*rd;
	t_rm	*rm;
	int		**matrix;
	t_path	*paths;

	if (!(rd = ft_read()))
		ft_error(NULL, NULL, NULL);
	ft_display_rd(rd);
	ants = ft_getants(&rd);
	if (!(rm = ft_getroom(&rd, 0, 0)))
		ft_error(rd, NULL, NULL);
	rm = rm_check(rm, rd);
	matrix = ft_matrix(&rd, rm);
	//ft_display_matrix(matrix, rm);
	if (!(paths = ft_getpaths(rm, matrix)))
		ft_error(NULL, rm, matrix);
	paths = ft_bestpath(paths, ants);
	//ft_display_path(paths);
	ft_doit(paths->way, rm, ants);
	ft_free_lemin(NULL, rm, matrix, paths);
	return (0);
}
