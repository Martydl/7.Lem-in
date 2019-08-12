/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:31:23 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/12 14:31:24 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_free_prin(t_prin *prin)
{
	free(prin->output);
	free(prin->form);
	free(prin);
}

void	ft_printf_error(t_prin *prin)
{
	va_end(prin->ap);
	ft_free_prin(prin);
	ft_putstr("error\n");
	exit(0);
}
