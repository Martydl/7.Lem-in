/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:08:44 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/12 16:20:51 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include <stdlib.h>

# include "stdio.h"

typedef struct	s_rd
{
	char		*data;
	struct s_rd	*next;

}				t_rd;

typedef struct	s_rm
{
	char		**data;
	int			pos;
	struct s_rm	*next;
	struct s_rm	*prev;
}				t_rm;

typedef struct	s_room
{
	t_rm		*room;
}				t_room;

t_rd			*ft_read(void);
t_rm			*ft_getroom(t_rd **rdm, int pos);
int				**ft_pipe(t_rd **rd, t_rm *room);
int				ft_nbroom(t_rm *room);
void			ft_display_matrix(int **matrix, t_rm *room);
int				rd_isstart(char *str);
int				rd_isend(char *str);
int				rd_iscom(char *str);
int				rd_isroom(char *str);
int				rd_ispipe(char *str);
int				rm_check(t_rm *room, t_rd *rd);
void			ft_free_lemin(t_rd *rd, t_rm *rm, int **matrix);

void			ft_display_rd(t_rd *rd);
void			ft_display_rm(t_rm *rm);
void			ft_error_lemin();

#endif
