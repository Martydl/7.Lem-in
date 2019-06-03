/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structfiller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:24:57 by mde-laga          #+#    #+#             */
/*   Updated: 2019/06/03 13:25:11 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isflag(char c)
{
	return (c == 'h' || c == 'l' || c == 'L' ? 1 : 0);
}

int		ft_flags(t_prin *prin)
{
	int i;

	i = 0;
	while (i < prin->length && !ft_isflag(prin->form[prin->z + i]))
		i++;
	if (i < prin->length)
	{
		if (prin->form[prin->z + i] == 'h' &&
			prin->form[prin->z + i + 1] != 'h' && (i += 1))
			prin->flags = 1;
		if (prin->form[prin->z + i] == 'h' &&
			prin->form[prin->z + i + 1] == 'h' && (i += 2))
			prin->flags = 2;
		if (prin->form[prin->z + i] == 'l' &&
			prin->form[prin->z + i + 1] != 'l' && (i += 1))
			prin->flags = 3;
		if (prin->form[prin->z + i] == 'l' &&
			prin->form[prin->z + i + 1] == 'l' && (i += 2))
			prin->flags = 4;
		if (prin->form[prin->z + i] == 'L' && (i += 1))
			prin->flags = 5;
	}
	if (i != prin->length)
		return (0);
	return (1);
}

int		ft_preci(t_prin *prin)
{
	int		i;
	char	*str;

	i = 1;
	while (i < prin->length && prin->form[prin->z + i] != '.')
		i++;
	if (i < prin->length)
	{
		str = ft_strnew(0);
		i++;
		while (ft_isdigit(prin->form[prin->z + i]) == 1)
		{
			str = ft_strjfree(str, ft_strndup(prin->form + prin->z + i, 1));
			i++;
		}
		prin->preci = ft_atoi(str);
		free(str);
		if (prin->form[prin->z + i] != prin->conv &&
			!(ft_isflag(prin->form[prin->z + i])))
			return (0);
	}
	return (1);
}

int		ft_field(t_prin *prin)
{
	int		i;
	char	*str;

	i = 1;
	while (i < prin->length && (!ft_isdigit(prin->form[prin->z + i]) ||
		(prin->form[prin->z + i] == '0')) && prin->form[prin->z + i] != '.')
		i++;
	if (i < prin->length && prin->form[prin->z + i] != '.')
	{
		str = ft_strnew(0);
		while (ft_isdigit(prin->form[prin->z + i]) == 1)
		{
			str = ft_strjfree(str, ft_strndup(prin->form + prin->z + i, 1));
			i++;
		}
		prin->field = ft_atoi(str);
		free(str);
		if (prin->form[prin->z + i] != prin->conv && prin->form[prin->z + i] !=
			'.' && !(ft_isflag(prin->form[prin->z + i])))
			return (0);
	}
	return (1);
}

int		ft_spac(t_prin *prin)
{
	int i;
	int last;

	i = prin->z;
	last = prin->length + i;
	while (i < last)
	{
		if (prin->form[i] == ' ')
		{
			prin->spac = 1;
			break ;
		}
		i++;
	}
	return (1);
}
