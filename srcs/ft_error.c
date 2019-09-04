/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:58:53 by mde-laga          #+#    #+#             */
/*   Updated: 2019/09/04 15:17:16 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	ft_error(t_rd *rd, t_rm *rm, int **matrix)
{
	ft_free_lemin(rd, rm, matrix, NULL);
	ft_printf("%1kERROR%0k\n");
	exit(-1);
}
