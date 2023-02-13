/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:34:24 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/13 15:59:05 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	count_bits(int n)
{
	int bits;

	bits = 0;	
	while (n >> bits)
		bits++;
	return (bits);
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
		if (aux->rank == -1 && (!ret || aux->val < ret->val))
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
	while (i < a->size)
	{
		min = get_next_min(a);
		min->rank = i++;
	}
}

void	move_negatives(t_state *state)
{
	int	i;
	int	neg;
	
	i = -1;
	neg = 0;
	while (++i < state->a->size)
	{
		if (state->a->head->has_negative_rank)
			neg++;
		state->a->head = state->a->head->next;
	}
	while (neg--)
	{
		while (!state->a->head->has_negative_rank)
			do_op(state, find_next_negative(state->a));
		do_op(state, PB);
	}
}

void	print_state(t_state *state)
{
	print_stack(state->a, "A");
	print_stack(state->b, "B");
}

void	sort(t_state *state)
{
	int k;
	int bits;

	k = -1;
	bits = count_bits(state->a->size);
	#ifdef DEBUG
		printf("Count bits: %d\n", bits);
	#endif
	
	int size = state->a->size;
	
	apply_rankings(state->a);
	// move_negatives(state);
	if (state->a->head->next->val > state->a->head->val && 
		state->a->head->next->val > state->a->head->prev->val)
		do_op(state, RRA);
	if (is_sorted(state->a))
		return;
	if (state->a->head->val > state->a->head->prev->val)
		do_op(state, RA);
	if (is_sorted(state->a))
		return;
	if (state->a->head->val > state->a->head->next->val)
		do_op(state, SA);
	if (is_sorted(state->a))
		return;
	while (++k < bits && !is_sorted(state->a))
	{
		int i = -1;
		while (++i < size)
		{
			if (!(state->a->head->rank & BIT(k)))
				do_op(state, PB);
			else
				do_op(state, RA);	
		}
		while (state->b->size)
			do_op(state, PA); 
	}
	#ifdef DEBUG
		printf("-------------- FINAL --------------\n");
		print_state(state);
	#endif
}

/*  */