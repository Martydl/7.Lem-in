#include "lem-in.h"

int		ft_getants(t_rd **rd)
{
	int		ants;
	t_rd	*tmp;

	while ((*rd))
	{
		if (rd_isstart() || rd_isend())
			ft_error();
		else if (rd_iscom() || rd_iscmd())
		{
			tmp = (*rd);
			(*rd) = (*rd)->next;
			free(tmp);
		}
		else if (ft_isint((*rd)->line))
		{
			ants = ft_atoi((*rd)->line);
			tmp = (*rd);
			(*rd) = (*rd)->next;
			free(tmp);
			return (ants);
		}
		else
			ft_error();
	}
	return (NULL);
}
