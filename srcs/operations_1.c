/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 00:21:01 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/11 18:41:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_op(t_state *state, t_operation op)
{
	if (op == SA)
		sx(state->a, "sa");
	else if (op == SB)
		sx(state->b, "sb");
	else if (op == SS)
		ss(state);
	else if (op == PA)
		px(state->b, state->a, "pa");
	else if (op == PB)
		px(state->a, state->b, "pb");
	else if (op == RA)
		rx(state->a, "ra");
	else if (op == RB)
		rx(state->b, "rb");
	else if (op == RR)
		rr(state);
	else if (op == RRA)
		rrx(state->a, "rra");
	else if (op == RRB)
		rrx(state->b, "rrb");
	else if (op == RRR)
		rrr(state); 
}

void	sx(t_stack *stack, char *op)
{
	int	aux;
	
	if (stack->size < 2)
		return ;
	aux = stack->head->val;
	stack->head->val = stack->head->next->val;
	stack->head->next->val = aux;
	if (op)
		ft_putendl_fd(op, STDOUT_FILENO);
}

void	ss(t_state *state)
{
	sx(state->a, NULL);	
	sx(state->b, NULL);
	ft_putendl_fd("ss", STDOUT_FILENO);
}

void	px(t_stack *src, t_stack *dest, char *op)
{
	if (!src->size)
		return ;	
	stack_push(dest, stack_pop(src));
	ft_putendl_fd(op, STDOUT_FILENO);
}
