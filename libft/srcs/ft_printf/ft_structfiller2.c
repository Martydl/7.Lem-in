/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structfiller2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:25:08 by mde-laga          #+#    #+#             */
/*   Updated: 2019/06/03 13:25:08 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_zero(t_prin *prin)
{
	int i;
	int	last;

	i = prin->z;
	last = prin->length + i;
	while (i <= last && !(prin->form[i] >= '1' && prin->form[i] <= '9'))
	{
		if (prin->form[i] == '0')
		{
			prin->zero = 1;
			break ;
		}
		i++;
	}
	return (1);
}

int		ft_minus(t_prin *prin)
{
	int i;
	int	last;

	i = prin->z;
	last = prin->length + i;
	while (i < (last))
	{
		if (prin->form[i] == '-')
		{
			prin->min = 1;
			break ;
		}
		i++;
	}
	return (1);
}

int		ft_plus(t_prin *prin)
{
	int i;
	int	last;

	i = prin->z;
	last = prin->length + i;
	while (i < last)
	{
		if (prin->form[i] == '+')
		{
			prin->plus = 1;
			break ;
		}
		i++;
	}
	return (1);
}

int		ft_hash(t_prin *prin)
{
	int i;
	int	last;

	i = prin->z;
	last = prin->length + i;
	while (i < last)
	{
		if (prin->form[i] == '#')
		{
			prin->hash = 1;
			break ;
		}
		i++;
	}
	return (1);
}
