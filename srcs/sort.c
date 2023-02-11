/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:34:24 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/11 22:27:17 by marvin           ###   ########.fr       */
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
		min->rank = ABS(i);
		min->has_negative_rank = (i++ < 0);
	}
}

t_operation	find_next_negative(t_stack *a)
{
	int		i;
	t_node	*node;

	node = a->head;
	i = -1;
	while (++i < a->size)
	{
		if (node->has_negative_rank)
			break;
		node = node->next;
	}
	if (i < a->size / 2)
		return (RA);
	else
		return (RRA);
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
	// printf("Negative ranks: %d\n", neg);
	while (neg--)
	{
		// print_stack(state->a, "A");
		while (!state->a->head->has_negative_rank)
			do_op(state, find_next_negative(state->a));
		do_op(state, PB);
	}	
}

int	count_zero_bits(t_stack *a, int k)
{
	int		i;
	int		count;
	t_node	*node;

	i = -1;
	count = 0;
	node = a->head;
	while (++i < a->size)
	{
		if (!(node->rank & BIT(k)))
			count++;
		node = node->next;
	}
	return (count);
}

t_operation	find_next_zero_bit(t_stack *a, int k)
{
	int		i;
	t_node	*node;

	node = a->head;
	i = -1;
	while (++i < a->size)
	{
		if (!(node->rank & BIT(k)))
			break;
		node = node->next;
	}
	if (i < a->size / 2)
		return (RA);
	else
		return (RRA);
}

void	set_first(t_stack *a, int k)
{
	int		i;
	t_node	*node;

	i = -1;
	node = a->head;
	while (++i < a->size)
	{
		if (node->rank & BIT(k))
		{
			node->was_first = true;
			return;
		}
		node = node->next;
	}
}

t_operation	find_old_first(t_stack *a)
{
	int		i;
	t_node	*node;

	node = a->head;
	i = -1;
	while (++i < a->size)
	{
		if (node->was_first)
			break;
		node = node->next;
	}
	if (i < a->size / 2)
		return (RA);
	else
		return (RRA);
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
	while (++k < bits && !is_sorted(state->a))
	{
		int i = 0;
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
		while (state->b->size)
			do_op(state, PA); 
	}
	#ifdef DEBUG
		printf("-------------- FINAL --------------\n");
		print_state(state);
	#endif
}

/* if (state->a->head->next->val > state->a->head->val && 
			state->a->head->next->val > state->a->head->prev->val)
			do_op(state, RRA);
		if (state->a->head->val > state->a->head->prev->val)
			do_op(state, RA);
		if (state->a->head->val > state->a->head->next->val)
			do_op(state, SA);
		if (is_sorted(state->a))
			break; */