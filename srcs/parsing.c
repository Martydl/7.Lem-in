/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:08:22 by mde-laga          #+#    #+#             */
/*   Updated: 2019/06/11 12:26:07 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		ft_check_line(char *str)
{
	if (ft_strlen(str) && ft_str_is_alpha(str))
		return (1);
	return (0);
}

t_rd	*ft_read(void)
{
	char	*str;
	t_rd	*rd;

	rd = NULL;
	if (get_next_line(0, &str))
	{
		if (ft_check_line(str))
		{
			if (!(rd = (t_rd*)malloc(sizeof(t_rd))))
				return (NULL);
			rd->line = str;
			rd->next = ft_read();
		}
		else
			free(str);
	}
	else
		free(str);
	return (rd);
}

int		ft_getants(t_rd **rd)
{
	int		ants;
	t_rd	*tmp;

	while ((*rd))
	{
		if (rd_isstart() || rd_isend())
			ft_error();
		else if (rd_iscom() || rd_iscmd())
		{
			tmp = (*rd);
			(*rd) = (*rd)->next;
			free(tmp);
		}
		else if (ft_isint((*rd)->line))
		{
			ants = ft_atoi((*rd)->line);
			tmp = (*rd);
			(*rd) = (*rd)->next;
			free(tmp);
			return (ants);
		}
		else
			ft_error();
	}
	return (NULL);
}

t_rm	*ft_getroom(t_rd **rd)
{
	t_rd	*tmp;

	while ((*rd))
	{
		if (rd_isstart() || rd_isend())
		{}
		else if (rd_iscom() || rd_iscmd())
		{
			tmp = rd;
			rd = rd->next;
			free(tmp);
		}
		else if (rd_isroom())
		{
			(*room)->data = ft_strsplit(rd->line, ' ');
			tmp = rd;
			rd = rd->next;
			free(tmp);
		}
		else
			ft_error();
	}
}
















/*void	ft_sep(t_rd **rd, int *ants, t_rm **room, matrix)
{
	t_rd	*tmp;

	while((*rd))
	{

	}
	ft_enough();
}

	while ((*rd) && (rd_iscom() || rd_iscmd()))
	{
		tmp = (*rd);
		(*rd) = (*rd)->next;
		free(tmp);
	}
	if (ft_isint((*rd)->line))
		*ants = ft_atoi((*rd)->line);
	while ((*rd))
	{
		if ()
			;
		else
			break ;
	}*/
