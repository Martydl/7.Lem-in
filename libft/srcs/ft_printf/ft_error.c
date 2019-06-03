/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:23:32 by mde-laga          #+#    #+#             */
/*   Updated: 2019/06/03 13:23:33 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_free_prin(t_prin *prin)
{
	free(prin->output);
	free(prin->form);
	free(prin);
}

void	ft_error(t_prin *prin)
{
	va_end(prin->ap);
	ft_free_prin(prin);
	ft_putstr("error\n");
	exit(0);
}
