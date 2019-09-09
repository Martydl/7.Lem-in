/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:40:21 by mde-laga          #+#    #+#             */
/*   Updated: 2019/09/09 15:35:45 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char	**ft_initroom(t_rm *rm)
{
	char	**room;
	int		nbroom;
	int		i;

	nbroom = ft_nbroom(rm);
	if (!(room = (char**)malloc(sizeof(char*) * nbroom)))
		return (NULL);
	i = -1;
	while (++i < nbroom)
	{
		room[i] = ft_strdup(rm->data[0]);
		rm = rm->next;
	}
	return (room);
}

static int	ft_printmove(int **lane, char **room, int space, int i)
{
	if (space == 0 && (space = 1))
		ft_printf("L%d-%s", lane[1][i], room[lane[0][i]]);
	else
		ft_printf(" L%d-%s", lane[1][i], room[lane[0][i]]);
	return (space);
}

static void	ft_moveants(t_way *way, char **room, t_doit *doit, t_dsp *dsp)
{
	int		i;

	while (way)
	{
		i = way->length;
		while (--i > 0)
			if (way->lane[1][i - 1])
			{
				way->lane[1][i] = way->lane[1][i - 1];
				way->lane[1][i - 1] = 0;
				if (dsp->move)
					dsp->space = ft_printmove(way->lane, room, dsp->space, i);
				i == way->length - 1 ? doit->end++ : 0;
			}
		if (way->ants)
		{
			way->lane[1][0] = doit->ants++;
			way->ants--;
			if (dsp->move)
				dsp->space = ft_printmove(way->lane, room, dsp->space, i);
			i == way->length - 1 ? doit->end++ : 0;
		}
		way = way->next;
	}
}

void		ft_doit(t_way *way, t_rm *rm, int ants, t_dsp *dsp)
{
	t_doit	*doit;
	char	**room;

	if (dsp->way)
		ft_display_way(way);
	if (!(doit = (t_doit*)malloc(sizeof(doit))))
		return ;
	doit->ants = 1;
	doit->end = 0;
	room = ft_initroom(rm);
	while (doit->end != ants)
	{
		dsp->space = 0;
		ft_moveants(way, room, doit, dsp);
		if (dsp->move)
			ft_putendl("");
	}
	ft_free_room(room, rm);
	free(doit);
}

void		ft_doitfast(t_way *way, t_rm *rm, int ants, t_dsp *dsp)
{
	char	**room;
	int		i;

	i = 1;
	if (dsp->way)
		ft_display_way(way);
	room = ft_initroom(rm);
	if (dsp->move)
		ft_printf("L%d-%s", i, room[way->lane[0][0]]);
	while (++i <= ants)
		if (dsp->move)
			ft_printf(" L%d-%s", i, room[way->lane[0][0]]);
	if (dsp->move)
		ft_putendl("");
	ft_free_room(room, rm);
}
