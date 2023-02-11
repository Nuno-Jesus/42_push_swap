/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:59:09 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/11 20:42:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int val)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	if (!node)
		return (node);
	node->val = val;
	node->rank = -1;
	return (node);
}

void	destroy_node(t_node **node)
{
	if (!node)
		return ;
	(*node)->next = NULL;
	(*node)->prev = NULL;
	free(*node);
	*node = NULL;
}
