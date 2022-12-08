/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:46:23 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/12/08 02:03:33 by ncarvalh         ###   ########.fr       */
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
	ft_memmove(stack->array + 1, stack->array, (stack->size++) * sizeof(int));	
	stack->array[0] = n;
}

int	stack_pop(t_stack *stack)
{
	int	pop;
	
	pop = stack->array[0];
	ft_memmove(stack->array, stack->array + 1, (--stack->size) * sizeof(int));
	return (pop);
}

void	stack_delete(t_stack **stack)
{
	free((*stack)->array);
	free(*stack);
	*stack = NULL;
}

int		ft_stktop(t_stack *stack)
{
	return (stack->array[stack->size - 1]);
}

void	stack_print(t_stack *stack)
{
	for(size_t i = 0; i < stack->size; i++)
		printf("%d\n", stack->array[i]);
}
