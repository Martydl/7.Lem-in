/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convperct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:23:00 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/10 12:17:27 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convperct(t_prin *prin)
{
	char	*ret;
	int		size;
	int		i;

	size = 1;
	if (prin->field)
		size += prin->field--;
	if (!(ret = ft_strnew(size)))
		ft_printf_error(prin);
	i = 0;
	if (!prin->min)
		while (--prin->field >= 0)
			ret[i++] = (prin->zero ? '0' : ' ');
	ret[i++] = '%';
	if (prin->min)
		while (--prin->field >= 0)
			ret[i++] = ' ';
	if (!(prin->output = ft_strjfree(prin->output, ret)))
		ft_printf_error(prin);
}
