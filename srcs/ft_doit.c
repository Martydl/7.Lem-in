/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:40:21 by mde-laga          #+#    #+#             */
/*   Updated: 2019/09/03 15:33:31 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

char	**ft_initroom(t_rm *rm)
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

void	ft_moveants(t_way *way, char **room, t_doit *doit, int space)
{
	int		i;

	while (way)
	{
		i = way->length;
		while (--i > 0)
		{
			if (way->lane[1][i - 1])
			{
				way->lane[1][i] = way->lane[1][i - 1];
				way->lane[1][i - 1] = 0;
				if (space == 0 && (space = 1))
					ft_printf("L%d-%s", way->lane[1][i], room[way->lane[0][i]]);
				else
					ft_printf(" L%d-%s", way->lane[1][i], room[way->lane[0][i]]);
				if (i == way->length - 1)
					doit->end++;
			}
		}
		if (doit->ants && way->ants)
		{
			way->lane[1][0] = doit->ants;
			way->ants--;
			doit->ants--;
			if (space == 0 && (space = 1))
				ft_printf("L%d-%s", way->lane[1][i], room[way->lane[0][i]]);
			else
				ft_printf(" L%d-%s", way->lane[1][i], room[way->lane[0][i]]);
			if (i == way->length - 1)
				way->ants--;
			if (i == way->length - 1)
				doit->end++;
		}
		way = way->next;
	}
}

void	ft_display(t_way *way, char **room)
{
	int		i;

	while (way)
	{
		//ft_printf("%2k%d%0k", way->length);
		ft_printf("%1k%5d%0k", way->ants);
		i = -1;
		while (way->lane[0][++i] != -1)
			ft_printf("%10s", room[way->lane[0][i]]);
		ft_putchar('\n');
		way = way->next;
	}
	ft_putchar('\n');
}

void	ft_doit(t_way *way, t_rm *rm, int ants)
{
	t_doit	*doit;
	char	**room;

	if (!(doit = (t_doit*)malloc(sizeof(doit))))
		return ;
	doit->ants = ants;
	doit->end = 0;
	room = ft_initroom(rm);
	//ft_display(way, room);
	while (doit->end != ants)
	{
		ft_moveants(way, room, doit, 0);
		ft_putchar('\n');
	}
	ft_free_room(room, rm);
}
