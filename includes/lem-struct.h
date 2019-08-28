/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:06:32 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/28 17:01:36 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_STRUCT_H
# define LEM_STRUCT_H

typedef struct		s_rd
{
	char			*data;
	struct s_rd		*next;

}					t_rd;

typedef struct		s_rm
{
	char			**data;
	int				pos;
	struct s_rm		*next;
}					t_rm;

typedef struct		s_queue
{
	int				room;
	struct s_queue		*next;
}					t_queue;


typedef struct		s_bfs
{
	int				room;
	int				nbroom;
	int				*prev;
	struct s_queue		*q;
}					t_bfs;

typedef struct		s_way
{
	int				*lane;
	int				ants;
	int				length;
	struct s_way	*next;
}					t_way;

typedef struct		s_paths
{
	struct s_way	*way;
	struct s_paths	*next;
}					t_paths;

typedef struct		s_algo
{
	struct s_way	*way;
	int				*lane;
	int				*conflicts;
	int				*start;
}					t_algo;

#endif
