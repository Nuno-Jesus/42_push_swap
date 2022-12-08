/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 00:58:22 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/12/08 01:53:07 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rotate(t_stack *stack, char *op)
{
	if (stack->size < 2)
		return ;
	push(stack, stack, NULL);
	if (op)
		ft_putendl_fd(op, STDOUT_FILENO);
}

void	rr(t_state *state)
{
	rotate(state->a, NULL);
	rotate(state->b, NULL);
	ft_putendl_fd("rr", STDOUT_FILENO);
}

void 	reverse(t_stack *stack, char *op)
{
	size_t	i;

	if (stack->size < 2)
		return ;
	i = 0;
	while (i < stack->size)
		push(stack, stack, NULL);
	if (op)
		ft_putendl_fd(op, STDOUT_FILENO);
}

void	rrr(t_state *state)
{
	reverse(state->a, NULL);
	reverse(state->b, NULL);
	ft_putendl_fd("rrr", STDOUT_FILENO);
}