/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findpattern.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 11:15:09 by mde-laga          #+#    #+#             */
/*   Updated: 2019/07/08 17:44:29 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static int	string(char **str, char sep)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = -1;
	while (**str == sep)
		*str += 1;
	while (**str != sep)
		i++;
	tmp = ft_strsub(*str, 0, i);
	*str +=i;
	while (tmp[++j])
		if (!ft_isprint(tmp[j]))
			{
				i = -1;
				break;
			}
	free(tmp);
	return (i < 0 ? 0 : 1);
}

static int	number(char **str, char sep)
{
	int		i;
	char	*tmp;

	i = 0;
	while (*str[0] == sep)
		str[0] += 1;

	ft_putendl(str[0]);

	while (str[0][i] && str[0][i] != sep)
		i++;
	tmp = ft_strsub(*str, 0, i);
	*str += i;
	if (!ft_isint(tmp))
		i = -1;
	free(tmp);
	return (i < 0 ? 0 : 1);
}

int			ft_findpattern(char *pattern, char *str, char sep)
{
	int		i;

	i = -1;
	while (pattern[++i])
	{
		ft_printf("i = %d\nchar :%c\n", i, pattern[i]);
		if (pattern[i] == '%')
		{
			if (pattern[++i] == 's')
			{
				if (!string(&str, sep))
					return (0);
			}
			else if (pattern[i] == 'd')
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
