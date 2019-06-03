/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 22:28:39 by lramard           #+#    #+#             */
/*   Updated: 2019/02/10 14:47:10 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int			ft_is_in_base(char car, char *base)
{
	int i;

	i = 0;
	if (car == '+' || car == '-' || car == '\0')
		return (-2);
	while (base[i] != '\0')
	{
		if (base[i] == car)
			return (i);
		i++;
	}
	return (-1);
}

int			ft_atoi_base(char *str, char *base)
{
	int i;
	int tmp;
	int neg;

	i = 0;
	neg = 1;
	tmp = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (ft_is_in_base(str[i], base) >= 0)
	{
		tmp *= ft_strlen(base);
		tmp += (ft_is_in_base(str[i], base)) * neg;
		i++;
	}
	if (ft_is_in_base(str[i], base) == -1)
		return (0);
	return (tmp);
}

char		*ft_itoa_base(int nbr, char *base, char *str, int size)
{
	int i;
	int	div;

	i = 0;
	div = 1;
	size -= 1;
	if (nbr < 0)
	{
		nbr *= -1;
		str[i++] = '-';
	}
	while (size > 0)
	{
		div *= ft_strlen(base);
		size--;
	}
	while (div > 0)
	{
		str[i] = base[nbr / div];
		i++;
		nbr %= div;
		div /= ft_strlen(base);
	}
	str[i] = '\0';
	return (str);
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nbrt[2];
	char	*str;
	int		neg;
	int		i;

	neg = 0;
	i = 0;
	nbrt[0] = ft_atoi_base(nbr, base_from);
	nbrt[1] = nbrt[0];
	if (nbrt[0] < 0)
		neg = 1;
	if (nbrt[0] == 0)
	{
		str = (char *)malloc(sizeof(char) * (2));
		str[i] = base_to[0];
		return (str);
	}
	while (nbrt[1] != 0)
	{
		nbrt[1] /= ft_strlen(base_to);
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (i + 1 + neg))))
		return (NULL);
	return (ft_itoa_base(nbrt[0], base_to, str, i));
}
