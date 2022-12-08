/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 04:55:23 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/12/08 04:12:10 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"
#include "../includes/state.h"
#include "../includes/operations.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	size_t size = atoi(argv[1]);
	
	t_stack *a = stack_new(size);
	t_stack *b = stack_new(size);
	t_state *state = state_new(a, b);

	for(size_t i = 0; i < size; i++)
	{
		stack_push(a, size - i);
		printf("\n\tSIZE: %ld\n\n", i);
		stack_print(a);	
	}

/* 	stack_pop(a);
	printf("\n\t===== TESTING POP =====\n\n");
	stack_print(a);	 */
	
	/* printf("\n\t===== TESTING PUSH A  =====\n\n");
	
	printf("\n\t===== A =====\n\n");
	stack_print(a);	
	printf("\n\t===== B =====\n\n");
	stack_print(b);	
	
	push(state->b, state->a, "pb");
	
	printf("\n\t===== A =====\n\n");
	stack_print(a);	
	printf("\n\t===== B =====\n\n");
	stack_print(b);	 */
	
	/* printf("\n\t===== TESTING SWAP A  =====\n\n");
	
	printf("\n\t===== A =====\n\n");
	stack_print(a);	
	
	swap(state->a, "sa");
	
	printf("\n\t===== A =====\n\n");
	stack_print(a);	
	
	state_delete(state);
	 */
	 
/* 	printf("\n\t===== TESTING ROTATE A  =====\n\n");
	
	printf("\n\t===== A =====\n\n");
	stack_print(a);	
	
	rotate(state->a, "ra");
	
	printf("\n\t===== A =====\n\n");
	stack_print(a);	 */
	
	printf("\n\t===== TESTING REVERSE A  =====\n\n");
	
	printf("\n\t===== A =====\n\n");
	stack_print(a);	
	
	reverse(state->a, "rra");
	
	printf("\n\t===== A =====\n\n");
	stack_print(a);	
	
	state_delete(state);
}