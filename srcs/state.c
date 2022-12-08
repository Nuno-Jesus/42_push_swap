/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 01:58:55 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/12/08 02:11:23 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_h

#include "../includes/stack.h"

t_state	*state_new(t_stack *a, t_stack *b)
{
	t_state	*state;
	
	state = (t_state *)malloc(sizeof(t_state));
	if (!state)
		return (NULL);
	state->a = a;
	state->b = b;
	return (state);
}

void	state_delete(t_state *state)
{
	stack_delete(&state->a);
	stack_delete(&state->b);
	free(state);
	state = NULL;
}

#endif