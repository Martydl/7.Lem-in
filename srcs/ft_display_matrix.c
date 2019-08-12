/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:46:51 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/12 15:09:48 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	ft_display_name(t_rm **room, int format)
{
	if (format == 0)
	{
		if ((*room)->pos == 1)
			ft_printf("%2k%5s%0k", (*room)->data[0]);
		else if ((*room)->pos == -1)
			ft_printf("%1k%5s%0k", (*room)->data[0]);
		else
			ft_printf("%4k%5s%0k", (*room)->data[0]);
	}
	if (format == 1)
	{
		if ((*room)->pos == 1)
			ft_printf("\n\n%2k%5s%0k", (*room)->data[0]);
		else if ((*room)->pos == -1)
			ft_printf("\n\n%1k%5s%0k", (*room)->data[0]);
		else
			ft_printf("\n\n%4k%5s%0k", (*room)->data[0]);
	}
	(*room) = (*room)->next;
}

void		ft_display_matrix(int **matrix, t_rm *room)
{
	t_rm	*cp;
	int		i;
	int		j;
	int		nb;

	cp = room;
	nb = ft_nbroom(room);
	ft_printf("     ");
	while (room && room->data)
		ft_display_name(&room, 0);
	i = -1;
	while (++i < nb)
	{
		ft_display_name(&cp, 1);
		j = -1;
		while (++j < nb)
			if (!matrix[i][j])
				ft_printf("%5c", '.');
			else if (matrix[i][j] > 0)
				ft_printf("%6k%5d%0k", matrix[i][j]);
			else
				ft_printf("%5d", matrix[i][j]);
	}
	ft_putstr("\n\n");
}
