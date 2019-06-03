/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:24:39 by mde-laga          #+#    #+#             */
/*   Updated: 2019/06/03 13:24:50 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_reset(t_prin *prin)
{
	prin->flags = 0;
	prin->preci = -1;
	prin->field = 0;
	prin->spac = 0;
	prin->hash = 0;
	prin->zero = 0;
	prin->min = 0;
	prin->plus = 0;
	prin->length = 0;
	return (1);
}
