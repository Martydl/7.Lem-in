/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:21:35 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/10 13:24:53 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_converter(t_prin *prin)
{
	if (prin->conv == 'F')
		ft_convmf(prin);
	if (prin->conv == 'g')
		ft_convg(prin);
	else if (prin->conv == 'G')
		ft_convmg(prin);
	else if (prin->conv == 'B')
		ft_convmb(prin);
	else if (prin->conv == 'b')
		ft_convb(prin);
	else if (prin->conv == 'e')
		ft_convb(prin);
}

int			ft_convert(t_prin *prin)
{
	if (prin->conv == '%')
		ft_convperct(prin);
	else if (prin->conv == 'd')
		ft_convd(prin);
	else if (prin->conv == 'i')
		ft_convi(prin);
	else if (prin->conv == 'o')
		ft_convo(prin);
	else if (prin->conv == 'u')
		ft_convu(prin);
	else if (prin->conv == 'x')
		ft_convx(prin);
	else if (prin->conv == 'X')
		ft_convmx(prin);
	else if (prin->conv == 'f')
		ft_convf(prin);
	else if (prin->conv == 'c')
		ft_convc(prin);
	else if (prin->conv == 's')
		ft_convs(prin);
	else if (prin->conv == 'p')
		ft_convp(prin);
	else
		ft_converter(prin);
	return (1);
}
