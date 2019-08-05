/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:08:44 by mde-laga          #+#    #+#             */
/*   Updated: 2019/08/05 16:51:24 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include <stdlib.h>

typedef struct	s_rd
{
	char		*line;
	struct s_rd	*next;

}				t_rd;

typedef struct s_rm
{
	char		**data;
	struct s_rm	*next;
}				t_rm;


t_rd	*ft_read(void);
t_rm	*ft_getroom(t_rd **rd);
int		**ft_pipe(t_rd **rd, t_rm *room);
void	ft_displaymatrix(int **matrix, t_rm *room);
int		rd_isstart(char *str);
int		rd_isend(char *str);
int		rd_iscom(char *str);
int		rd_isroom(char *str);
int		rd_ispipe(char *str);

#endif
