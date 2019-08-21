/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:08:44 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/21 14:10:43 by mde-laga         ###   ########.fr       */
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
}				t_rm;

typedef struct s_q
{
	int			room;
	struct s_q	*next;
}				t_q;


typedef struct s_bfs
{
	int			room;
	int			nbroom;
	int			*prev;
	struct s_q	*q;
}				t_bfs;


t_rd			*ft_read(void);
t_rm			*ft_getroom(t_rd **rd);
int				ft_getants(t_rd **rd);
int				**ft_matrix(t_rd **rd, t_rm *room);
int				ft_nbroom(t_rm *room);
int				ft_getpos(t_rm * room, char *name);
void			ft_next(t_rd **rd);
void			ft_display_matrix(int **matrix, t_rm *room);
int				rd_isstart(char *str);
int				rd_isend(char *str);
int				rd_iscom(char *str);
int				rd_isroom(char *str);
int				rd_ispipe(char *str);
int				rm_check(t_rm *room, t_rd *rd);
void			ft_free_lemin(t_rd *rd, t_rm *rm, int **matrix);
t_rm			*ft_push_front(t_rm *rm, int pos);
void			ft_deloneq(t_bfs *bfs);

void			ft_display_rd(t_rd *rd);
void			ft_display_rm(t_rm *rm);
void			ft_error_lemin();

#endif
