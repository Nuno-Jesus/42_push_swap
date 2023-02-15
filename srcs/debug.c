/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:34:15 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/15 15:03:40 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_bits(unsigned char n)
{
	unsigned long	i;

	i = 1L << 31;
	while (i > 0)
	{
		if (n & i)
			ft_putchar_fd('1', 1);
		else
			ft_putchar_fd('0', 1);
		i >>= 1;
	}
}

void	print_stack(t_stack *stack, char *name)
{
	int		i;
	t_node	*aux;

	i = -1;
	aux = stack->head;
	ft_putstr_fd(name, STDOUT_FILENO);
	while (++i < stack->size)
	{
		print_bits(aux->rank);
		ft_putstr_fd(" -> [Rank ", STDOUT_FILENO);
		ft_putnbr_fd(aux->rank, STDOUT_FILENO);
		ft_putendl_fd("]\n", STDOUT_FILENO);
		aux = aux->next;
	}
}

void	print_state(t_state *state)
{
	print_stack(state->a, "A");
	print_stack(state->b, "B");
}
