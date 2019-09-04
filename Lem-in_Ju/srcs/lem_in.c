/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:41:24 by judumay           #+#    #+#             */
/*   Updated: 2019/05/24 15:54:48 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_usage(t_s *s)
{
	miniprintf("Usage : ./lem-in < fichier\n\nOptions :\n-c  : Active le ");
	miniprintf("mode Color.\n-m  : Affiche la matrice\n-n  : Retire l'aff");
	miniprintf("ichage de la map.\n-nn : Pour le debug, retire tous les ");
	miniprintf("displays.\n");
	ft_error(s, 1);
}

static int	ft_read_input(t_s *s)
{
	int	i;

	i = 0;
	while ((s->ret = get_next_line(0, &s->str)))
	{
		i = 1;
		if (s->ret < 0 || (s->nbantset == 0 && (!ft_is_comment(s)
						&& !ft_strisnum(s->str))))
			return (-2);
		else if (s->nbantset == 0 && ft_strisnum(s->str))
		{
			s->nbant = ft_atolli(s->str);
			if (s->nbant <= 0 || s->nbant > INT32_MAX)
				return (-2);
			s->nbantset = 1;
			ft_strdel(&s->str);
		}
		else if ((ft_detect_line_type(s)) < 1)
			return (-2);
		if (s->ret == 2)
			break ;
	}
	if (i == 0)
		return (-1);
	return (1);
}

static void	ft_main_algo_one(t_s *s)
{
	ft_set_paths_start(s);
	if (ft_list_size(s->finalways) > 0)
	{
		ft_apply_flag(s);
		if (s->flag_nn == 0)
		{
			ft_print_path(s);
			ft_inttabdel(&s->ants_in_way, s->maxway);
			ft_strtabdel(&s->color);
		}
	}
	else
		miniprintf("ERROR\n");
	ft_inttabdel(&s->matrice, s->ttroom);
	ft_inttabdel(&s->weight, s->ttroom);
	ft_strtabdel(&s->namematrice);
	get_next_line(0, NULL);
	ft_list_clear_tab(&s->ways);
	ft_list_clear_tab(&s->finalways);
	ft_clear_struct(s);
}

int			main(int ac, char **av)
{
	t_s	*s;
	int	ret;

	if (!(s = (t_s *)malloc(sizeof(t_s))))
		ft_error(s, 0);
	s->av = av;
	s->ac = ac;
	s->flag_nn = 0;
	s->flag_h = 0;
	s->stset = 0;
	s->eset = 0;
	ft_set_struct(s);
	ft_set_flags(s);
	s->flag_h == 1 ? ft_usage(s) : 0;
	if ((ret = ft_read_input(s)) < 1 || !s->onepipeisset || !s->oneroomisset)
	{
		ret = ret != -2 && (!s->onepipeisset || !s->oneroomisset) ? -3 : ret;
		ft_error(s, ret);
	}
	if ((ret = ft_set_matrice_laplacienne(s)) < 1)
		ft_error(s, ret);
	ft_calcul_nb_pipes(s);
	ft_main_algo_one(s);
	return (0);
}
