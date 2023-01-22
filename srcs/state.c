/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 01:58:55 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/22 16:27:47 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



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

