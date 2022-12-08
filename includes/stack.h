/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 04:09:41 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/12/08 00:02:30 by ncarvalh         ###   ########.fr       */
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

# include "../libft/libft.h"

typedef struct s_stack
{
	size_t	size;
	size_t	capacity;
	int		*array;
}t_stack;

//! GENERIC STACK FUNCTIONS

t_stack	*ft_stknew(size_t capacity);

void	ft_stkpush(t_stack *stack, int n);

int		ft_stkpop(t_stack *stack);

void	ft_stkdel(t_stack **stack);

void	ft_stkprint(t_stack *stack);


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