/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convmf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:22:25 by mde-laga          #+#    #+#             */
/*   Updated: 2019/06/03 13:23:06 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double	ft_getnb(t_prin *prin)
{
	long double ret;

	ret = 0;
	if (prin->flags == 0)
		ret = va_arg(prin->ap, double);
	if (prin->flags == 5)
		ret = va_arg(prin->ap, long double);
	return (ret);
}

static char			*ft_prefix(t_prin *prin, char *str, int mant)
{
	char	*pre;
	int		size;
	int		len;
	int		i;

	len = ft_strlen(str);
	size = (mant == 1 && (prin->plus || prin->spac) ? 1 : 0);
	if (!prin->min && prin->field > size + len && (prin->field -= size + len))
		size += prin->field;
	else if (!prin->min)
		prin->field = 0;
	if (!(pre = ft_strnew(size)))
		ft_error(prin);
	i = 0;
	if (!prin->min)
		while (--prin->field >= 0)
			pre[i++] = ' ';
	mant == 1 && prin->spac ? pre[i++] = ' ' : 0;
	mant == 1 && prin->plus ? pre[i++] = '+' : 0;
	return (pre);
}

static char			*ft_suffix(t_prin *prin, char *ret)
{
	char	*suf;
	int		i;
	int		len;

	i = 0;
	len = prin->field - ft_strlen(ret);
	if (!(suf = ft_strnew(len)))
		ft_error(prin);
	while (i < len)
		suf[i++] = ' ';
	ret = ft_strjfree(ret, suf);
	return (ret);
}

static void			ft_inf_nan(t_prin *prin, int mant)
{
	char *ret;

	if (!(ret = ft_strnew(0)))
		ft_error(prin);
	ret = ft_strjfree(ret, ft_strdup(mant == 1 ? "INF" : "NAN"));
	ret = ft_strjfree(ft_prefix(prin, ret, mant), ret);
	if (prin->min && prin->field > (int)ft_strlen(ret))
		ret = ft_suffix(prin, ret);
	prin->output = ft_strjfree(prin->output, ret);
}

void				ft_convmf(t_prin *prin)
{
	t_fl		*fl;
	long double	value;
	int			mant;
	int			neg;

	prin->preci == -1 ? prin->preci = 6 : 0;
	if (!(fl = (t_fl *)malloc(sizeof(t_fl))))
		ft_error(prin);
	value = ft_getnb(prin);
	neg = (value < 0 && (value *= -1) ? 1 : 0);
	ft_separator(fl, value);
	ft_normiser(fl, value);
	mant = ft_mantiser(fl);
	if ((mant == 1 || mant == 2) && value != 1)
		ft_inf_nan(prin, mant);
	else
	{
		ft_rounder(fl, prin->preci);
		ft_convf2(prin, fl, neg);
	}
	free(fl->sig);
	free(fl->mant);
	free(fl->expo);
	free(fl);
}
