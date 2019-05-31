/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:38:28 by mde-laga          #+#    #+#             */
/*   Updated: 2019/02/28 15:28:12 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_printable(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (ft_isprint(str[i]) == 0)
			return (0);
	return (1);
}
