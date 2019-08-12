/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convmx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:23:59 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/10 12:17:27 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uint64_t	ft_getnb(t_prin *prin)
{
	uint64_t ret;

	ret = 0;
	if (prin->flags == 0)
		ret = va_arg(prin->ap, uint32_t);
	else if (prin->flags == 1)
		ret = (unsigned short)va_arg(prin->ap, uint32_t);
	else if (prin->flags == 2)
		ret = (unsigned char)va_arg(prin->ap, uint32_t);
	else if (prin->flags == 3)
		ret = va_arg(prin->ap, uint64_t);
	else if (prin->flags == 4)
		ret = va_arg(prin->ap, uint64_t);
	return (ret);
}

static int		ft_size(t_prin *prin, int nlen, uint64_t nb)
{
	int size;

	size = 0;
	if (prin->hash == 1 && nb != 0)
		size += 2;
	if (prin->preci > nlen)
		size += prin->preci - nlen;
	return (size);
}

static char		*ft_prefix(t_prin *prin, char *str, uint64_t nb)
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
		ft_printf_error(prin);
	i = 0;
	if (!prin->min && !prin->zero)
		while (--prin->field >= 0)
			pre[i++] = ' ';
	if (prin->hash && nb != 0 && (i += 2))
		ft_strcpy(pre + i - 2, "0X");
	if ((!prin->min && prin->zero) || prin->preci)
		while ((!prin->min && --prin->field >= 0) || --prin->preci - nlen >= 0)
			pre[i++] = '0';
	return (pre);
}

static char		*ft_suffix(t_prin *prin, char *ret)
{
	char	*suf;
	int		i;
	int		len;

	i = 0;
	len = prin->field - ft_strlen(ret);
	if (!(suf = ft_strnew(len)))
		ft_printf_error(prin);
	while (i < len)
		suf[i++] = ' ';
	if (!(ret = ft_strjfree(ret, suf)))
		ft_printf_error(prin);
	return (ret);
}

void			ft_convmx(t_prin *prin)
{
	char		*ret;
	uint64_t	nb;

	nb = ft_getnb(prin);
	if (!(nb == 0 && prin->preci == 0))
		ret = ft_lutoa_base(nb, 16, 'A');
	else if (!(ret = ft_strnew(0)))
		ft_printf_error(prin);
	if (!(ret = ft_strjfree(ft_prefix(prin, ret, nb), ret)))
		ft_printf_error(prin);
	if (prin->min && prin->field > (int)ft_strlen(ret))
		ret = ft_suffix(prin, ret);
	if (!(prin->output = ft_strjfree(prin->output, ret)))
		ft_printf_error(prin);
}
