/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 00:21:01 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/24 01:56:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* 
void	swap(t_stack *stack, char *op)
{
	int aux;
	
	if(stack->size <= 1)
		return ;
	aux = stack->array[stack->size - 1];
	stack->array[stack->size - 1] = stack->array[stack->size - 2];
	stack->array[stack->size - 2] = aux;
	if (op)
		ft_putendl_fd(op, STDOUT_FILENO);
}

void	ss(t_state *state)
{
	swap(state->a, NULL);	
	swap(state->b, NULL);
	ft_putendl_fd("ss", STDOUT_FILENO);
}

void	push(t_stack *dest, t_stack *src, char *op)
{
	if (src->size > 0)
	{
		push(dest, stack_pop(src));
		ft_putendl_fd(op, STDOUT_FILENO);
	}
}
 */