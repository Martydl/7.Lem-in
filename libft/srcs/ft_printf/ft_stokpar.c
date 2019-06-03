/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stokpar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:24:47 by mde-laga          #+#    #+#             */
/*   Updated: 2019/06/03 13:24:48 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conflit(t_prin *prin)
{
	if (prin->min == 1 && prin->zero == 1)
		prin->zero = 0;
	else if (prin->zero == 1 && prin->preci != -1 && (prin->conv == 'd' ||
				prin->conv == 'i' || prin->conv == 'o' || prin->conv == 'u' ||
					prin->conv == 'x' || prin->conv == 'X' ||
						prin->conv == 'b'))
		prin->zero = 0;
	else if (prin->plus == 1 && prin->spac == 1)
		prin->spac = 0;
	return (1);
}

int			ft_stopar(t_prin *prin)
{
	if (!ft_flags(prin))
		ft_error(prin);
	if (!ft_preci(prin))
		ft_error(prin);
	if (!ft_field(prin))
		ft_error(prin);
	if (!ft_spac(prin))
		ft_error(prin);
	if (!ft_hash(prin))
		ft_error(prin);
	if (!ft_zero(prin))
		ft_error(prin);
	if (!ft_minus(prin))
		ft_error(prin);
	if (!ft_plus(prin))
		ft_error(prin);
	if (!ft_conflit(prin))
		ft_error(prin);
	return (1);
}
