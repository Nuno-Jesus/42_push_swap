/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 04:55:23 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/12/08 01:56:18 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/stack.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	size_t size = atoi(argv[1]);
	
	t_stack *stack = ft_stknew(size);

	for(size_t i = 0; i < size; i++)
	{
		ft_stkpush(stack, i + 1);
		printf("\n\tSIZE: %ld\n\n", i);
		ft_stkprint(stack);	
	}

	ft_stkpop(stack);
	printf("\n\t===== TESTING POP =====\n\n");
	ft_stkprint(stack);	
	
	//printf("\n\t===== TESTING PUSH A  =====\n\n");
	
	ft_stkdel(&stack);
}