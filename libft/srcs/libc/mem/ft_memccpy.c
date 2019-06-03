/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:12:03 by mde-laga          #+#    #+#             */
/*   Updated: 2019/02/28 15:28:12 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*dest;
	char	*sourc;

	i = 0;
	dest = dst;
	sourc = (char*)src;
	while (i < n && (i == 0 || (unsigned char)sourc[i - 1] != (unsigned char)c))
	{
		dest[i] = sourc[i];
		i++;
	}
	if (i > 0 && (unsigned char)sourc[i - 1] == (unsigned char)c)
		return (dest + i);
	return (NULL);
}
