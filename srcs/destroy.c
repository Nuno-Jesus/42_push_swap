/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:30:17 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/15 15:03:53 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	destroy_state(t_state *state)
{
	if (state->a)
		destroy_stack(&state->a);
	if (state->b)
		destroy_stack(&state->b);
	return ;
}

void	destroy_stack(t_stack **stack)
{
	t_node	*aux;

	aux = (*stack)->head;
	if (!(*stack))
		return ;
	if ((*stack)->head)
	{
		(*stack)->head->prev->next = NULL;
		while (aux)
		{
			(*stack)->head = (*stack)->head->next;
			destroy_node(&aux);
			aux = (*stack)->head;
		}
	}
	free(*stack);
	*stack = NULL;
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
