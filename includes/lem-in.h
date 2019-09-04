/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:08:44 by mde-laga          #+#    #+#             */
/*   Updated: 2019/09/04 15:22:26 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include "lem-struct.h"
# include <stdlib.h>

# include <stdio.h>

t_rd			*ft_read(void);
t_rm			*ft_getroom(t_rd **rd, int start, int end);
int				ft_getants(t_rd **rd);
int				**ft_matrix(t_rd **rd, t_rm *room);
int				ft_nbroom(t_rm *room);
int				ft_getpos(t_rm * room, char *name);
void			ft_next(t_rd **rd);
void			ft_display_matrix(int **matrix, t_rm *room);
int				rd_isstart(char *str);
int				rd_isend(char *str);
int				rd_iscom(char *str);
t_path			*ft_getpaths(t_rm *rm, int **matrix);
int				rd_isroom(char *str);
int				rd_ispipe(char *str);
int				rm_check(t_rm *room, t_rd *rd);
void			ft_free_lemin(t_rd *rd, t_rm *rm, int **matrix, t_path *paths);
t_rm			*ft_push_front(t_rm *rm, int pos, t_rd *rd);
void			ft_deloneq(t_bfs *bfs);
int				**ft_bfs(int qone, int **matrix, int *cflct, t_rm *rm);
t_bfs			*ft_setbfs(t_rm *rm, int start);
void			*ft_freebfs(t_bfs *bfs);
t_path			*ft_bestpath(t_path *paths, int ants);
void			ft_error(t_rd *rd, t_rm *rm, int **matrix);
t_algo			*ft_initalgo(int **matrix, t_rm *rm);
int				*ft_initcflct(t_rm *rm, int **matrix);
int				*ft_getstart(int **matrix, t_rm *rm);
void			ft_delway(t_path *path);
int				ft_lanelen(int *lane);
void			ft_doit(t_way *way, t_rm *rm, int ants);;


void	ft_display_path(t_path *path);

#endif
