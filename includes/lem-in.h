/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:08:44 by mde-laga          #+#    #+#             */
/*   Updated: 2019/09/09 11:34:03 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include "lem-struct.h"
# include <stdlib.h>

# include <stdio.h>

t_rd			*ft_read(void);
void			ft_display_rd(t_rd *rd);
int				ft_getants(t_rd **rd);
t_rm			*ft_getroom(t_rd **rd, int start, int end);
t_rm			*rm_check(t_rm *room, t_rd *rd);
int				**ft_matrix(t_rd **rd, t_rm *room);
t_path			*ft_getpaths(t_rm *rm, int **matrix);
int				**ft_bfs(int qone, int **matrix, int *cflct, t_rm *rm);
t_path			*ft_bestpath(t_path *paths, int ants);
void			ft_free_lemin(t_rd *rd, t_rm *rm, int **matrix, t_path *paths);
void			ft_doit(t_way *way, t_rm *rm, int ants);
int				ft_getpos(t_rm * room, char *name);
int				ft_nbroom(t_rm *room);
void			ft_next(t_rd **rd);
int				rd_isstart(char *str);
int				rd_isend(char *str);
int				rd_iscom(char *str);
int				rd_isroom(char *str);
int				rd_ispipe(char *str);
t_bfs			*ft_setbfs(t_rm *rm, int start);
int				**ft_initlane(int i);
void			*ft_freebfs(t_bfs *bfs);
void			ft_deloneq(t_bfs *bfs);
int				ft_lanelen(int *lane);
int				*ft_getstart(int **matrix, t_rm *rm);
int				*ft_initcflct(t_rm *rm, int **matrix);
t_algo			*ft_initalgo(int **matrix, t_rm *rm);
void			ft_delway(t_path *path);
void			ft_free_rd(t_rd *beg);
void			ft_error(t_rd *rd, t_rm *rm, int **matrix);
void			ft_display_matrix(int **matrix, t_rm *room);
void			ft_display_path(t_path *path);

#endif
