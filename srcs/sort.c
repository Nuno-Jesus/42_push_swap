/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:34:24 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/27 19:56:06 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "push_swap.h"

void	calculate_local_minima(t_stack *a)
{
	size_t	i;
	int		min;

	i = 0;
	a->head->local_min = MIN(a->head->val, a->head->next->val);
	min = a->head->local_min;
	while (i < a->size)
	{
		min = MIN(min, a->head->val);
		a->head->local_min = min;
		a->head = a->head->next;
		i++;
	}
}

void	transfer_local_chunk_to_b(t_state *state)
{
	int	min;

	min = state->a->head->local_min;
	while (min == state->a->head->local_min && state->a->size)
		do_op(state, PB);		
}

size_t	find_absolute_maximum(t_stack *b)
{
	size_t	i;
	int		max;
	int		index;

	i = 0;
	index = 0;
	max = INT_MIN;
	while (i < b->size)
	{
		if (b->head->val > max)
		{
			max = b->head->val;
			index = i;
		}
		b->head = b->head->next;
		i++;
	}
	// printf("Absolute maximum: %d (%d)\n", max, index);
	return (index);
}

void	transfer_local_chunk_to_a(t_state *state)
{
	size_t	i;
	size_t	index;

	while (state->b->size)
	{
		i = -1;
		index = find_absolute_maximum(state->b);		
		if (index >= state->b->size / 2 && index != 0)
			while (++i < state->b->size - index)
				do_op(state, RRB);
		else if (index < state->b->size / 2 && index != 0)
			while (++i < index)
				do_op(state, RB);
		do_op(state, PA);
	}
}

void rotate_local_chunk(t_state *state)
{
	int min;

	min = state->a->head->local_min;
	
	while (state->a->head->local_min == min)
		do_op(state, RA);
}

void	sort(t_state *state)
{
	size_t i = -1;
	while (++i < 3)
	{
		calculate_local_minima(state->a);
		print_stack(state->a, "A");
		transfer_local_chunk_to_b(state);
		print_stack(state->a, "A");
		print_stack(state->b, "B");
		transfer_local_chunk_to_a(state);
		print_stack(state->a, "A");
		print_stack(state->b, "B");
		rotate_local_chunk(state);
		print_stack(state->a, "A");		
	}
}



#endif