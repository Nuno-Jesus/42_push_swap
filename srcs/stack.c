/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:46:23 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/11 20:26:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack(int capacity)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->capacity = capacity;
	return (stack);
}

void	stack_push(t_stack *stack, t_node *node)
{
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

t_node*	stack_pop(t_stack *stack)
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

void	print_bits(unsigned char n)
{
	unsigned long i = 1L << 32;
	
	while (i >>= 1)
		(n & i) ? printf("1") : printf("0");
}

void	print_stack(t_stack *stack, char *name)
{
	if (!stack->size)
		return ;
	t_node *aux;
	
	aux = stack->head;
	printf("(%s) Head -> Bottom (Size : %d)\n", name, stack->size);
	for (int i = 0; i < stack->size; i++, aux = aux->next)
	{
		print_bits(aux->rank);
		printf(" -> [Rank %5d][%d]%s\n", aux->rank, aux->has_negative_rank, aux->was_first ? "[first]" : "");
	}
	puts("");
	/* 
	aux = stack->head->prev;
	printf("Bottom -> Head\n");
	for (size_t i = 0; i < stack->size; i++, aux = aux->prev)
		printf("[%d]\n", aux->val);
	puts(""); */
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