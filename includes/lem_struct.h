/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:06:32 by mde-laga          #+#    #+#             */
/*   Updated: 2019/09/09 15:35:45 by mde-laga         ###   ########.fr       */
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
	struct s_queue	*next;
}					t_queue;

typedef struct		s_bfs
{
	int				room;
	int				nbroom;
	int				*link;
	int				*dont;
	struct s_queue	*q;
}					t_bfs;

typedef struct		s_way
{
	int				ants;
	int				length;
	int				**lane;
	struct s_way	*next;
}					t_way;

typedef struct		s_path
{
	struct s_way	*way;
	struct s_path	*next;
}					t_path;

typedef struct		s_algo
{
	struct s_way	*way;
	int				**lane;
	int				*cflct;
	int				*start;
	int				i;
	int				j;
}					t_algo;

typedef struct		s_doit
{
	int				ants;
	int				end;
}					t_doit;

typedef struct		s_dsp
{
	int				ants;
	int				rd;
	int				move;
	int				matrix;
	int				way;
	int				space;
}					t_dsp;

#endif
