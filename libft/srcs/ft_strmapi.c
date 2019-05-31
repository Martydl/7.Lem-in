/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:13:48 by mde-laga          #+#    #+#             */
/*   Updated: 2019/02/28 15:28:12 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s2;
	int		i;

	if (!s)
		return (NULL);
	if (!(s2 = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	i = -1;
	while (s[++i])
		s2[i] = f(i, (char)s[i]);
	s2[i] = '\0';
	return (s2);
}
