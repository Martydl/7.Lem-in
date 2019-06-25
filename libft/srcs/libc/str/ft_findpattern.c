/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findpattern.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 11:15:09 by mde-laga          #+#    #+#             */
/*   Updated: 2019/06/25 18:32:38 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		string(char ***str, char sep)
{
	while (**str == sep)
		*str++;
	while (**str != sep)
		;
}

int		number(char ***str, char sep)
{
	int		i;
	char	*tmp;

	i = 0;
	while (**str == sep)
		*str++;
	while (**str != sep)
		i++;
	tmp = ft_strsub(*str, 0, i);
	*str += i;
	if (!ft_isint(tmp))
		i = -1;
	free(tmp);
	return (i < 0 ? 0 : 1);
}

int		ft_findpattern(char *pattern, char *str, char sep)
{
	int		i;

	i = -1;
	while (pattern[++i])
	{
		if (pattern[i] == '%')
		{
			if (pattern[i + 1] == 's' && i++)
			{
				if (!string(&str, sep))
					return (0);
			}
			else if (pattern[i + 1] == 'd' && i++)
			{
				if (!number(&str, sep))
					return (0);
			}
			else
				return (0);
		}
		else
			return (0);
	}
	return (1);
}
