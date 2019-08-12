/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:39:20 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/10 13:33:07 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

void	ft_conve(t_prin *prin)
{
	dprintf(1, "test");
	(void)prin;
	//prin->output = ft_strjfree(prin->output, ret);
	/*if (prin->field == 0)
		prin->output = ft_strjfree(prin->output, RESET);
	else if (prin->field == 1)
		prin->output = ft_strjfree(prin->output, RED);
	else if (prin->field == 2)
		prin->output = ft_strjfree(prin->output, GREEN);
	else if (prin->field == 3)
		prin->output = ft_strjfree(prin->output, BLUE);
	else if (prin->field == 4)
		prin->output = ft_strjfree(prin->output, YELLOW);
	else if (prin->field == 5)
		prin->output = ft_strjfree(prin->output, MAGENTA);
	else if (prin->field == 6)
		prin->output = ft_strjfree(prin->output, CYAN);*/
}
