/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 08:53:39 by judumay           #+#    #+#             */
/*   Updated: 2019/05/24 14:35:04 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_insert_data(t_btree **root, void *content
		, int (*cmpf)(void *, void *))
{
	t_btree	*new;

	if (*root && root)
	{
		new = *root;
		if (cmpf(content, new->content) < 0)
		{
			if (new->left)
				btree_insert_data(&(new->left), content, cmpf);
			else
				new->left = btree_create_node(content);
		}
		else
		{
			if (new->right)
				btree_insert_data(&(new->right), content, cmpf);
			else
				new->right = btree_create_node(content);
		}
	}
	else
		*root = btree_create_node(content);
}
