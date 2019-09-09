/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:08:04 by mde-laga          #+#    #+#             */
/*   Updated: 2019/09/09 15:36:09 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_error(t_rd *rd, t_rm *rm, int **matrix, t_dsp *dsp)
{
	free(dsp);
	ft_free_lemin(rd, rm, matrix, NULL);
	ft_printf("%1kERROR%0k\n");
	exit(-1);
}

int		main(int ac, char **av)
{
	t_rd	*rd;
	t_rm	*rm;
	int		**matrix;
	t_path	*paths;
	t_dsp	*dsp;

	dsp = ft_initdsp(ac, av);
	if (!(rd = ft_read()))
		ft_error(NULL, NULL, NULL, dsp);
	dsp->rd ? ft_display_rd(rd) : 0;
	dsp->ants = ft_getants(&rd);
	if (!(rm = ft_getroom(&rd, 0, 0)))
		ft_error(rd, NULL, NULL, dsp);
	rm = rm_check(rm, rd, dsp);
	matrix = ft_matrix(&rd, rm, dsp);
	if (!(paths = ft_getpaths(rm, matrix, dsp)))
		ft_error(NULL, rm, matrix, dsp);
	paths = ft_bestpath(paths, dsp->ants);
	if (ft_lanelen(paths->way->lane[0]) == 1)
		ft_doitfast(paths->way, rm, dsp->ants, dsp);
	else
		ft_doit(paths->way, rm, dsp->ants, dsp);
	free(dsp);
	ft_free_lemin(NULL, rm, matrix, paths);
	return (0);
}
