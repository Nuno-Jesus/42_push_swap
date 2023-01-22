/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:46:23 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/22 20:09:12 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack(size_t capacity)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->capacity = capacity;
	return (stack);
}

void	stack_push(t_stack *stack, int val)
{
	t_node	*node;

	node = new_node(val);
	if (!node)
		return ;
	if (!stack->head)
	{
		stack->head = node;		//Stack head -> node
		stack->head->next = node;				//Replace stack head		
		stack->head->prev = node;				//Replace stack head		
		stack->size++;
		return ;
	}
	node->next = stack->head;		//Node -> stack head
	stack->head->prev->next = node;	//Last element -> node
	node->prev = stack->head->prev;	//Node -> Last element
	stack->head->prev = node;		//Stack head -> node
	stack->head = node;				//Replace stack head
	stack->size++;
}

/* 
int	stack_pop(t_stack *stack)
{

}

void	stack_delete(t_stack **stack)
{
	
}

int	stack_top(t_stack *stack)
{

}
*/

void	stack_print(t_stack *stack)
{
	t_node *aux;

	aux = stack->head;
	for (size_t i = 0; i < stack->size; i++, aux = aux->next)
		printf("%d->", aux->val);
	printf("NULL\n");

} 
