/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 00:58:22 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/11 18:41:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rx(t_stack *stack, char *op)
{
	if (!stack->head)
		return ;
	stack->head = stack->head->next;
	if (op)
		ft_putendl_fd(op, STDOUT_FILENO);
}

void	rr(t_state *state)
{
	rx(state->a, NULL);
	rx(state->b, NULL);
	ft_putendl_fd("rr", STDOUT_FILENO);
}

void 	rrx(t_stack *stack, char *op)
{
	if (!stack->head)
		return ;
	stack->head = stack->head->prev;
	if (op)
		ft_putendl_fd(op, STDOUT_FILENO);
}

void	rrr(t_state *state)
{
	rrx(state->a, NULL);
	rrx(state->b, NULL);
	ft_putendl_fd("rrr", STDOUT_FILENO);
}
