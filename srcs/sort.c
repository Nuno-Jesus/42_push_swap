/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:34:24 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/11 18:34:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	find_absolute_maximum(t_stack *a)
{
	int	i;
	int		max;

	i = -1;
	max = INT_MIN;
	while (++i < a->size)
	{
		max = MAX(max, a->head->val);
		a->head = a->head->next;
	}
	printf("Absolute maximum: %d\n", max);
	return (max);
}

int	count_bits(int n)
{
	int bits;

	bits = 0;	
	while (n >> bits)
		bits++;
	return (bits);
}

int	count_numbers_with_0_bit(t_stack *a, int n)
{
	int		ret;
	int	i;

	i = -1;
	ret = 0;
	while (++i < a->size)
	{
		if (!(a->head->rank & BIT(n)))
			ret++;		
		a->head = a->head->next;
	}
	return (ret);
}

t_node	*get_next_min(t_stack *a)
{
	int	i;
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
	int	i;
	t_node	*min;

	i = 0;
	while (++i <= a->size)
	{
		min = get_next_min(a);
		min->rank = i;
	}
}

int	find_next_zero(t_stack *a, int n)
{
	int i;

	i = 0;
	while (i < a->size)
	{
		if (!(a->head->rank & BIT(n)))
			return (i);
	}
	return (-1);
}

void	sort(t_state *state)
{
	int bits;
	int i;
	int k;
	int size;

	k = -1;
	size = state->a->size;
	bits = count_bits(state->a->size);
	// printf("Count bits: %d\n", bits);
	apply_rankings(state->a);
	// print_stack(state->a, "A");
	while (++k < bits && !is_sorted(state->a))
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
		i = -1;
		// printf("Numbers with 0 on the  %d position: %d\n", k, n);
		while (++i < size)
		{
			// printf("Current head: %d\n", state->a->head->val);
			if (!(state->a->head->rank & BIT(k)))
			{
				// i++;
				do_op(state, PB);
				// printf("Pushed %d numbers so far.\n", i);
			}
			else
				do_op(state, RA);	
			// print_stack(state->a, "A");		
		}
		
		// print_stack(state->b, "B");
		while (state->b->size)
			do_op(state, PA);
	}
}