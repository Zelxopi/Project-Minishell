/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:24:43 by mtrembla          #+#    #+#             */
/*   Updated: 2023/02/13 13:52:30 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	dlist_remove_node(t_dlist *l, t_node *node)
{
	t_node	*temp;

	temp = node;
	if (!node->prev && !node->next)
		return ;
	else if (!node->prev)
	{
		node->next->prev = NULL;
		l->first = node->next;
	}
	else if (!node->next)
	{
		node->prev->next = NULL;
		l->last = node->prev;
	}
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	free(node->content);
	free(temp);
}
