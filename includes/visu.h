/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:15:16 by mde-laga          #+#    #+#             */
/*   Updated: 2019/09/10 15:39:37 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include "../libft/includes/libft.h"
# include <SDL.h>

typedef struct	s_rd
{
	char		*data;
	struct s_rd	*next;
}				t_rd;

typedef struct		s_rm
{
	char			*name
	int				x;
	int				y;
	int				pos;
	struct s_rm		*next;
}					t_rm;

#endif
