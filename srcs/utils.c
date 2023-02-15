/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:33:51 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/15 16:30:05 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_bits(int n)
{
	int	bits;

	bits = 0;
	while (n >> bits)
		bits++;
	return (bits);
}

void	stack_fill(t_stack *stack, char **argv, int argc)
{
	int	i;

	i = argc;
	while (--i >= 0)
		stack_push(stack, new_node(ft_atoi(argv[i])));
}

t_node	*find_next_unranked_min(t_stack *a)
{
	int		i;
	t_node	*ret;
	t_node	*aux;

	i = -1;
	aux = a->head;
	ret = NULL;
	while (++i < a->size)
	{
		if (aux->rank == -1 && (!ret || aux->val < ret->val))
			ret = aux;
		aux = aux->next;
	}
	return (ret);
}

int	find_stack_min(t_stack *stack)
{
	int		i;
	int		min;
	t_node	*node;

	i = -1;
	node = stack->head;
	min = stack->head->rank;
	while (++i < stack->size)
	{
		if (node->rank < min)
			min = node->rank;
		node = node->next;
	}
	return (min);
}

void	extract_min_to_b(t_state *state)
{
	int	min;

	min = find_stack_min(state->a);
	while (state->a->head->rank != min)
	{
		if (state->a->head->rank != min && state->a->head->next->rank != min)
			do_op(state, RRA);
		else
			do_op(state, RA);
	}
	do_op(state, PB);
}
