/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:08:12 by mde-laga          #+#    #+#             */
/*   Updated: 2019/02/28 15:28:12 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ln;
	void	*ln_cont;

	if (!(ln = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content != NULL)
	{
		ln_cont = ft_memalloc(content_size);
		ft_memcpy(ln_cont, content, content_size);
		ln->content = ln_cont;
		ln->content_size = content_size;
	}
	else
	{
		ln->content = NULL;
		ln->content_size = 0;
	}
	ln->next = NULL;
	return (ln);
}
