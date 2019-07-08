/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 13:07:49 by mde-laga          #+#    #+#             */
/*   Updated: 2019/07/08 13:47:52 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem-in.h"

/*void	ft_test(char **str)
{
	*str += 1;
}*/

int		main(int ac, char **av)
{
	//char *str;

	ft_printf("%s\n%s\n%c/\n\n", av[1],av[2], av[3][0]);
	ft_putnbr(ft_findpattern(av[1], av[2], av[3][0]));
	//str = ft_strdup("abcdef");
	//ft_putendl(str);
	//ft_test(&str);
	//ft_putendl(str);
	(void)ac;
	(void)av;
	return (0);
}
