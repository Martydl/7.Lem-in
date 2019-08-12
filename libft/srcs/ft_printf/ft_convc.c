/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:22:21 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/10 12:17:27 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convc(t_prin *prin)
{
	char	*ret;
	char	c;
	int		size;
	int		i;

	c = va_arg(prin->ap, int);
	size = 1;
	if (prin->field)
		size += prin->field--;
	if (!(ret = ft_strnew(size)))
		ft_printf_error(prin);
	i = 0;
	if (!prin->min)
		while (--prin->field >= 0)
			ret[i++] = ' ';
	ret[i++] = c;
	if (prin->min)
		while (--prin->field >= 0)
			ret[i++] = ' ';
	prin->output = ft_strjfree(prin->output, ret);
}
