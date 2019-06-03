/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:42:48 by mde-laga          #+#    #+#             */
/*   Updated: 2019/04/30 18:18:45 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strings(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		(s[i] && s[i] != c) ? count++ : count;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	ft_slen(char const *s, int beg, char c)
{
	int		n;

	n = 0;
	while (s[n + beg] && s[n + beg] != c)
		n++;
	return (n);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;
	int		len;

	if (!s || !c)
		return (NULL);
	if (!(split = (char**)malloc(sizeof(char*) * (ft_strings(s, c) + 1))))
		return (NULL);
	i = 0;
	j = -1;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j++;
		if (!s[i])
			break ;
		len = ft_slen(s, i, c);
		split[j] = ft_strsub(s, i, len);
		i = i + len;
	}
	s[i - 1] != c ? j++ : j;
	split[j] = 0;
	return (split);
}
