/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 04:09:41 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/12/04 04:33:30 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_stack
{
	size_t	capacity;
	size_t	size;
	t_list	*content;
}t_stack;

//! GENERIC STACK FUNCTIONS

t_stack	*ft_stknew(size_t capacity);

int		ft_stkfull(t_stack *stack);

int		ft_stkempty(t_stack *stack);

void	ft_stkpush(t_stack *stack, t_list *node);

t_list	*ft_stkpop(t_stack *stack);

void	ft_stkclear(t_stack *stack);

//! SUBJECT OPERATIONS

void	sa(t_stack *a);

void	sb(t_stack *b);

void	ss(t_stack *a, t_stack *b);

void	pa(t_stack *a);

void	pb(t_stack *b);

void	ra(t_stack *a);

void	rb(t_stack *b);

void	rr(t_stack *a, t_stack *b);

void	rra(t_stack *a);

void	rrb(t_stack *b);

void	rrr(t_stack *a, t_stack *b);


#endif