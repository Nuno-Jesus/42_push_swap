/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 04:55:23 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/12/07 23:58:01 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/stack.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	
	t_stack *stack = ft_stknew(5);

	for(int i = 0; i < 5; i++)
		ft_stkpush(stack, i);

	ft_stkprint(stack);
	ft_stkdel(&stack);
}