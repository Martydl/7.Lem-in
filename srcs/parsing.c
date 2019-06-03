/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:08:22 by mde-laga          #+#    #+#             */
/*   Updated: 2019/06/03 11:22:06 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_rd	*ft_read(void)
{
	char	str[1];
	int		ret;
	t_rd	*beg;
	t_rd	*rd;

	beg = NULL;
	rd = beg;
	while ((ret = read(0, str, 1)) > 0)
	{
		if (ret == -1)
			return (NULL);
		if (!rd && !(rd = (t_rd*)(malloc(sizeof(t_rd)))))
			return (NULL);
		else if (str[0] != '\n')
			rd->line = ft_strjfree(rd->line, str);
		else
		{
			if (ft_verif())
				break ;
			rd = rd->next;
		}
	}
}
