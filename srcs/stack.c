/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:46:23 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/26 17:09:59 by ncarvalh         ###   ########.fr       */
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

void	push(t_stack *stack, int val)
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

t_node*	pop(t_stack *stack)
{
	t_node	*aux;
	
	if (!stack)
		return (NULL);
	else if (!stack->head)
		return (NULL);
	aux = stack->head;
	if (stack->size == 1)
		stack->head = NULL;
	else 
	{
		stack->head->prev->next = stack->head->next; //Put the last element pointing to the one after the head
		stack->head->next->prev = stack->head->prev; //Put the next head pointing to the last element
		stack->head = stack->head->next;			 //Promote the next head
	}
	stack->size--;
	return (aux);
}
/* 


int	stack_top(t_stack *stack)
{

}
*/

void	print_stack(t_stack *stack)
{
	t_node *aux;

	aux = stack->head;
	printf("Head -> Bottom\n");
	for (size_t i = 0; i < stack->size; i++, aux = aux->next)
		printf("%d->", aux->val);
	puts("");
	
	aux = stack->head->prev;
	printf("Bottom -> Head\n");
	for (size_t i = 0; i < stack->size; i++, aux = aux->prev)
		printf("%d<-", aux->val);
	puts("");

} 

void	destroy_stack(t_stack **stack)
{
	t_node	*aux;
	
	aux = (*stack)->head;
	if (!(*stack))
		return ;
	if ((*stack)->head)
	{
		(*stack)->head->prev->next = NULL;
		while (aux)
		{
			(*stack)->head = (*stack)->head->next;
			destroy_node(&aux);
			aux = (*stack)->head;
		}
	}
	free(*stack);
	*stack = NULL;			
}