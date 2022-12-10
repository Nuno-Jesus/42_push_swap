/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 00:58:22 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/12/10 04:42:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rotate(t_stack *stack, char *op)
{
	int	top;
	
	if (stack->size < 2)
		return ;
	top = stack->array[stack->size - 1];
	ft_memmove(stack->array + 1, stack->array, (stack->size - 1) * sizeof(int));
	stack->array[0] = top;
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
	int	bottom;

	if (stack->size < 2)
		return ;
	bottom = stack->array[0];
	ft_memmove(stack->array, stack->array + 1, (stack->size - 1) * sizeof(int));
	stack->array[stack->size - 1] = bottom;
	if (op)
		ft_putendl_fd(op, STDOUT_FILENO);
}

void	rrr(t_state *state)
{
	reverse(state->a, NULL);
	reverse(state->b, NULL);
	ft_putendl_fd("rrr", STDOUT_FILENO);
}