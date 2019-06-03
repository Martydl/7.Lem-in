/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:08:22 by mde-laga          #+#    #+#             */
/*   Updated: 2019/06/03 16:25:42 by mde-laga         ###   ########.fr       */
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
