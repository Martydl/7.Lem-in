/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:02:25 by mde-laga          #+#    #+#             */
/*   Updated: 2019/02/28 15:28:12 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int		size;

	size = 0;
	(n < 0) ? size++ : size;
	while (n /= 10)
		size++;
	return (size);
}

static char	*ft_recur(char *s, long n, int i)
{
	if (n < 0 && (n = -n))
		s[0] = '-';
	(n >= 10) ? ft_recur(s, n / 10, i - 1) : 0;
	s[i] = (n % 10 + '0');
	return (s);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		size;
	long	nb;

	nb = n;
	size = ft_len(n);
	if (!(s = (char*)malloc(sizeof(char) * (size + 2))))
		return (NULL);
	ft_recur(s, nb, size);
	s[size + 1] = '\0';
	return (s);
}
