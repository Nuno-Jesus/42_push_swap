/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 04:09:41 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/12/08 02:03:41 by ncarvalh         ###   ########.fr       */
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

typedef struct s_state
{
	t_stack *a;
	t_stack *b;
}t_state;

//! GENERIC STACK FUNCTIONS

t_stack	*stack_new(size_t capacity);

void	stack_push(t_stack *stack, int n);

int		stack_pop(t_stack *stack);

void	stack_delete(t_stack **stack);

void	stack_print(t_stack *stack);

#endif