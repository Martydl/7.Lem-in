/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:08:04 by mde-laga          #+#    #+#             */
/*   Updated: 2019/06/11 11:46:51 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	ft_free_list(t_rd *beg)
{
	if (beg)
	{
		if (beg->next)
			ft_free_list(beg->next);
		free(beg->line);
		free(beg);
	}
}

void	ft_display_list(t_rd *rd)
{
	while (rd)
	{
		ft_putendl(rd->line);
		rd = rd->next;
	}
}

int		main(int ac, char **av)
{
	t_rd	*rd;

	(void)ac;
	(void)av;
	rd = ft_read();
	ft_display_list(rd);
	ft_free_list(rd);
	//ft_putendl(ft_isint(av[1]) ? "OK" : "KO");
}
