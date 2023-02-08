/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:34:24 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/08 15:21:41 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

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

t_node	*get_next_min(t_stack *a)
{
	size_t	i;
	t_node	*ret;
	t_node	*aux;
	
	i = -1;
	aux = a->head;
	ret = NULL;
	while (++i < a->size)
	{
		if (aux->rank == 0 && (!ret || aux->val < ret->val))
			ret = aux;			
		aux = aux->next;
	}
	return (ret);
}

void	apply_rankings(t_stack *a)
{
	size_t	i;
	long	prev_min;
	t_node	*min;

	i = 0;
	prev_min = LONG_MIN;
	while (++i <= a->size)
	{
		min = get_next_min(a);
		printf("prev/current = %ld/%d -> rank %zu\n", prev_min, min->val, i);
		min->rank = i;
		prev_min = min->val;
	}
}

void	sort(t_state *state)
{
	int bits;
	size_t	i;
	int k;
	// size_t size;

	k = -1;
	// size = state->a->size;
	bits = count_bits(find_absolute_maximum(state->a));
	apply_rankings(state->a);
	print_stack(state->a, "A");
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
		// printf("Numbers with (1 << %d): %d\n", bits, n);
		while (i < state->a->size)
		{
			// printf("Current head: %d\n", state->a->head->val);
			if (!(state->a->head->val & BIT(k)))
			{
				do_op(state, PB);
			}
			else
				do_op(state, RA);			
			i++;
		}
		
		while (state->b->size)
			do_op(state, PA);
		// print_stack(state->a, "A");
	}
}