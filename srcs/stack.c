/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:46:23 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/12/08 00:00:31 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

t_stack	*ft_stknew(size_t capacity)
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

void	ft_stkpush(t_stack *stack, int n)
{
	stack->array[stack->size++] = n;
}

int	ft_stkpop(t_stack *stack)
{
	return (stack->array[stack->size--]);
}

void	ft_stkdel(t_stack **stack)
{
	free((*stack)->array);
	free(*stack);
	*stack = NULL;
}

void	ft_stkprint(t_stack *stack)
{
	for(size_t i = 0; i < stack->size; i++)
		printf("%d\n", stack->array[i]);
}
