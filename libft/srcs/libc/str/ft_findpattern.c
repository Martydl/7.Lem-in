/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findpattern.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 11:15:09 by mde-laga          #+#    #+#             */
/*   Updated: 2019/07/08 14:48:58 by mde-laga         ###   ########.fr       */
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
	while (**str == sep)
		*str += 1;
	ft_putchar(*str[1]);
	ft_putendl(*str);
	while (*str[i] /*&& *str[i] != sep*/)
		i++;
	dprintf(1, "a");
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
		if (pattern[i] == '%')
		{
			i++;
			if (pattern[i] == 's' && i++)
			{
				if (!string(&str, sep))
				{
					ft_putendl("1");
					return (0);
				}
			}
			else if (pattern[i] == 'd' && i++)
			{
				ft_putchar('x');
				if (!number(&str, sep))
				{
					ft_putendl("2");
					return (0);
				}
			}
			else
			{
				ft_putendl("3");
				return (0);
			}
		}
		else
		{
			ft_putendl("4");
			return (0);
		}
	}
	return (1);
}
