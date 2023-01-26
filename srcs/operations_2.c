/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 00:58:22 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/26 17:49:19 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, char *op)
{
	if (!stack->head)
		return ;
	stack->head = stack->head->next;
	if (op)
		ft_putendl_fd(op, STDOUT_FILENO);
}

void	rr(t_state *state)
{
	rotate(state->a, NULL);
	rotate(state->b, NULL);
	ft_putendl_fd("rr", STDOUT_FILENO);
}

/* 
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
 */