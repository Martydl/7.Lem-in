/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 16:20:17 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/05 16:33:26 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		rd_isstart(char *str)
{
	return (ft_strcmp("##start", str) ? 0 : 1);
}

int		rd_isend(char *str)
{
	return (ft_strcmp("##end", str) ? 0 : 1);
}

int		rd_iscom(char *str)
{
	return (str[0] == '#' ? 1 : 0);
}

int		rd_isroom(char *str)
{
	return (ft_findpattern("%s%d%d", str, ' ') ? 1 : 0);
}

int		rd_ispipe(char *str)
{
	return (ft_findpattern("%d%d", str, '-') ? 1 : 0);
}
