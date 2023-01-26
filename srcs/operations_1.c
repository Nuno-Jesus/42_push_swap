/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 00:21:01 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/26 17:26:03 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_op(t_state *state, t_operation op)
{
	if (op == SA)
		swap(state->a, "sa");
	else if (op == SB)
		swap(state->b, "sb");
	else if (op == SS)
		ss(state);
	/* else if (op == RA)
		rotate(state->a, "ra");
	else if (op == RB)
		rotate(state->b, "rb");
	else if (op == RR)
		rr(state);
	else if (op == RRA)
		rev_rotate(state->a, "rra");
	else if (op == RRB)
		rev_rotate(state->b, "rrb");
	else if (op == RRR)
		rrr(state); */
}
void	swap(t_stack *stack, char *op)
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
	swap(state->a, NULL);	
	swap(state->b, NULL);
	ft_putendl_fd("ss", STDOUT_FILENO);
}

/* 

void	push(t_stack *dest, t_stack *src, char *op)
{
	if (src->size > 0)
	{
		push(dest, pop(src));
		ft_putendl_fd(op, STDOUT_FILENO);
	}
}
 */