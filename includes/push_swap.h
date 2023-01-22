/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:40:23 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/22 16:53:07 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "macros.h"
# include "libft.h"

typedef struct	s_node
{
	int				val;
	struct s_node	*next;
	struct s_node	*prev;	
}				t_node;

typedef struct	s_stack
{
	size_t	size;
	size_t	capacity;
	t_node 	*head;
}				t_stack;

typedef struct	s_state
{
	t_stack	*a;
	t_stack	*b;
}				t_state;

//!-------------------------------------------------

t_stack	*stack_new(size_t capacity);

void	stack_push(t_stack *stack, int n);

int		stack_pop(t_stack *stack);

void	stack_delete(t_stack **stack);

int		stack_top(t_stack *stack);

void	stack_print(t_stack *stack);

//!-------------------------------------------------
void	swap(t_stack *stack, char *op);

void	ss(t_state *state);

void	push(t_stack *dest, t_stack *src, char *op);

void	rotate(t_stack *stack, char *op);

void	rr(t_state *state);

void 	reverse(t_stack *stack, char *op);

void	rrr(t_state *state);

//!-------------------------------------------------

t_node	*new_node(int val);

void	destroy_node(t_node **node);

#endif