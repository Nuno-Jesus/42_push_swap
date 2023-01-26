/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:40:23 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/26 17:53:42 by ncarvalh         ###   ########.fr       */
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

t_stack	*new_stack(size_t capacity);

void	stack_push(t_stack *stack, t_node *val);

t_node*	stack_pop(t_stack *stack);

void	destroy_stack(t_stack **stack);

void	print_stack(t_stack *stack);

//!-------------------------------------------------

void	do_op(t_state *state, t_operation op);

void	swap(t_stack *stack, char *op);

void	ss(t_state *state);

void	push(t_stack *src, t_stack *dest, char *op);

void	rotate(t_stack *stack, char *op);

void	rr(t_state *state);

void 	reverse(t_stack *stack, char *op);

void	rrr(t_state *state);

//!-------------------------------------------------

t_node	*new_node(int val);

void	destroy_node(t_node **node);

#endif