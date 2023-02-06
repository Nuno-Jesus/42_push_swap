/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:34:24 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/06 17:26:19 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"
/* 
void	calculate_local_minima(t_state *state)
{
	size_t	i;
	int		min;

	i = 0;
	state->a->head->local_min = MIN(state->a->head->val, state->a->head->next->val);
	min = state->a->head->local_min;
	state->local_minima = 1;
	while (i < state->a->size)
	{
		if (state->a->head->val < min)
		{
			min = state->a->head->val;
			state->local_minima++;
		}
		state->a->head->local_min = min;
		state->a->head = state->a->head->next;
		i++;
	}
}

void	transfer_local_chunk_to_b(t_state *state)
{
	int	min;

	min = state->a->head->local_min;
	while (state->a->size)
	{
		if (min != state->a->head->local_min)
			break;
		do_op(state, PB);		
	}
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
	size_t i;

	i = -1;
	min = state->a->head->local_min;
	while (state->a->head->local_min == min && ++i < state->a->size)
		do_op(state, RA);
}

void	sort(t_state *state)
{
	while (1)
	{
		while (state->a->head->next->val > state->a->head->val && 
			state->a->head->next->val > state->a->head->prev->val)
			do_op(state, RRA);
		if (is_sorted(state->a))
			break;
		while (state->a->head->val > state->a->head->prev->val)
			do_op(state, RA);
		if (is_sorted(state->a))
			break;
		while (state->a->head->val > state->a->head->next->val)
			do_op(state, SA);
		if (is_sorted(state->a))
			break;
		calculate_local_minima(state);
		// print_stack(state->a, "A");
		transfer_local_chunk_to_b(state);
		// print_stack(state->a, "A");
		// print_stack(state->b, "B");
		transfer_local_chunk_to_a(state);
		if (is_sorted(state->a))
			break;
		// print_stack(state->a, "A");
		// print_stack(state->b, "B");
		rotate_local_chunk(state);
		// print_stack(state->a, "A");		
	}
}
 */

int	find_absolute_maximum(t_stack *a)
{
	size_t	i;
	int		max;

	i = -1;
	max = INT_MIN;
	while (++i < a->size)
	{
		max = MAX(max, a->head->val);
		a->head = a->head->next;
	}
	// printf("Absolute maximum: %d (%d)\n", max, index);
	return (max);
}

int	count_bits(int n)
{
	int bits;

	bits = 0;	
	while (n)
	{
		n >>= 1;
		bits++;
	}
	return (bits);
}

int	count_numbers_with_0_bit(t_stack *a, int n)
{
	int		ret;
	size_t	i;

	i = -1;
	ret = 0;
	while (++i < a->size)
	{
		if (!(a->head->val & BIT(n)))
			ret++;		
		a->head = a->head->next;
	}
	return (ret);
}

void	sort(t_state *state)
{
	int bits;
	int	i;
	int n;
	int k;
	size_t size;

	k = -1;
	size = state->a->size;
	bits = count_bits(find_absolute_maximum(state->a));
	// printf("Count bits: %d\n", bits);
	while (++k < bits)
	{
		/* if (state->a->head->next->val > state->a->head->val && 
			state->a->head->next->val > state->a->head->prev->val)
			do_op(state, RRA);
		if (state->a->head->val > state->a->head->prev->val)
			do_op(state, RA);
		if (state->a->head->val > state->a->head->next->val)
			do_op(state, SA);
		if (is_sorted(state->a))
			break; */
		i = 0;
		n = count_numbers_with_0_bit(state->a, k);
		if (!n)
			continue;
		// printf("Numbers with (1 << %d): %d\n", bits, n);
		while (i < n)
		{
			// printf("Current head: %d\n", state->a->head->val);
			if (!(state->a->head->val & BIT(k)))
			{
				do_op(state, PB);
				i++;
			}
			else
				do_op(state, RA);			
		}
		
		while (state->b->size)
			do_op(state, PA);
		// print_stack(state->a, "A");
	}
}