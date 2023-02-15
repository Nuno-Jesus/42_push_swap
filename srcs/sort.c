/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:34:24 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/15 14:22:46 by ncarvalh         ###   ########.fr       */
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

void	print_state(t_state *state)
{
	print_stack(state->a, "A");
	print_stack(state->b, "B");
}

void	small_sort(t_state *state)
{
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
		#ifdef DEBUG
			printf("Found min: %d\n", min);
			printf("Current node: %d\n", node->rank);
		#endif
		min = MIN(min, node->rank);
		node = node->next;
	}
	return (min);
}

void	extract_min_to_b(t_state *state)
{
	int		min;
	
	min = find_stack_min(state->a);
	#ifdef DEBUG
		printf("Stack min: %d\n", min);
	#endif
	while (state->a->head->rank != min)
	{
		if (state->a->head->rank != min && state->a->head->next->rank != min)
			do_op(state, RRA);
		else
			do_op(state, RA);
	}
	do_op(state, PB);
}

void	medium_sort(t_state *state)
{
	while (state->a->size > SMALL_SORT_THRESHOLD)
	{
		extract_min_to_b(state);
		#ifdef DEBUG
			print_state(state);
		#endif
	}
	small_sort(state);
	while (state->b->size)
		do_op(state, PA);
}

void	big_sort(t_state *state)
{
	int k;
	int bits;

	k = -1;
	bits = count_bits(state->a->size);
	#ifdef DEBUG
		printf("Count bits: %d\n", bits);
	#endif
	
	int size = state->a->size;
		
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
