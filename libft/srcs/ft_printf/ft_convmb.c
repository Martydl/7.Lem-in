/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convmb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 09:17:41 by mde-laga          #+#    #+#             */
/*   Updated: 2019/06/03 13:22:15 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	uint64_t	ft_getnb(t_prin *prin)
{
	uint64_t ret;

	ret = 0;
	if (prin->flags == 0)
		ret = va_arg(prin->ap, uint32_t);
	else if (prin->flags == 1)
		ret = (short)va_arg(prin->ap, uint32_t);
	else if (prin->flags == 2)
		ret = (char)va_arg(prin->ap, uint32_t);
	else if (prin->flags == 3)
		ret = va_arg(prin->ap, uint64_t);
	else if (prin->flags == 4)
		ret = va_arg(prin->ap, uint64_t);
	return (ret);
}

static int			ft_size(t_prin *prin, int nlen, uint64_t nb)
{
	int size;

	size = 0;
	if (prin->hash == 1 && nb != 0)
		size += 2;
	if (prin->preci > nlen)
		size += prin->preci - nlen;
	return (size);
}

static char			*ft_prefix(t_prin *prin, char *str, uint64_t nb)
{
	char	*pre;
	int		size;
	int		nlen;
	int		i;

	nlen = ft_strlen(str);
	size = ft_size(prin, nlen, nb);
	if (!prin->min && prin->field > size + nlen && (prin->field -= size + nlen))
		size += prin->field;
	else if (!prin->min)
		prin->field = 0;
	if (!(pre = ft_strnew(size)))
		ft_error(prin);
	i = 0;
	if (!prin->min && !prin->zero)
		while (--prin->field >= 0)
			pre[i++] = ' ';
	if (prin->hash && nb != 0 && (i += 2))
		ft_strcpy(pre + i - 2, "0B");
	if ((!prin->min && prin->zero) || prin->preci)
		while ((!prin->min && --prin->field >= 0) || --prin->preci - nlen >= 0)
			pre[i++] = '0';
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
	if (!(ret = ft_strjfree(ret, suf)))
		ft_error(prin);
	return (ret);
}

void				ft_convmb(t_prin *prin)
{
	char		*ret;
	uint64_t	nb;

	nb = ft_getnb(prin);
	if (prin->preci == -1)
		prin->preci = 1;
	if (!(nb == 0 && prin->preci == 0))
		ret = ft_lutoa_base(nb, 2, 0);
	else if (!(ret = ft_strnew(0)))
		ft_error(prin);
	if (!(ret = ft_strjfree(ft_prefix(prin, ret, nb), ret)))
		ft_error(prin);
	if (prin->min && prin->field > (int)ft_strlen(ret))
		ret = ft_suffix(prin, ret);
	if (!(prin->output = ft_strjfree(prin->output, ret)))
		ft_error(prin);
}
