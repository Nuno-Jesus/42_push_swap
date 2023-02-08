/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:34:24 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/08 15:00:30 by ncarvalh         ###   ########.fr       */
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

t_node	*get_next_min(t_stack *a, long prev_min)
{
	size_t	i;
	long	curr_min;
	t_node	*ret;
	t_node	*aux;
	
	i = -1;
	aux = a->head;
	curr_min = (long)LONG_MAX;
	while (++i < a->size)
	{
		if (aux->val < curr_min && aux->rank == 0)
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
	prev_min = (long)LONG_MIN;
	while (++i <= a->size)
	{
		min = get_next_min(a, prev_min);
		printf("prev/current = %ld/%d -> rank %zu\n", prev_min, min->val, i);
		min->rank = i;
		prev_min = min->val;
	}
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