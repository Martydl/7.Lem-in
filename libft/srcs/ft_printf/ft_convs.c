/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:16:44 by mde-laga          #+#    #+#             */
/*   Updated: 2019/02/12 19:14:07 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_getstring(t_prin *prin)
{
	char	*str;
	char	*tmp;

	if (!(tmp = va_arg(prin->ap, char*)))
	{
		if (!(str = ft_strdup("(null)")))
			ft_error(prin);
		return (str);
	}
	if (prin->preci >= 0)
		str = ft_strndup(tmp, prin->preci);
	else if (!(str = ft_strdup(tmp)))
		ft_error(prin);
	return (str);
}

static char	*ft_add(t_prin *prin, char *ret)
{
	char	*add;

	prin->field -= ft_strlen(ret);
	if (!(add = ft_strnew(prin->field)))
		ft_error(prin);
	while (--prin->field >= 0)
		add[prin->field] = ' ';
	if (!prin->min)
		ret = ft_strjfree(add, ret);
	else
		ret = ft_strjfree(ret, add);
	return (ret);
}

void		ft_convs(t_prin *prin)
{
	char	*ret;

	ret = ft_getstring(prin);
	if (prin->field > (int)ft_strlen(ret))
		ret = ft_add(prin, ret);
	if (!(prin->output = ft_strjfree(prin->output, ret)))
		ft_error(prin);
}
