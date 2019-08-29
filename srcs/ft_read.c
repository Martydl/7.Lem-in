/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:08:22 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/29 15:48:45 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		ft_getants(t_rd **rd)
{
	int		ants;

	while ((*rd))
	{
		if (rd_isstart((*rd)->data) || rd_isend((*rd)->data))
			ft_error(*rd, NULL, NULL);
		else if (rd_iscom((*rd)->data))
			ft_next(rd);
		else if (ft_isint((*rd)->data))
		{
			ants = ft_atoi((*rd)->data);
			ft_next(rd);
			return (ants);
		}
		else
			ft_error(*rd, NULL, NULL);
	}
	return (0);
}

t_rd	*ft_read(void)
{
	char	*str;
	t_rd	*rd;

	rd = NULL;
	if (get_next_line(0, &str))
	{
		if (!(rd = (t_rd*)malloc(sizeof(t_rd))))
			return (NULL);
		rd->data = str;
		rd->next = ft_read();
	}
	else
		free(str);
	return (rd);
}
