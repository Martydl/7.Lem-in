/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:39:20 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/12 14:23:14 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convk(t_prin *prin)
{
	if (prin->field == 0)
		prin->output = ft_strjfree(prin->output, ft_strdup(RESET));
	else if (prin->field == 1)
		prin->output = ft_strjfree(prin->output, ft_strdup(RED));
	else if (prin->field == 2)
		prin->output = ft_strjfree(prin->output, ft_strdup(GREEN));
	else if (prin->field == 3)
		prin->output = ft_strjfree(prin->output, ft_strdup(BLUE));
	else if (prin->field == 4)
		prin->output = ft_strjfree(prin->output, ft_strdup(YELLOW));
	else if (prin->field == 5)
		prin->output = ft_strjfree(prin->output, ft_strdup(MAGENTA));
	else if (prin->field == 6)
		prin->output = ft_strjfree(prin->output, ft_strdup(CYAN));
}
