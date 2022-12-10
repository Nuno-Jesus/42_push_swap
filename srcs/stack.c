/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:46:23 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/12/10 06:42:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

t_stack	*stack_new(size_t capacity)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->capacity = capacity;
	stack->array = malloc(capacity * sizeof(int));
	if (!stack->array)
	{
		free(stack);
		return (NULL);
	}	
	return (stack);
}

void	stack_push(t_stack *stack, int n)
{
	stack->array[stack->size++] = n;
}

int	stack_pop(t_stack *stack)
{
	return (stack->array[(stack->size--) - 1]);
}

void	stack_delete(t_stack **stack)
{
	free((*stack)->array);
	free(*stack);
	*stack = NULL;
}

int	stack_top(t_stack *stack)
{
	return (stack->array[stack->size - 1]);
}

void	stack_print(t_stack *stack)
{
	for(size_t i = stack->size - 1; i < stack->size; i--)
		printf("%d\n", stack->array[i]);
}
