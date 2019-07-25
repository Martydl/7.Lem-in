/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 13:07:49 by mde-laga          #+#    #+#             */
/*   Updated: 2019/07/25 18:21:21 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem-in.h"

int		main(int ac, char **av)
{
	char	*pattern = ft_strdup(av[1]);
	char	*str = ft_strdup(av[2]);
	char	c = av[3][0];

	ft_printf("%s\n%s\n%c/\n\n", pattern, str, c);
	ft_putnbr(ft_findpattern(pattern, str, c));
	(void)ac;
	(void)av;
	free(pattern);
	free(str);
	return (0);
}
