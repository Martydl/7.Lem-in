/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:32:50 by mde-laga          #+#    #+#             */
/*   Updated: 2019/07/08 17:20:05 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	if (!s || !len)
		return (NULL);
	if (!(s2 = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = -1;
	while (++i < len)
		s2[i] = s[start + i];
	s2[i] = '\0';
	return (s2);
}
