/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:11:04 by mde-laga          #+#    #+#             */
/*   Updated: 2019/09/09 16:55:09 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_usage(t_dsp *dsp)
{
	if (dsp)
	{
		free(dsp);
		ft_printf("%1kArguments invalides%0k\n\n");
	}
	ft_printf("Usage : ./lem-in < fichier\n\n");
	ft_printf("Options :\n");
	ft_printf("-m  (matrix) : Affiche la matrice\n");
	ft_printf("-w  (way)    : Affiche le chemin choisi\n");
	ft_printf("-s1 (silent) : Retire l'affichage de la map\n");
	ft_printf("-s2 (silent) : Retire l'affichage des coups\n");
	exit(0);
}

void	ft_parseargs(t_dsp *dsp, char *args)
{
	int i;

	if (args[0] != '-')
		ft_usage(dsp);
	i = 0;
	while (args[++i])
	{
		if (args[i] == 'm')
			dsp->matrix = 1;
		else if (args[i] == 'w')
			dsp->way = 1;
		else if (args[i] == 's')
		{
			i++;
			if (args[i] == '1')
				dsp->rd = 0;
			else if (args[i] == '2')
				dsp->move = 0;
			else
				ft_usage(dsp);
		}
		else
			ft_usage(dsp);
	}
}

void	ft_free_room(char **room, t_rm *rm)
{
	int		nbroom;
	int		i;

	nbroom = ft_nbroom(rm);
	i = -1;
	while (++i < nbroom)
		free(room[i]);
	free(room);
}
