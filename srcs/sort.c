/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:34:24 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/27 18:56:30 by ncarvalh         ###   ########.fr       */
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

void	transfer_local_chunk(t_state *state)
{
	int	min;

	min = state->a->head->local_min;
	while (min == state->a->head->local_min && state->a->size)
		do_op(state, PB);		
}

void	sort(t_state *state)
{
	calculate_local_minima(state->a);
	print_stack(state->a, "A");
	transfer_local_chunk(state);
	print_stack(state->a, "A");
	print_stack(state->b, "B");
}



#endif