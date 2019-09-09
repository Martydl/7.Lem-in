/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 14:03:15 by mde-laga          #+#    #+#             */
/*   Updated: 2019/09/09 13:38:51 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_next(t_rd **rd)
{
	t_rd	*tmp;

	tmp = (*rd);
	(*rd) = ((*rd)->next);
	free(tmp->data);
	free(tmp);
}

int		ft_nbroom(t_rm *rm)
{
	int	i;

	i = 0;
	while (rm)
	{
		rm = rm->next;
		i++;
	}
	return (i);
}

int		ft_getpos(t_rm *rm, char *name)
{
	int		i;

	i = 0;
	while (rm && ft_strcmp(rm->data[0], name))
	{
		rm = rm->next;
		i++;
	}
	return (i);
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
