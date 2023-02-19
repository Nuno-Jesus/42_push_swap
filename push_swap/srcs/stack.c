/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:46:23 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/15 15:06:44 by ncarvalh         ###   ########.fr       */
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

t_stack	*new_stack(int capacity)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->capacity = capacity;
	return (stack);
}

void	stack_push(t_stack *stack, t_node *node)
{
	if (!node)
		return ;
	if (!stack->head)
	{
		stack->head = node;
		stack->head->next = node;
		stack->head->prev = node;
		stack->size++;
		return ;
	}
	node->next = stack->head;
	stack->head->prev->next = node;
	node->prev = stack->head->prev;
	stack->head->prev = node;
	stack->head = node;
	stack->size++;
}

t_node	*stack_pop(t_stack *stack)
{
	t_node	*aux;

	if (!stack)
		return (NULL);
	else if (!stack->head)
		return (NULL);
	aux = stack->head;
	if (stack->size == 1)
		stack->head = NULL;
	else
	{
		stack->head->prev->next = stack->head->next;
		stack->head->next->prev = stack->head->prev;
		stack->head = stack->head->next;
	}
	stack->size--;
	return (aux);
}
