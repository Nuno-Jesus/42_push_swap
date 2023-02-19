/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:34:24 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/19 18:17:15 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	int		i;
	t_node	*aux;

	i = -1;
	aux = stack->head;
	while (++i < stack->size - 1)
	{
		if (aux->val > aux->next->val)
			return (false);
		aux = aux->next;
	}
	return (true);
}	

void	apply_rankings(t_stack *a)
{
	int		i;
	t_node	*min;

	i = -1;
	while (++i < a->size)
	{
		min = find_next_unranked_min(a);
		min->rank = i;
	}
}

void	small_sort_algorithm(t_state *state)
{
	if (state->a->head->next->val > state->a->head->val
		&& state->a->head->next->val > state->a->head->prev->val)
		do_op(state, RRA);
	if (is_sorted(state->a))
		return ;
	if (state->a->head->val > state->a->head->prev->val)
		do_op(state, RA);
	if (is_sorted(state->a))
		return ;
	if (state->a->head->val > state->a->head->next->val)
		do_op(state, SA);
	if (is_sorted(state->a))
		return ;
}

void	medium_sort_algorithm(t_state *state)
{
	if (is_sorted(state->a))
		return ;
	while (state->a->size > SMALL_SORT_THRESHOLD)
		extract_min_to_b(state);
	small_sort_algorithm(state);
	while (state->b->size)
		do_op(state, PA);
}

void	big_sort_algorithm(t_state *state)
{
	int	k;
	int	i;
	int	size;
	int	bits;

	k = -1;
	size = state->a->size;
	bits = count_bits(state->a->size);
	while (++k < bits && !is_sorted(state->a))
	{
		i = -1;
		while (++i < size)
		{
			if (!(state->a->head->rank & (1 << k)))
				do_op(state, PB);
			else
				do_op(state, RA);
		}
		while (state->b->size)
			do_op(state, PA);
	}
}
