/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findpattern.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 11:15:09 by mde-laga          #+#    #+#             */
/*   Updated: 2019/06/25 13:51:10 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		string(char ***str)
{
	while (*str)
	{

	}
}

int		ft_findpattern(char *pattern, char *str)
{
	int		i;

	i = -1;
	while (pattern[++i])
	{
		if (pattern[i] == '%')
			if (pattern[i + 1] == 's' && i++)
				if (!string())
					return (0);
			else if (pattern[i+ 1] == 'd' && i++)
				if (!number())
					return (0);
			else
				return (0);
		else
			return (0);
	}
	return (1);
}

//%s, %d
